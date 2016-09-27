/* GNUstep.h - macros to make easier to port gnustep apps to macos-x
   Copyright (C) 2001 Free Software Foundation, Inc.

   Written by: Nicola Pero <n.pero@mi.flashnet.it>
   Date: March, October 2001
   
   This file is part of GNUstep.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef __GNUSTEP_GNUSTEP_H_INCLUDED_
#define __GNUSTEP_GNUSTEP_H_INCLUDED_

#ifndef GNUSTEP

#ifndef __has_feature
#  define __has_feature(x) 0
#endif

#if __has_feature(objc_arc)

#ifndef RETAIN
#define RETAIN(object)      (object)
#endif
#ifndef RELEASE
#define RELEASE(object)     
#endif
#ifndef AUTORELEASE
#define AUTORELEASE(object) (object)
#endif

#ifndef TEST_RETAIN
#define TEST_RETAIN(object) (object)
#endif
#ifndef TEST_RELEASE
#define TEST_RELEASE(object)
#endif
#ifndef TEST_AUTORELEASE
#define TEST_AUTORELEASE(object)    (object)
#endif

#ifndef ASSIGN
#define ASSIGN(object,value)    object = (value)
#endif
#ifndef ASSIGNCOPY
#define ASSIGNCOPY(object,value)    object = [(value) copy]
#endif
#ifndef DESTROY
#define DESTROY(object)     object = nil
#endif

#else

#define RETAIN(object)      [(id)(object) retain]
#define RELEASE(object)     [(object) release]
#define AUTORELEASE(object) [(id)(object) autorelease]

#define TEST_RETAIN(object) ({\
id __object = (id)(object); (__object != nil) ? [__object retain] : nil; })

#define TEST_RELEASE(object)    ({\
id __object = (id)(object); if (__object != nil) [__object release]; })

#define TEST_AUTORELEASE(object)    ({\
id __object = (id)(object); (__object != nil) ? [__object autorelease] : nil; })

#define ASSIGN(object,value)    ({\
  id __object = (id)(object); \
  object = [((id)value) retain]; \
  [__object release]; \
})

#define ASSIGNCOPY(object,value)    ({\
  id __object = (id)(object); \
  object = [((id)value) copy];\
  [__object release]; \
})

#define DESTROY(object)     ({ \
  id __o = object; \
  object = nil; \
  [__o release]; \
})

#endif /* __has_feature(objc_arc) */

#define CREATE_AUTORELEASE_POOL(X) \
  NSAutoreleasePool *(X) = [NSAutoreleasePool new]

#define RECREATE_AUTORELEASE_POOL(X)  \
  DESTROY(X);\
  (X) = [NSAutoreleasePool new]

#define _(X) NSLocalizedString (X, @"")
#define __(X) X

#define GSLocalizedStaticString(key, comment) key

#endif /* GNUSTEP */

#endif /* __GNUSTEP_GNUSTEP_H_INCLUDED_ */
