/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2010 Robert Geiman
                   <robgeiman@gmail.com>

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
--------------------------------------------------------------------------------
*/

#ifndef GMOGRE_CAMERA_H
#define GMOGRE_CAMERA_H

#include "GMOgre3D.h"

static double camera_id;
static double camera_entity_id;
static Ogre::String camera_entity_bone_name;

GMFN double CreateCamera(double aspect, double znear, double zfar, double fov)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Camera *cam = NULL;
   
   TRY
      cam = mSceneMgr->createCamera(GenerateUniqueName());

      if (cam == NULL)
         return FALSE;

      cam->setNearClipDistance((Ogre::Real)znear);
      cam->setFarClipDistance((Ogre::Real)zfar);
      cam->setAspectRatio(Ogre::Real(aspect));
      cam->setFOVy(Ogre::Degree((Ogre::Real)fov));
      cam->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(0)), Ogre::Degree(0), Ogre::Degree(0)));
   CATCH("CreateCamera")

   return ConvertToGMPointer(cam);
}


GMFN double DestroyCamera(double camera_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   mSceneMgr->destroyCamera(cam);

   return TRUE;
}


GMFN double SetCameraProjection(double camera_ptr, double xfrom, double zfrom, double yfrom, double xto, double zto, double yto, double xup, double zup, double yup)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setPosition(ConvertFromGMAxis(xfrom, yfrom, zfrom));
   cam->setDirection(ConvertFromGMAxis(xto, yto, zto));
   cam->lookAt(ConvertFromGMAxis(xup, yup, zup));

   return TRUE;
}


GMFN double SetCameraAspect(double camera_ptr, double aspect)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setAspectRatio(Ogre::Real(aspect));
   
   return TRUE;
}


GMFN double SetCameraClipDistances(double camera_ptr, double znear, double zfar)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setNearClipDistance((Ogre::Real)znear);
   cam->setFarClipDistance((Ogre::Real)zfar);

   return TRUE;
}


GMFN double SetCameraPosition(double camera_ptr, double x, double z, double y)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setPosition(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetCameraDirection(double camera_ptr, double xto, double zto, double yto)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setDirection(ConvertFromGMAxis(xto, yto, zto));

   return TRUE;
}


GMFN double GetCameraDirection(double camera_ptr, double xto, double zto, double yto)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Vector3 vec = cam->getDirection();

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double MoveCameraForward(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getDirection() * (Ogre::Real)delta);

   return TRUE;
}


GMFN double MoveCameraBackward(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getDirection() * ((Ogre::Real)delta * -1));

   return TRUE;
}


GMFN double MoveCameraRight(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getRight() * (Ogre::Real)delta);

   return TRUE;
}


GMFN double MoveCameraLeft(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getRight() * ((Ogre::Real)delta * -1));

   return TRUE;
}


GMFN double MoveCameraUp(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getUp() * (Ogre::Real)delta);

   return TRUE;
}


GMFN double MoveCameraDown(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getUp() * ((Ogre::Real)delta * -1));

   return TRUE;
}


GMFN double GetCameraPosition(double camera_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Vector3 vec = cam->getPosition();

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double GetCameraDerivedPosition(double camera_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Vector3 vec = cam->getDerivedPosition();

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double SetCameraLookAt(double camera_ptr, double x, double z, double y)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->lookAt(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetCameraOrientation(double cam_ptr, double yaw, double pitch, double roll)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMRoll(roll))));

   return TRUE;
}


GMFN double GetCameraOrientation(double cam_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Quaternion quat = cam->getOrientation();

   AcquireGMEulerGlobals();
   if (mEulerYaw != NULL)
   {
      Euler euler = QuaternionToEuler(quat);

      SetGMVariable(*mEulerYaw, ConvertToGMYaw(euler.getYaw().valueDegrees()));
      SetGMVariable(*mEulerPitch, ConvertToGMPitch(euler.getPitch().valueDegrees()));
      SetGMVariable(*mEulerRoll, ConvertToGMRoll(euler.getRoll().valueDegrees()));
   }

   return TRUE;
}


