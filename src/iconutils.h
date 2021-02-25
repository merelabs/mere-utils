#ifndef ICONUTILS_H
#define ICONUTILS_H

#include "global.h"

namespace Mere
{

namespace Utils
{

class MERE_UTILS_LIB_SPEC IconUtils
{
    IconUtils() = default;
public:
    static QString fromMime(const QString &mime);

private:
    static QMap<QString, QString> MIMETYPES;
};

}
}
#endif // ICONUTILS_H
