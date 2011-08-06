/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/
Copyright (c) 2000-2009 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#include "PlayPenTests.h"

PlayPen_MultiViewports::PlayPen_MultiViewports()
{
	mInfo["Title"] = "PlayPen_MultiViewports";
	mInfo["Description"] = "Tests.";
	addScreenshotFrame(10);
}
//----------------------------------------------------------------------------

void PlayPen_MultiViewports::setupContent()
{
	SceneNode* mTestNode[3];
	
	// Set ambient light
	mSceneMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
	
	// Create a point light
	Light* l = mSceneMgr->createLight("MainLight");
	l->setType(Light::LT_DIRECTIONAL);
	l->setDirection(-Vector3::UNIT_Y);
	
	Entity* pEnt = mSceneMgr->createEntity( "1", "knot.mesh" );
	mSceneMgr->getRootSceneNode()->createChildSceneNode(Vector3(-30,0,-50))->attachObject(pEnt);
	
	mTestNode[0] = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	
	pEnt = mSceneMgr->createEntity( "2", "ogrehead.mesh" );
	mTestNode[0]->attachObject( pEnt );
	mTestNode[0]->translate(0, 0, 200);
	
	Ogre::Frustum* frustum = new Frustum();
	//frustum->setVisible(true);
	frustum->setFarClipDistance(5000);
	frustum->setNearClipDistance(100);
	mTestNode[0]->attachObject(frustum);
	
	Viewport* vp = mRoot->getAutoCreatedWindow()->addViewport(mCamera, 1, 0.5, 0.5, 0.5, 0.5);
	vp->setOverlaysEnabled(false);
	vp->setBackgroundColour(ColourValue(1,0,0));

	mCamera->setPosition(0,0,500);
	
}
