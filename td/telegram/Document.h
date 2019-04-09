//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2019
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "td/telegram/files/FileId.h"

#include "td/utils/common.h"
#include "td/utils/StringBuilder.h"

namespace td {

struct Document {
  // append only
  enum class Type : int32 { Unknown, Animation, Audio, General, Sticker, Video, VideoNote, VoiceNote };

  Type type = Type::Unknown;
  FileId file_id;

  Document() = default;
  Document(Type type, FileId file_id) : type(type), file_id(file_id) {
  }

  bool empty() const {
    return type == Type::Unknown;
  }
};

StringBuilder &operator<<(StringBuilder &string_builder, const Document &document);

}  // namespace td