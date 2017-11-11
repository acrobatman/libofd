#ifndef __WXOFD_GLOBAL_H__
#define __WXOFD_GLOBAL_H__

enum {
    ID_USER_BEGIN = wxID_HIGHEST+1,

    ID_CustomizeToolbar,
    ID_CreatePerspective,

    ID_FILE_OPEN,
    ID_FILE_NEW,
    ID_FILE_NEW_FROM_FILE,
    ID_FILE_NEW_FROM_SCANNER,

    ID_SampleItem, // must be last

    ID_FirstPerspective = ID_CreatePerspective+1000
};

static const char* sample_intro_text =
    "<html><body>"
    "<h3>Welcome to wxAUI</h3>"
    "<br/><b>Overview</b><br/>"
    "<p>wxAUI is an Advanced User Interface library for the wxWidgets toolkit "
    "that allows developers to create high-quality, cross-platform user "
    "interfaces quickly and easily.</p>"
    "<p><b>Features</b></p>"
    "<p>With wxAUI, developers can create application frameworks with:</p>"
    "<ul>"
    "<li>Native, dockable floating frames</li>"
    "<li>Perspective saving and loading</li>"
    "<li>Native toolbars incorporating real-time, &quot;spring-loaded&quot; dragging</li>"
    "<li>Customizable floating/docking behaviour</li>"
    "<li>Completely customizable look-and-feel</li>"
    "<li>Optional transparent window effects (while dragging or docking)</li>"
    "<li>Splittable notebook control</li>"
    "</ul>"
    "<p><b>What's new in 0.9.4?</b></p>"
    "<p>wxAUI 0.9.4, which is bundled with wxWidgets, adds the following features:"
    "<ul>"
    "<li>New wxAuiToolBar class, a toolbar control which integrates more "
    "cleanly with wxAuiFrameManager.</li>"
    "<li>Lots of bug fixes</li>"
    "</ul>"
    "<p><b>What's new in 0.9.3?</b></p>"
    "<p>wxAUI 0.9.3, which is now bundled with wxWidgets, adds the following features:"
    "<ul>"
    "<li>New wxAuiNotebook class, a dynamic splittable notebook control</li>"
    "<li>New wxAuiMDI* classes, a tab-based MDI and drop-in replacement for classic MDI</li>"
    "<li>Maximize/Restore buttons implemented</li>"
    "<li>Better hinting with wxGTK</li>"
    "<li>Class rename.  'wxAui' is now the standard class prefix for all wxAUI classes</li>"
    "<li>Lots of bug fixes</li>"
    "</ul>"
    "<p><b>What's new in 0.9.2?</b></p>"
    "<p>The following features/fixes have been added since the last version of wxAUI:</p>"
    "<ul>"
    "<li>Support for wxMac</li>"
    "<li>Updates for wxWidgets 2.6.3</li>"
    "<li>Fix to pass more unused events through</li>"
    "<li>Fix to allow floating windows to receive idle events</li>"
    "<li>Fix for minimizing/maximizing problem with transparent hint pane</li>"
    "<li>Fix to not paint empty hint rectangles</li>"
    "<li>Fix for 64-bit compilation</li>"
    "</ul>"
    "<p><b>What changed in 0.9.1?</b></p>"
    "<p>The following features/fixes were added in wxAUI 0.9.1:</p>"
    "<ul>"
    "<li>Support for MDI frames</li>"
    "<li>Gradient captions option</li>"
    "<li>Active/Inactive panes option</li>"
    "<li>Fix for screen artifacts/paint problems</li>"
    "<li>Fix for hiding/showing floated window problem</li>"
    "<li>Fix for floating pane sizing problem</li>"
    "<li>Fix for drop position problem when dragging around center pane margins</li>"
    "<li>LF-only text file formatting for source code</li>"
    "</ul>"
    "<p>See README.txt for more information.</p>"
    "</body></html>";

#endif // __WXOFD_GLOBAL_H__