GMFN double GetCameraDerivedOrientation(double cam_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Quaternion quat = cam->getDerivedOrientation();

   AcquireGMEulerGlobals();
   if (mEulerYaw != NULL)
   {
      SetGMVariable(*mEulerYaw, ConvertToGMYaw(quat.getYaw().valueDegrees()));
      SetGMVariable(*mEulerPitch, ConvertToGMPitch(quat.getPitch().valueDegrees()));
      SetGMVariable(*mEulerRoll, ConvertToGMRoll(quat.getRoll().valueDegrees()));
   }

   return TRUE;
}


GMFN double SetCameraRoll(double camera_ptr, double degrees)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->roll(Ogre::Degree((Ogre::Real)degrees));

   return TRUE;
}


GMFN double GetCameraRoll(double camera_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Quaternion quat = cam->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   return ConvertToGMRoll(euler.getRoll().valueDegrees());
}


GMFN double SetCameraYaw(double camera_ptr, double degrees)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->yaw(Ogre::Degree((Ogre::Real)degrees));

   return TRUE;
}


GMFN double GetCameraYaw(double camera_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Quaternion quat = cam->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   return ConvertToGMYaw(euler.getYaw().valueDegrees());
}


GMFN double SetCameraPitch(double camera_ptr, double degrees)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->pitch(Ogre::Degree((Ogre::Real)degrees));

   return TRUE;
}


GMFN double GetCameraPitch(double camera_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Quaternion quat = cam->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   return ConvertToGMPitch(euler.getPitch().valueDegrees());
}


GMFN double SetCameraFOV(double camera_ptr, double angle)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setFOVy(Ogre::Degree((Ogre::Real)angle));

   return TRUE;
}


GMFN double SetCameraProjectionType(double camera_ptr, double type)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setProjectionType(static_cast<Ogre::ProjectionType>((int)type));
   //cam->setOrthoWindow(w, h);

   return TRUE;
}


GMFN double SetCameraRenderType(double camera_ptr, double type)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setPolygonMode(static_cast<Ogre::PolygonMode>((int)type));

   return TRUE;
}


GMFN double SetCameraLODBias(double camera_ptr, double factor)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setLodBias((Ogre::Real)factor);

   return TRUE;
}


GMFN double GetCameraLODBias(double camera_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   return cam->getLodBias();
}


GMFN double EnableCameraAutoTracking(double camera_ptr, double enable, double scene_node_ptr, double x, double z, double y)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   if (enable != 0)
   {
      Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

      if (node == NULL)
         return FALSE;

      cam->setAutoTracking(true, node, ConvertFromGMAxis(x, y, z));
   }
   else
      cam->setAutoTracking(false);

   return TRUE;
}


GMFN double EnableCameraFixedYawAxis(double cam_ptr, double enable, double x, double z, double y)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;
   
   cam->setFixedYawAxis((enable != 0), ConvertFromGMAxis(x, y, z));

   return TRUE;
} 


GMFN double EnableCameraReflection(double cam_ptr, double enable, double plane_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;
   
   Ogre::Plane *plane = ConvertFromGMPointer<Ogre::Plane*>(plane_ptr);

   if (plane == NULL)
      return FALSE;

   if (enable != 0)
      cam->enableReflection(*plane);
   else
      cam->disableReflection();

   return TRUE;
} 


GMFN double GetCameraToViewportRay(double cam_ptr, double x, double y)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return 0;
   
   Ogre::Real realitive_x = (Ogre::Real)x / cam->getViewport()->getActualWidth();
   Ogre::Real realitive_y = (Ogre::Real)y / cam->getViewport()->getActualHeight();

   Ogre::Ray *ray = OGRE_NEW Ogre::Ray;
   cam->getCameraToViewportRay(realitive_x, realitive_y, ray);

   return ConvertToGMPointer(ray);
} 


GMFN double GetCameraProjectionMatrix(double cam_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Matrix4 mat = cam->getProjectionMatrix();

   AcquireGMMatrixGlobals();
   if (mEulerYaw != NULL)
   {
      SetGMVariable(*mMatrix00, mat[0][0]);
      SetGMVariable(*mMatrix01, mat[0][1]);
      SetGMVariable(*mMatrix02, mat[0][2]);
      SetGMVariable(*mMatrix03, mat[0][3]);
      SetGMVariable(*mMatrix10, mat[1][0]);
      SetGMVariable(*mMatrix11, mat[1][1]);
      SetGMVariable(*mMatrix12, mat[1][2]);
      SetGMVariable(*mMatrix13, mat[1][3]);
      SetGMVariable(*mMatrix20, mat[2][0]);
      SetGMVariable(*mMatrix21, mat[2][1]);
      SetGMVariable(*mMatrix22, mat[2][2]);
      SetGMVariable(*mMatrix23, mat[2][3]);
      SetGMVariable(*mMatrix30, mat[3][0]);
      SetGMVariable(*mMatrix31, mat[3][1]);
      SetGMVariable(*mMatrix32, mat[3][2]);
      SetGMVariable(*mMatrix33, mat[3][3]);

   }

   return TRUE;
}


