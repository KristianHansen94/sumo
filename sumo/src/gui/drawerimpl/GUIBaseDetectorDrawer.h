#ifndef GUIBaseDetectorDrawer_h
#define GUIBaseDetectorDrawer_h
//---------------------------------------------------------------------------//
//                        GUIBaseDetectorDrawer.h -
//  Base class for detector drawing
//                           -------------------
//  project              : SUMO - Simulation of Urban MObility
//  begin                : Wed, 14.Jan 2004
//  copyright            : (C) 2004 by Daniel Krajzewicz
//  organisation         : IVF/DLR http://ivf.dlr.de
//  email                : Daniel.Krajzewicz@dlr.de
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//---------------------------------------------------------------------------//
// $Log$
// Revision 1.2  2004/03/19 12:34:30  dkrajzew
// porting to FOX
//
// Revision 1.1  2004/01/26 06:39:41  dkrajzew
// visualisation of e3-detectors added; documentation added
//
/* =========================================================================
 * included modules
 * ======================================================================= */
#include <gui/GUISUMOAbstractView.h>


/* =========================================================================
 * class definitions
 * ======================================================================= */
class GUIBaseDetectorDrawer
{
public:
    /// Constructor
    GUIBaseDetectorDrawer(std::vector<GUIDetectorWrapper*> &detectors);

    /// Destructor
    virtual ~GUIBaseDetectorDrawer();

    /// Draws all detectors
    void drawGLDetectors(size_t *which, size_t maxDetectors,
        double scale);

protected:
    /** @brief Virtual function to be implemented taht actually performs the drawing
        The drawing process depends on whether the full or the simply geometry shall
        be used and whether tool tips shall be displayed or not */
    virtual void myDrawGLDetectors(size_t *which, size_t maxDetectors,
        double scale) = 0;

protected:
    /** @brief Inititialises the drawing process
        The textures have to be initialised */
    void initStep();

protected:
    /// The list of detectors to consider at drawing
    std::vector<GUIDetectorWrapper*> &myDetectors;

};


/**************** DO NOT DEFINE ANYTHING AFTER THE INCLUDE *****************/

#endif

// Local Variables:
// mode:C++
// End:
