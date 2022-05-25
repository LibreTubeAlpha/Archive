//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2022
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "td/telegram/files/FileId.h"
#include "td/telegram/PhotoSize.h"
#include "td/telegram/SecretInputMedia.h"
#include "td/telegram/td_api.h"
#include "td/telegram/telegram_api.h"

#include "td/utils/buffer.h"
#include "td/utils/common.h"
#include "td/utils/FlatHashMap.h"

namespace td {

class Td;

class AudiosManager {
 public:
  explicit AudiosManager(Td *td);

  int32 get_audio_duration(FileId file_id) const;

  tl_object_ptr<td_api::audio> get_audio_object(FileId file_id) const;

  td_api::object_ptr<td_api::notificationSound> get_notification_sound_object(FileId file_id) const;

  void create_audio(FileId file_id, string minithumbnail, PhotoSize thumbnail, string file_name, string mime_type,
                    int32 duration, string title, string performer, int32 date, bool replace);

  tl_object_ptr<telegram_api::InputMedia> get_input_media(FileId file_id,
                                                          tl_object_ptr<telegram_api::InputFile> input_file,
                                                          tl_object_ptr<telegram_api::InputFile> input_thumbnail) const;

  SecretInputMedia get_secret_input_media(FileId audio_file_id,
                                          tl_object_ptr<telegram_api::InputEncryptedFile> input_file,
                                          const string &caption, BufferSlice thumbnail) const;

  FileId get_audio_thumbnail_file_id(FileId file_id) const;

  void delete_audio_thumbnail(FileId file_id);

  FileId dup_audio(FileId new_id, FileId old_id);

  void merge_audios(FileId new_id, FileId old_id, bool can_delete_old);

  template <class StorerT>
  void store_audio(FileId file_id, StorerT &storer) const;

  template <class ParserT>
  FileId parse_audio(ParserT &parser);

  string get_audio_search_text(FileId file_id) const;

 private:
  class Audio {
   public:
    string file_name;
    string mime_type;
    int32 duration = 0;
    int32 date = 0;
    string title;
    string performer;
    string minithumbnail;
    PhotoSize thumbnail;

    FileId file_id;
  };

  const Audio *get_audio(FileId file_id) const;

  FileId on_get_audio(unique_ptr<Audio> new_audio, bool replace);

  Td *td_;
  FlatHashMap<FileId, unique_ptr<Audio>, FileIdHash> audios_;
};

}  // namespace td
