//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2022
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "td/telegram/files/FileId.hpp"
#include "td/telegram/PhotoSize.h"
#include "td/telegram/Version.h"

#include "td/utils/logging.h"
#include "td/utils/tl_helpers.h"

namespace td {

template <class StorerT>
void store(Dimensions dimensions, StorerT &storer) {
  store(static_cast<uint32>((static_cast<uint32>(dimensions.width) << 16) | dimensions.height), storer);
}

template <class ParserT>
void parse(Dimensions &dimensions, ParserT &parser) {
  uint32 width_height;
  parse(width_height, parser);
  dimensions.width = static_cast<uint16>(width_height >> 16);
  dimensions.height = static_cast<uint16>(width_height & 0xFFFF);
}

template <class StorerT>
void store(const PhotoSize &photo_size, StorerT &storer) {
  LOG(DEBUG) << "Store photo size " << photo_size;
  store(photo_size.type, storer);
  store(photo_size.dimensions, storer);
  store(photo_size.size, storer);
  store(photo_size.file_id, storer);
  store(photo_size.progressive_sizes, storer);
}

template <class ParserT>
void parse(PhotoSize &photo_size, ParserT &parser) {
  parse(photo_size.type, parser);
  parse(photo_size.dimensions, parser);
  parse(photo_size.size, parser);
  parse(photo_size.file_id, parser);
  if (parser.version() >= static_cast<int32>(Version::AddPhotoProgressiveSizes)) {
    parse(photo_size.progressive_sizes, parser);
  } else {
    photo_size.progressive_sizes.clear();
  }
  if (photo_size.type < 0 || photo_size.type >= 128) {
    parser.set_error("Wrong PhotoSize type");
    return;
  }
  LOG(DEBUG) << "Parsed photo size " << photo_size;
}

template <class StorerT>
void store(const AnimationSize &animation_size, StorerT &storer) {
  store(static_cast<const PhotoSize &>(animation_size), storer);
  store(animation_size.main_frame_timestamp, storer);
}

template <class ParserT>
void parse(AnimationSize &animation_size, ParserT &parser) {
  parse(static_cast<PhotoSize &>(animation_size), parser);
  if (parser.version() >= static_cast<int32>(Version::AddDialogPhotoHasAnimation)) {
    parse(animation_size.main_frame_timestamp, parser);
  } else {
    animation_size.main_frame_timestamp = 0;
  }
}

}  // namespace td
