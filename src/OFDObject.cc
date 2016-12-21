#include "OFDObject.h"
#include "OFDTextObject.h"
#include "utils/logger.h"
#include "utils/xml.h"

using namespace utils;
using namespace ofd;

OFDObject::OFDObject() :
    ID(0), Visible(true), LineWidth(0.353), Alpha(255){
}

OFDObject::~OFDObject(){
}

OFDObjectPtr OFDObjectFactory::CreateObject(Object::Type objType){
    OFDObjectPtr object = nullptr;

    switch ( objType ){
    case Object::Type::TEXT:{
        OFDTextObject *textObject = new OFDTextObject();
        object = std::shared_ptr<OFDObject>(textObject);
        } break;
    case Object::Type::PATH:
        break;
    case Object::Type::IMAGE:
        break;
    case Object::Type::COMPOSITE:
        break;
    default:
        break;
    };

    return object;
}

// Called by OFDPage::ImplCls::generateContentXML()
void OFDObject::GenerateXML(XMLWriter &writer) const{
    writer.StartElement(ObjectLabel);{
        GenerateAttributesXML(writer);
        GenerateElementsXML(writer);
    } writer.EndElement();
}

void OFDObject::GenerateAttributesXML(XMLWriter &writer) const{

    // -------- GraphUnit attributes --------
    // OFD (section 8.5) P50. Page.xsd.

    // -------- <Object ID="">
    // Required
    writer.WriteAttribute("ID", ID);

    // -------- <Object Boundary="">
    // Required.
    writer.WriteAttribute("Boundary", Boundary.to_xmlstring());

    // -------- <Object Name="">
    // Optional
    if ( !Name.empty() ){
        writer.WriteAttribute("Name", Name);
    }

    // -------- <Object Visible="">
    // Optional, default value: true.
    if ( !Visible ){
        writer.WriteAttribute("Visible", "false");
    }

    // TODO
    // -------- <Object CTM="">


    // TODO
    // -------- <Object LineWidth="">
    if ( LineWidth > 0 ){
        writer.WriteAttribute("LineWidth", LineWidth, 3);
    }

    // -------- <Object Alpha="">
    // Optional, default value: 0.
    if ( Alpha > 0 ){
        writer.WriteAttribute("Alpha", std::to_string(Alpha));
    }
}

void OFDObject::GenerateElementsXML(XMLWriter &writer) const{

    // -------- GraphUnit elements --------
    // OFD P50. Page.xsd.

    // TODO
    // -------- <Actions>

    // TODO
    // -------- <Clips>

}

bool OFDObject::FromXML(utils::XMLReader &reader, const std::string &tagName){
    bool ok = true;

    if ( reader.CheckElement(tagName) ){
        ok = FromAttributesXML(reader); 
        if ( ok && reader.EnterChildElement(tagName) ){
            ok = FromElementsXML(reader);

            reader.BackParentElement();
        }
    }

    return ok;
}

// -------- CT_GraphicUnit --------
// OFD (section 8.5) P50.
bool OFDObject::FromAttributesXML(XMLReader &reader){
    bool ok = true;

    // -------- <TextObject ID="">
    // Required.
    reader.ReadAttribute("ID", ID);

    // -------- <Object Boundary="">
    // Required.
    std::string strBoundary;
    reader.ReadAttribute("Boundary", strBoundary);

    std::vector<std::string> tokens = utils::SplitString(strBoundary);
    if ( tokens.size() >= 4 ){
        Boundary.Left = atof(tokens[0].c_str());
        Boundary.Top = atof(tokens[1].c_str());
        Boundary.Width = atof(tokens[2].c_str());
        Boundary.Height = atof(tokens[3].c_str());
        ok = true;
    } else {
        LOG(ERROR) << "Box String tokens size >= 4 failed. boxString:" << strBoundary << " element name: " << reader.GetElementName();
        return false;
    }

    // -------- <Object LineWidth="">
    // Optional
    reader.ReadAttribute("LineWidth", LineWidth);

    // -------- <Object Alpha="">
    // Optional
    uint64_t alpha;
    reader.ReadAttribute("Alpha", alpha);
    Alpha = alpha;

    // -------- <Object Name="">
    // Optional

    // -------- <Visible Name="">
    // Optional

    // -------- <CTM Name="">
    // Optional

    // -------- <DrawParam Name="">
    // Optional

    // -------- <Cap Name="">
    // Optional

    // -------- <Join Name="">
    // Optional

    // -------- <MiterLimit Name="">
    // Optional

    // -------- <DashOffset Name="">
    // Optional

    // -------- <DashPattern Name="">
    // Optional


    return ok;
}

bool OFDObject::FromElementsXML(XMLReader &reader){
    bool ok = true;

    while ( reader.HasElement() ){

        CheckElementsXML(reader);

        reader.NextElement();
    }

    return ok;
}

// -------- CT_GraphicUnit --------
// OFD (section 8.5) P50.
bool OFDObject::CheckElementsXML(XMLReader &reader){
    bool ok = false;

        // -------- <Actions Name="">
        // Optional

        // -------- <Clips Name="">
        // Optional


    return ok;
}

