#include "iconutils.h"

QMap<QString, QString> Mere::Utils::IconUtils::MIMETYPES = {
    {"image", "file-image.svg"},
    {"audio", "file-audio.svg"},
    {"video", "file-video.svg"},

//    {"text/plain", "file-text.svg"},
    {"text/html", "file-code.svg"},

    {"application/json", "file-code.svg"},
    {"application/gzip", "file-archive.svg"},
    {"application/zip", "file-archive.svg"},
    {"application/pdf", "file-pdf.svg"},

    {"application/msword", "file-word.svg"},
    {"application/vnd.ms-word", "file-word.svg"},
    {"application/vnd.oasis.opendocument.text", "file-word.svg"},
    {"application/vnd.openxmlformats-officedocument.wordprocessingml", "file-word.svg"},

    {"application/vnd.ms-excel", "file-excel.svg"},
    {"application/vnd.openxmlformats-officedocument.spreadsheetml", "file-excel.svg"},
    {"application/vnd.oasis.opendocument.spreadsheet", "file-excel.svg"},

    {"application/vnd.ms-powerpoint", "file-powerpoint.svg"},
    {"application/vnd.openxmlformats-officedocument.presentationml", "file-powerpoint.svg"},
    {"application/vnd.oasis.opendocument.presentation", "file-powerpoint.svg"}
};

//static
QString Mere::Utils::IconUtils::fromMime(const QString &mime)
{
    if (MIMETYPES.contains(mime))
        return MIMETYPES.value(mime);

    return "file.svg";
}
