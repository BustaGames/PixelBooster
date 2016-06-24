#ifndef UTILSLIB_GLOBAL_H
#define UTILSLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UTILSLIB_LIBRARY)
#  define UTILSLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define UTILSLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // UTILSLIB_GLOBAL_H
