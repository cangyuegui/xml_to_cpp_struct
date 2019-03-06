#ifndef __OTHER_H__
#define __OTHER_H__

#include "x2struct.hpp"

struct StruParams
{
     struct StruConfigXML
     {
          struct StruDoorStatus
          {
               int doorStatus;

               int lockStauts;

               int magnetic;

              XTOSTRUCT(O(doorStatus,lockStauts,magnetic));
          };

          StruDoorStatus DoorStatus;

         XTOSTRUCT(O(DoorStatus));
     };

     StruConfigXML ConfigXML;

    XTOSTRUCT(O(ConfigXML));
};

StruParams Params;

StruParams obStructObject;

#endif
