#ifndef _PathologyEnums
#define _PathologyEnums

#include <string>
#include <map>
#include "core_export.h"

namespace pathology {

  struct LUT {
    unsigned char colors[256][4];
    bool wrapAround;
  };

  extern CORE_EXPORT const std::map<std::string, LUT> ColorLookupTables;

  enum ColorType : int {
    InvalidColorType = 0,
    Monochrome = 1,
    RGB = 2,
    ARGB = 3,
    Indexed = 4
  };

  enum DataType : int {
    InvalidDataType = 0,
    UChar = 1,
    UInt16 = 2,
    UInt32 = 3,
    Float = 4
  };

  enum Compression : int {
    RAW = 0,
    JPEG = 1,
    LZW = 2,
    JPEG2000 = 3
  };

  enum Interpolation : int {
    NearestNeighbor = 0,
    Linear = 1
  };

}

#endif