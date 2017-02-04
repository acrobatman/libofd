#include "Gfx2Ofd.h"
#include "utils/logger.h"

using namespace ofd;

OfdPathPtr GfxPath_to_OfdPath(GfxPath *gfxPath){
    if ( gfxPath == nullptr ) return nullptr;

    OfdPathPtr ofdPath = nullptr;
    int numSubpaths = gfxPath->getNumSubpaths();
    if ( numSubpaths == 0 ) return nullptr;
    ofdPath = std::make_shared<OfdPath>();

    double x, y;
    int j;
    for ( int i = 0 ; i < numSubpaths ; i++){
        GfxSubpath *subpath = gfxPath->getSubpath(i);
        if ( subpath->getNumPoints() > 0 ){
            x = subpath->getX(0);
            y = subpath->getY(0);
            ofdPath->MoveTo(Point(x,y));
            j = 1;
            while ( j < subpath->getNumPoints()) {
                if ( subpath->getCurve(j) ){
                    x = subpath->getX(j+2);
                    y = subpath->getY(j+2);
                    double x0 = subpath->getX(j);
                    double y0 = subpath->getY(j);
                    double x1 = subpath->getX(j+1);
                    double y1 = subpath->getY(j+1);
                    ofdPath->CurveTo(Point(x0, y0), Point(x1, y1), Point(x, y));

                    j += 3;
                } else {
                    x = subpath->getX(j);
                    y = subpath->getY(j);
                    ofdPath->LineTo(Point(x, y));
                    ++j;
                }
            }
            if ( subpath->isClosed() ){
                ofdPath->ClosePath();
            }
        }
    }

    return ofdPath;
}

// -------- GfxFont_to_OFDFont() --------
OFDFontPtr GfxFont_to_OFDFont(GfxFont *gfxFont, XRef *xref){
    OFDFontPtr ofdFont = std::make_shared<OFDFont>();

    // -------- FontID --------
    Ref *ref = gfxFont->getID();
    ofdFont->ID = ref->num;

    // -------- FontFamily --------
    GooString *family = gfxFont->getFamily();
    if ( family != nullptr ){
        ofdFont->FamilyName = std::string(family->getCString());
    }

    // -------- FontName --------
    GooString *name = gfxFont->getName();
    if ( name != nullptr ){
        ofdFont->FontName = std::string(name->getCString());
    }

    // -------- FontType --------
    GfxFontType fontType = gfxFont->getType();
    if ( fontType == fontCIDType2 ){
        ofdFont->FontType = ofd::Font::Type::CIDType2;
    } else if (fontType == fontType1 ){
        ofdFont->FontType = ofd::Font::Type::Type1;
    } else if (fontType == fontType3 ){
        ofdFont->FontType = ofd::Font::Type::Type3;
    } else if (fontType == fontTrueType ){
        ofdFont->FontType = ofd::Font::Type::TrueType;
    } else {
        ofdFont->FontType = ofd::Font::Type::Unknown;
    }

    // -------- FontLoc --------
    GfxFontLoc *fontLoc = gfxFont->locateFont(xref, nullptr);
    if ( fontLoc != nullptr ){
        if ( fontLoc->locType == gfxFontLocEmbedded ){
            ofdFont->FontLoc = ofd::Font::Location::Embedded;
        } else if ( fontLoc->locType == gfxFontLocExternal ){
            ofdFont->FontLoc = ofd::Font::Location::External;
            ofdFont->FontFile = std::string(fontLoc->path->getCString());
        } else if ( fontLoc->locType == gfxFontLocResident ){
            ofdFont->FontLoc = ofd::Font::Location::Resident;
        } else {
            ofdFont->FontLoc = ofd::Font::Location::Unknown;
        }
        delete fontLoc;
        fontLoc = nullptr;
    } else {
        LOG(WARNING) << "fontLoc == nullptr.";
    }

    // -------- FontData --------
    //int fontDataSize = 0;
    //char *fontData = gfxFont->readEmbFontFile(xref, &fontDataSize);

    // FIXME
    //ofdFont->m_fontData = fontData;
    //ofdFont->m_fontDataSize = fontDataSize;
    //ofdFont->CreateFromData(fontData, fontDataSize);

    //// FIXME
    //// Export running font data.
    //{
        //std::string fontfile = std::string("font_running_") + std::to_string(ofdFont->ID) + ".ttf";
        //utils::WriteFileData(fontfile, fontData, fontDataSize);
    //}

    //int *codeToGID = nullptr;
    //size_t codeToGIDLen = 0;
    //std::tie(codeToGID, codeToGIDLen) = getCodeToGID(gfxFont, fontData, fontDataSize);

    return ofdFont;
}