GMFN double GetCameraProjectionMatrixRS(double cam_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Matrix4 mat = cam->getProjectionMatrixRS();

   AcquireGMMatrixGlobals();
   if (mEulerYaw != NULL)
   {
      SetGMVariable(*mMatrix00, mat[0][0]);
      SetGMVariable(*mMatrix01, mat[0][1]);
      SetGMVariable(*mMatrix02, mat[0][2]);
      SetGMVariable(*mMatrix03, mat[0][3]);
      SetGMVariable(*mMatrix10, mat[1][0]);
      SetGMVariable(*mMatrix11, mat[1][1]);
      SetGMVariable(*mMatrix12, mat[1][2]);
      SetGMVariable(*mMatrix13, mat[1][3]);
      SetGMVariable(*mMatrix20, mat[2][0]);
      SetGMVariable(*mMatrix21, mat[2][1]);
      SetGMVariable(*mMatrix22, mat[2][2]);
      SetGMVariable(*mMatrix23, mat[2][3]);
      SetGMVariable(*mMatrix30, mat[3][0]);
      SetGMVariable(*mMatrix31, mat[3][1]);
      SetGMVariable(*mMatrix32, mat[3][2]);
      SetGMVariable(*mMatrix33, mat[3][3]);
   }

   return TRUE;
}


GMFN double GetCameraProjectionMatrixWithRSDepth(double cam_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Matrix4 mat = cam->getProjectionMatrixWithRSDepth();

   AcquireGMMatrixGlobals();
   if (mEulerYaw != NULL)
   {
      SetGMVariable(*mMatrix00, mat[0][0]);
      SetGMVariable(*mMatrix01, mat[0][1]);
      SetGMVariable(*mMatrix02, mat[0][2]);
      SetGMVariable(*mMatrix03, mat[0][3]);
      SetGMVariable(*mMatrix10, mat[1][0]);
      SetGMVariable(*mMatrix11, mat[1][1]);
      SetGMVariable(*mMatrix12, mat[1][2]);
      SetGMVariable(*mMatrix13, mat[1][3]);
      SetGMVariable(*mMatrix20, mat[2][0]);
      SetGMVariable(*mMatrix21, mat[2][1]);
      SetGMVariable(*mMatrix22, mat[2][2]);
      SetGMVariable(*mMatrix23, mat[2][3]);
      SetGMVariable(*mMatrix30, mat[3][0]);
      SetGMVariable(*mMatrix31, mat[3][1]);
      SetGMVariable(*mMatrix32, mat[3][2]);
      SetGMVariable(*mMatrix33, mat[3][3]);
   }

   return TRUE;
}


GMFN double AttachCameraToSceneNode(double cam_ptr, double scene_node_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->attachObject(cam);

   return TRUE;
}


GMFN double DetachCameraFromSceneNode(double cam_ptr, double scene_node_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->detachObject(cam);

   return TRUE;
}


GMFN double AttachCameraToEntityBone1(double cam_ptr, double entity_ptr, char *bone_name)
{
   camera_id = cam_ptr;
   camera_entity_id = entity_ptr;
   camera_entity_bone_name = bone_name;

   return TRUE;
}


GMFN double AttachCameraToEntityBone2(double x, double y, double z, double yaw, double pitch, double roll)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_id);

   if (cam == NULL)
      return FALSE;

   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(camera_entity_id);

   if (entity == NULL)
      return FALSE;

   entity->attachObjectToBone(camera_entity_bone_name, cam, Euler(Ogre::Degree(ConvertFromGMYaw(yaw + 90)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMRoll(roll))), ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double DetachCameraFromEntityBone(double cam_ptr, double entity_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;
   
   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (entity == NULL)
      return FALSE;
   
   entity->detachObjectFromBone(cam->getName());

   return TRUE;
}

#endif
