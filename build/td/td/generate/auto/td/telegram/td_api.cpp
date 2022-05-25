#include "td_api.h"

#include "td/utils/common.h"
#include "td/utils/format.h"
#include "td/utils/logging.h"
#include "td/utils/SliceBuilder.h"
#include "td/utils/tl_parsers.h"
#include "td/utils/tl_storers.h"
#include "td/utils/TlStorerToString.h"

namespace td {
namespace td_api {

std::string to_string(const BaseObject &value) {
  TlStorerToString storer;
  value.store(storer, "");
  return storer.move_as_string();
}

accountTtl::accountTtl()
  : days_()
{}

accountTtl::accountTtl(int32 days_)
  : days_(days_)
{}

const std::int32_t accountTtl::ID;

void accountTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accountTtl");
    s.store_field("days", days_);
    s.store_class_end();
  }
}

addedReaction::addedReaction()
  : reaction_()
  , sender_id_()
{}

addedReaction::addedReaction(string const &reaction_, object_ptr<MessageSender> &&sender_id_)
  : reaction_(reaction_)
  , sender_id_(std::move(sender_id_))
{}

const std::int32_t addedReaction::ID;

void addedReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addedReaction");
    s.store_field("reaction", reaction_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_class_end();
  }
}

addedReactions::addedReactions()
  : total_count_()
  , reactions_()
  , next_offset_()
{}

addedReactions::addedReactions(int32 total_count_, array<object_ptr<addedReaction>> &&reactions_, string const &next_offset_)
  : total_count_(total_count_)
  , reactions_(std::move(reactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t addedReactions::ID;

void addedReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addedReactions");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

address::address()
  : country_code_()
  , state_()
  , city_()
  , street_line1_()
  , street_line2_()
  , postal_code_()
{}

address::address(string const &country_code_, string const &state_, string const &city_, string const &street_line1_, string const &street_line2_, string const &postal_code_)
  : country_code_(country_code_)
  , state_(state_)
  , city_(city_)
  , street_line1_(street_line1_)
  , street_line2_(street_line2_)
  , postal_code_(postal_code_)
{}

const std::int32_t address::ID;

void address::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "address");
    s.store_field("country_code", country_code_);
    s.store_field("state", state_);
    s.store_field("city", city_);
    s.store_field("street_line1", street_line1_);
    s.store_field("street_line2", street_line2_);
    s.store_field("postal_code", postal_code_);
    s.store_class_end();
  }
}

animatedChatPhoto::animatedChatPhoto()
  : length_()
  , file_()
  , main_frame_timestamp_()
{}

animatedChatPhoto::animatedChatPhoto(int32 length_, object_ptr<file> &&file_, double main_frame_timestamp_)
  : length_(length_)
  , file_(std::move(file_))
  , main_frame_timestamp_(main_frame_timestamp_)
{}

const std::int32_t animatedChatPhoto::ID;

void animatedChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animatedChatPhoto");
    s.store_field("length", length_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("main_frame_timestamp", main_frame_timestamp_);
    s.store_class_end();
  }
}

animatedEmoji::animatedEmoji()
  : sticker_()
  , fitzpatrick_type_()
  , sound_()
{}

animatedEmoji::animatedEmoji(object_ptr<sticker> &&sticker_, int32 fitzpatrick_type_, object_ptr<file> &&sound_)
  : sticker_(std::move(sticker_))
  , fitzpatrick_type_(fitzpatrick_type_)
  , sound_(std::move(sound_))
{}

const std::int32_t animatedEmoji::ID;

void animatedEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animatedEmoji");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("fitzpatrick_type", fitzpatrick_type_);
    s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get()));
    s.store_class_end();
  }
}

animation::animation()
  : duration_()
  , width_()
  , height_()
  , file_name_()
  , mime_type_()
  , has_stickers_()
  , minithumbnail_()
  , thumbnail_()
  , animation_()
{}

animation::animation(int32 duration_, int32 width_, int32 height_, string const &file_name_, string const &mime_type_, bool has_stickers_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&animation_)
  : duration_(duration_)
  , width_(width_)
  , height_(height_)
  , file_name_(file_name_)
  , mime_type_(mime_type_)
  , has_stickers_(has_stickers_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , animation_(std::move(animation_))
{}

const std::int32_t animation::ID;

void animation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animation");
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_field("has_stickers", has_stickers_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

animations::animations()
  : animations_()
{}

animations::animations(array<object_ptr<animation>> &&animations_)
  : animations_(std::move(animations_))
{}

const std::int32_t animations::ID;

void animations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animations");
    { s.store_vector_begin("animations", animations_.size()); for (const auto &_value : animations_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

attachmentMenuBot::attachmentMenuBot()
  : bot_user_id_()
  , name_()
  , name_color_()
  , default_icon_()
  , ios_static_icon_()
  , ios_animated_icon_()
  , android_icon_()
  , macos_icon_()
  , icon_color_()
{}

attachmentMenuBot::attachmentMenuBot(int53 bot_user_id_, string const &name_, object_ptr<attachmentMenuBotColor> &&name_color_, object_ptr<file> &&default_icon_, object_ptr<file> &&ios_static_icon_, object_ptr<file> &&ios_animated_icon_, object_ptr<file> &&android_icon_, object_ptr<file> &&macos_icon_, object_ptr<attachmentMenuBotColor> &&icon_color_)
  : bot_user_id_(bot_user_id_)
  , name_(name_)
  , name_color_(std::move(name_color_))
  , default_icon_(std::move(default_icon_))
  , ios_static_icon_(std::move(ios_static_icon_))
  , ios_animated_icon_(std::move(ios_animated_icon_))
  , android_icon_(std::move(android_icon_))
  , macos_icon_(std::move(macos_icon_))
  , icon_color_(std::move(icon_color_))
{}

const std::int32_t attachmentMenuBot::ID;

void attachmentMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachmentMenuBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("name", name_);
    s.store_object_field("name_color", static_cast<const BaseObject *>(name_color_.get()));
    s.store_object_field("default_icon", static_cast<const BaseObject *>(default_icon_.get()));
    s.store_object_field("ios_static_icon", static_cast<const BaseObject *>(ios_static_icon_.get()));
    s.store_object_field("ios_animated_icon", static_cast<const BaseObject *>(ios_animated_icon_.get()));
    s.store_object_field("android_icon", static_cast<const BaseObject *>(android_icon_.get()));
    s.store_object_field("macos_icon", static_cast<const BaseObject *>(macos_icon_.get()));
    s.store_object_field("icon_color", static_cast<const BaseObject *>(icon_color_.get()));
    s.store_class_end();
  }
}

attachmentMenuBotColor::attachmentMenuBotColor()
  : light_color_()
  , dark_color_()
{}

attachmentMenuBotColor::attachmentMenuBotColor(int32 light_color_, int32 dark_color_)
  : light_color_(light_color_)
  , dark_color_(dark_color_)
{}

const std::int32_t attachmentMenuBotColor::ID;

void attachmentMenuBotColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachmentMenuBotColor");
    s.store_field("light_color", light_color_);
    s.store_field("dark_color", dark_color_);
    s.store_class_end();
  }
}

audio::audio()
  : duration_()
  , title_()
  , performer_()
  , file_name_()
  , mime_type_()
  , album_cover_minithumbnail_()
  , album_cover_thumbnail_()
  , audio_()
{}

audio::audio(int32 duration_, string const &title_, string const &performer_, string const &file_name_, string const &mime_type_, object_ptr<minithumbnail> &&album_cover_minithumbnail_, object_ptr<thumbnail> &&album_cover_thumbnail_, object_ptr<file> &&audio_)
  : duration_(duration_)
  , title_(title_)
  , performer_(performer_)
  , file_name_(file_name_)
  , mime_type_(mime_type_)
  , album_cover_minithumbnail_(std::move(album_cover_minithumbnail_))
  , album_cover_thumbnail_(std::move(album_cover_thumbnail_))
  , audio_(std::move(audio_))
{}

const std::int32_t audio::ID;

void audio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "audio");
    s.store_field("duration", duration_);
    s.store_field("title", title_);
    s.store_field("performer", performer_);
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_object_field("album_cover_minithumbnail", static_cast<const BaseObject *>(album_cover_minithumbnail_.get()));
    s.store_object_field("album_cover_thumbnail", static_cast<const BaseObject *>(album_cover_thumbnail_.get()));
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_class_end();
  }
}

authenticationCodeInfo::authenticationCodeInfo()
  : phone_number_()
  , type_()
  , next_type_()
  , timeout_()
{}

authenticationCodeInfo::authenticationCodeInfo(string const &phone_number_, object_ptr<AuthenticationCodeType> &&type_, object_ptr<AuthenticationCodeType> &&next_type_, int32 timeout_)
  : phone_number_(phone_number_)
  , type_(std::move(type_))
  , next_type_(std::move(next_type_))
  , timeout_(timeout_)
{}

const std::int32_t authenticationCodeInfo::ID;

void authenticationCodeInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeInfo");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("next_type", static_cast<const BaseObject *>(next_type_.get()));
    s.store_field("timeout", timeout_);
    s.store_class_end();
  }
}

authenticationCodeTypeTelegramMessage::authenticationCodeTypeTelegramMessage()
  : length_()
{}

authenticationCodeTypeTelegramMessage::authenticationCodeTypeTelegramMessage(int32 length_)
  : length_(length_)
{}

const std::int32_t authenticationCodeTypeTelegramMessage::ID;

void authenticationCodeTypeTelegramMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeTelegramMessage");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeSms::authenticationCodeTypeSms()
  : length_()
{}

authenticationCodeTypeSms::authenticationCodeTypeSms(int32 length_)
  : length_(length_)
{}

const std::int32_t authenticationCodeTypeSms::ID;

void authenticationCodeTypeSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeSms");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeCall::authenticationCodeTypeCall()
  : length_()
{}

authenticationCodeTypeCall::authenticationCodeTypeCall(int32 length_)
  : length_(length_)
{}

const std::int32_t authenticationCodeTypeCall::ID;

void authenticationCodeTypeCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeCall");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeFlashCall::authenticationCodeTypeFlashCall()
  : pattern_()
{}

authenticationCodeTypeFlashCall::authenticationCodeTypeFlashCall(string const &pattern_)
  : pattern_(pattern_)
{}

const std::int32_t authenticationCodeTypeFlashCall::ID;

void authenticationCodeTypeFlashCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeFlashCall");
    s.store_field("pattern", pattern_);
    s.store_class_end();
  }
}

authenticationCodeTypeMissedCall::authenticationCodeTypeMissedCall()
  : phone_number_prefix_()
  , length_()
{}

authenticationCodeTypeMissedCall::authenticationCodeTypeMissedCall(string const &phone_number_prefix_, int32 length_)
  : phone_number_prefix_(phone_number_prefix_)
  , length_(length_)
{}

const std::int32_t authenticationCodeTypeMissedCall::ID;

void authenticationCodeTypeMissedCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeMissedCall");
    s.store_field("phone_number_prefix", phone_number_prefix_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authorizationStateWaitTdlibParameters::authorizationStateWaitTdlibParameters() {
}

const std::int32_t authorizationStateWaitTdlibParameters::ID;

void authorizationStateWaitTdlibParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitTdlibParameters");
    s.store_class_end();
  }
}

authorizationStateWaitEncryptionKey::authorizationStateWaitEncryptionKey()
  : is_encrypted_()
{}

authorizationStateWaitEncryptionKey::authorizationStateWaitEncryptionKey(bool is_encrypted_)
  : is_encrypted_(is_encrypted_)
{}

const std::int32_t authorizationStateWaitEncryptionKey::ID;

void authorizationStateWaitEncryptionKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitEncryptionKey");
    s.store_field("is_encrypted", is_encrypted_);
    s.store_class_end();
  }
}

authorizationStateWaitPhoneNumber::authorizationStateWaitPhoneNumber() {
}

const std::int32_t authorizationStateWaitPhoneNumber::ID;

void authorizationStateWaitPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitPhoneNumber");
    s.store_class_end();
  }
}

authorizationStateWaitCode::authorizationStateWaitCode()
  : code_info_()
{}

authorizationStateWaitCode::authorizationStateWaitCode(object_ptr<authenticationCodeInfo> &&code_info_)
  : code_info_(std::move(code_info_))
{}

const std::int32_t authorizationStateWaitCode::ID;

void authorizationStateWaitCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitCode");
    s.store_object_field("code_info", static_cast<const BaseObject *>(code_info_.get()));
    s.store_class_end();
  }
}

authorizationStateWaitOtherDeviceConfirmation::authorizationStateWaitOtherDeviceConfirmation()
  : link_()
{}

authorizationStateWaitOtherDeviceConfirmation::authorizationStateWaitOtherDeviceConfirmation(string const &link_)
  : link_(link_)
{}

const std::int32_t authorizationStateWaitOtherDeviceConfirmation::ID;

void authorizationStateWaitOtherDeviceConfirmation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitOtherDeviceConfirmation");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

authorizationStateWaitRegistration::authorizationStateWaitRegistration()
  : terms_of_service_()
{}

authorizationStateWaitRegistration::authorizationStateWaitRegistration(object_ptr<termsOfService> &&terms_of_service_)
  : terms_of_service_(std::move(terms_of_service_))
{}

const std::int32_t authorizationStateWaitRegistration::ID;

void authorizationStateWaitRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitRegistration");
    s.store_object_field("terms_of_service", static_cast<const BaseObject *>(terms_of_service_.get()));
    s.store_class_end();
  }
}

authorizationStateWaitPassword::authorizationStateWaitPassword()
  : password_hint_()
  , has_recovery_email_address_()
  , recovery_email_address_pattern_()
{}

authorizationStateWaitPassword::authorizationStateWaitPassword(string const &password_hint_, bool has_recovery_email_address_, string const &recovery_email_address_pattern_)
  : password_hint_(password_hint_)
  , has_recovery_email_address_(has_recovery_email_address_)
  , recovery_email_address_pattern_(recovery_email_address_pattern_)
{}

const std::int32_t authorizationStateWaitPassword::ID;

void authorizationStateWaitPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateWaitPassword");
    s.store_field("password_hint", password_hint_);
    s.store_field("has_recovery_email_address", has_recovery_email_address_);
    s.store_field("recovery_email_address_pattern", recovery_email_address_pattern_);
    s.store_class_end();
  }
}

authorizationStateReady::authorizationStateReady() {
}

const std::int32_t authorizationStateReady::ID;

void authorizationStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateReady");
    s.store_class_end();
  }
}

authorizationStateLoggingOut::authorizationStateLoggingOut() {
}

const std::int32_t authorizationStateLoggingOut::ID;

void authorizationStateLoggingOut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateLoggingOut");
    s.store_class_end();
  }
}

authorizationStateClosing::authorizationStateClosing() {
}

const std::int32_t authorizationStateClosing::ID;

void authorizationStateClosing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateClosing");
    s.store_class_end();
  }
}

authorizationStateClosed::authorizationStateClosed() {
}

const std::int32_t authorizationStateClosed::ID;

void authorizationStateClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorizationStateClosed");
    s.store_class_end();
  }
}

autoDownloadSettings::autoDownloadSettings()
  : is_auto_download_enabled_()
  , max_photo_file_size_()
  , max_video_file_size_()
  , max_other_file_size_()
  , video_upload_bitrate_()
  , preload_large_videos_()
  , preload_next_audio_()
  , use_less_data_for_calls_()
{}

autoDownloadSettings::autoDownloadSettings(bool is_auto_download_enabled_, int32 max_photo_file_size_, int32 max_video_file_size_, int32 max_other_file_size_, int32 video_upload_bitrate_, bool preload_large_videos_, bool preload_next_audio_, bool use_less_data_for_calls_)
  : is_auto_download_enabled_(is_auto_download_enabled_)
  , max_photo_file_size_(max_photo_file_size_)
  , max_video_file_size_(max_video_file_size_)
  , max_other_file_size_(max_other_file_size_)
  , video_upload_bitrate_(video_upload_bitrate_)
  , preload_large_videos_(preload_large_videos_)
  , preload_next_audio_(preload_next_audio_)
  , use_less_data_for_calls_(use_less_data_for_calls_)
{}

const std::int32_t autoDownloadSettings::ID;

void autoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoDownloadSettings");
    s.store_field("is_auto_download_enabled", is_auto_download_enabled_);
    s.store_field("max_photo_file_size", max_photo_file_size_);
    s.store_field("max_video_file_size", max_video_file_size_);
    s.store_field("max_other_file_size", max_other_file_size_);
    s.store_field("video_upload_bitrate", video_upload_bitrate_);
    s.store_field("preload_large_videos", preload_large_videos_);
    s.store_field("preload_next_audio", preload_next_audio_);
    s.store_field("use_less_data_for_calls", use_less_data_for_calls_);
    s.store_class_end();
  }
}

autoDownloadSettingsPresets::autoDownloadSettingsPresets()
  : low_()
  , medium_()
  , high_()
{}

autoDownloadSettingsPresets::autoDownloadSettingsPresets(object_ptr<autoDownloadSettings> &&low_, object_ptr<autoDownloadSettings> &&medium_, object_ptr<autoDownloadSettings> &&high_)
  : low_(std::move(low_))
  , medium_(std::move(medium_))
  , high_(std::move(high_))
{}

const std::int32_t autoDownloadSettingsPresets::ID;

void autoDownloadSettingsPresets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoDownloadSettingsPresets");
    s.store_object_field("low", static_cast<const BaseObject *>(low_.get()));
    s.store_object_field("medium", static_cast<const BaseObject *>(medium_.get()));
    s.store_object_field("high", static_cast<const BaseObject *>(high_.get()));
    s.store_class_end();
  }
}

availableReactions::availableReactions()
  : reactions_()
{}

availableReactions::availableReactions(array<string> &&reactions_)
  : reactions_(std::move(reactions_))
{}

const std::int32_t availableReactions::ID;

void availableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableReactions");
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

background::background()
  : id_()
  , is_default_()
  , is_dark_()
  , name_()
  , document_()
  , type_()
{}

background::background(int64 id_, bool is_default_, bool is_dark_, string const &name_, object_ptr<document> &&document_, object_ptr<BackgroundType> &&type_)
  : id_(id_)
  , is_default_(is_default_)
  , is_dark_(is_dark_)
  , name_(name_)
  , document_(std::move(document_))
  , type_(std::move(type_))
{}

const std::int32_t background::ID;

void background::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "background");
    s.store_field("id", id_);
    s.store_field("is_default", is_default_);
    s.store_field("is_dark", is_dark_);
    s.store_field("name", name_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

backgroundFillSolid::backgroundFillSolid()
  : color_()
{}

backgroundFillSolid::backgroundFillSolid(int32 color_)
  : color_(color_)
{}

const std::int32_t backgroundFillSolid::ID;

void backgroundFillSolid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundFillSolid");
    s.store_field("color", color_);
    s.store_class_end();
  }
}

backgroundFillGradient::backgroundFillGradient()
  : top_color_()
  , bottom_color_()
  , rotation_angle_()
{}

backgroundFillGradient::backgroundFillGradient(int32 top_color_, int32 bottom_color_, int32 rotation_angle_)
  : top_color_(top_color_)
  , bottom_color_(bottom_color_)
  , rotation_angle_(rotation_angle_)
{}

const std::int32_t backgroundFillGradient::ID;

void backgroundFillGradient::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundFillGradient");
    s.store_field("top_color", top_color_);
    s.store_field("bottom_color", bottom_color_);
    s.store_field("rotation_angle", rotation_angle_);
    s.store_class_end();
  }
}

backgroundFillFreeformGradient::backgroundFillFreeformGradient()
  : colors_()
{}

backgroundFillFreeformGradient::backgroundFillFreeformGradient(array<int32> &&colors_)
  : colors_(std::move(colors_))
{}

const std::int32_t backgroundFillFreeformGradient::ID;

void backgroundFillFreeformGradient::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundFillFreeformGradient");
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

backgroundTypeWallpaper::backgroundTypeWallpaper()
  : is_blurred_()
  , is_moving_()
{}

backgroundTypeWallpaper::backgroundTypeWallpaper(bool is_blurred_, bool is_moving_)
  : is_blurred_(is_blurred_)
  , is_moving_(is_moving_)
{}

const std::int32_t backgroundTypeWallpaper::ID;

void backgroundTypeWallpaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundTypeWallpaper");
    s.store_field("is_blurred", is_blurred_);
    s.store_field("is_moving", is_moving_);
    s.store_class_end();
  }
}

backgroundTypePattern::backgroundTypePattern()
  : fill_()
  , intensity_()
  , is_inverted_()
  , is_moving_()
{}

backgroundTypePattern::backgroundTypePattern(object_ptr<BackgroundFill> &&fill_, int32 intensity_, bool is_inverted_, bool is_moving_)
  : fill_(std::move(fill_))
  , intensity_(intensity_)
  , is_inverted_(is_inverted_)
  , is_moving_(is_moving_)
{}

const std::int32_t backgroundTypePattern::ID;

void backgroundTypePattern::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundTypePattern");
    s.store_object_field("fill", static_cast<const BaseObject *>(fill_.get()));
    s.store_field("intensity", intensity_);
    s.store_field("is_inverted", is_inverted_);
    s.store_field("is_moving", is_moving_);
    s.store_class_end();
  }
}

backgroundTypeFill::backgroundTypeFill()
  : fill_()
{}

backgroundTypeFill::backgroundTypeFill(object_ptr<BackgroundFill> &&fill_)
  : fill_(std::move(fill_))
{}

const std::int32_t backgroundTypeFill::ID;

void backgroundTypeFill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundTypeFill");
    s.store_object_field("fill", static_cast<const BaseObject *>(fill_.get()));
    s.store_class_end();
  }
}

backgrounds::backgrounds()
  : backgrounds_()
{}

backgrounds::backgrounds(array<object_ptr<background>> &&backgrounds_)
  : backgrounds_(std::move(backgrounds_))
{}

const std::int32_t backgrounds::ID;

void backgrounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgrounds");
    { s.store_vector_begin("backgrounds", backgrounds_.size()); for (const auto &_value : backgrounds_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

bankCardActionOpenUrl::bankCardActionOpenUrl()
  : text_()
  , url_()
{}

bankCardActionOpenUrl::bankCardActionOpenUrl(string const &text_, string const &url_)
  : text_(text_)
  , url_(url_)
{}

const std::int32_t bankCardActionOpenUrl::ID;

void bankCardActionOpenUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bankCardActionOpenUrl");
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

bankCardInfo::bankCardInfo()
  : title_()
  , actions_()
{}

bankCardInfo::bankCardInfo(string const &title_, array<object_ptr<bankCardActionOpenUrl>> &&actions_)
  : title_(title_)
  , actions_(std::move(actions_))
{}

const std::int32_t bankCardInfo::ID;

void bankCardInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bankCardInfo");
    s.store_field("title", title_);
    { s.store_vector_begin("actions", actions_.size()); for (const auto &_value : actions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

basicGroup::basicGroup()
  : id_()
  , member_count_()
  , status_()
  , is_active_()
  , upgraded_to_supergroup_id_()
{}

basicGroup::basicGroup(int53 id_, int32 member_count_, object_ptr<ChatMemberStatus> &&status_, bool is_active_, int53 upgraded_to_supergroup_id_)
  : id_(id_)
  , member_count_(member_count_)
  , status_(std::move(status_))
  , is_active_(is_active_)
  , upgraded_to_supergroup_id_(upgraded_to_supergroup_id_)
{}

const std::int32_t basicGroup::ID;

void basicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "basicGroup");
    s.store_field("id", id_);
    s.store_field("member_count", member_count_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("is_active", is_active_);
    s.store_field("upgraded_to_supergroup_id", upgraded_to_supergroup_id_);
    s.store_class_end();
  }
}

basicGroupFullInfo::basicGroupFullInfo()
  : photo_()
  , description_()
  , creator_user_id_()
  , members_()
  , invite_link_()
  , bot_commands_()
{}

basicGroupFullInfo::basicGroupFullInfo(object_ptr<chatPhoto> &&photo_, string const &description_, int53 creator_user_id_, array<object_ptr<chatMember>> &&members_, object_ptr<chatInviteLink> &&invite_link_, array<object_ptr<botCommands>> &&bot_commands_)
  : photo_(std::move(photo_))
  , description_(description_)
  , creator_user_id_(creator_user_id_)
  , members_(std::move(members_))
  , invite_link_(std::move(invite_link_))
  , bot_commands_(std::move(bot_commands_))
{}

const std::int32_t basicGroupFullInfo::ID;

void basicGroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "basicGroupFullInfo");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("description", description_);
    s.store_field("creator_user_id", creator_user_id_);
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    { s.store_vector_begin("bot_commands", bot_commands_.size()); for (const auto &_value : bot_commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

botCommand::botCommand()
  : command_()
  , description_()
{}

botCommand::botCommand(string const &command_, string const &description_)
  : command_(command_)
  , description_(description_)
{}

const std::int32_t botCommand::ID;

void botCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommand");
    s.store_field("command", command_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

botCommandScopeDefault::botCommandScopeDefault() {
}

const std::int32_t botCommandScopeDefault::ID;

void botCommandScopeDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeDefault");
    s.store_class_end();
  }
}

botCommandScopeAllPrivateChats::botCommandScopeAllPrivateChats() {
}

const std::int32_t botCommandScopeAllPrivateChats::ID;

void botCommandScopeAllPrivateChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeAllPrivateChats");
    s.store_class_end();
  }
}

botCommandScopeAllGroupChats::botCommandScopeAllGroupChats() {
}

const std::int32_t botCommandScopeAllGroupChats::ID;

void botCommandScopeAllGroupChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeAllGroupChats");
    s.store_class_end();
  }
}

botCommandScopeAllChatAdministrators::botCommandScopeAllChatAdministrators() {
}

const std::int32_t botCommandScopeAllChatAdministrators::ID;

void botCommandScopeAllChatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeAllChatAdministrators");
    s.store_class_end();
  }
}

botCommandScopeChat::botCommandScopeChat()
  : chat_id_()
{}

botCommandScopeChat::botCommandScopeChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t botCommandScopeChat::ID;

void botCommandScopeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

botCommandScopeChatAdministrators::botCommandScopeChatAdministrators()
  : chat_id_()
{}

botCommandScopeChatAdministrators::botCommandScopeChatAdministrators(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t botCommandScopeChatAdministrators::ID;

void botCommandScopeChatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChatAdministrators");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

botCommandScopeChatMember::botCommandScopeChatMember()
  : chat_id_()
  , user_id_()
{}

botCommandScopeChatMember::botCommandScopeChatMember(int53 chat_id_, int53 user_id_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
{}

const std::int32_t botCommandScopeChatMember::ID;

void botCommandScopeChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

botCommands::botCommands()
  : bot_user_id_()
  , commands_()
{}

botCommands::botCommands(int53 bot_user_id_, array<object_ptr<botCommand>> &&commands_)
  : bot_user_id_(bot_user_id_)
  , commands_(std::move(commands_))
{}

const std::int32_t botCommands::ID;

void botCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommands");
    s.store_field("bot_user_id", bot_user_id_);
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

botInfo::botInfo()
  : share_text_()
  , description_()
  , menu_button_()
  , commands_()
  , default_group_administrator_rights_()
  , default_channel_administrator_rights_()
{}

botInfo::botInfo(string const &share_text_, string const &description_, object_ptr<botMenuButton> &&menu_button_, array<object_ptr<botCommand>> &&commands_, object_ptr<chatAdministratorRights> &&default_group_administrator_rights_, object_ptr<chatAdministratorRights> &&default_channel_administrator_rights_)
  : share_text_(share_text_)
  , description_(description_)
  , menu_button_(std::move(menu_button_))
  , commands_(std::move(commands_))
  , default_group_administrator_rights_(std::move(default_group_administrator_rights_))
  , default_channel_administrator_rights_(std::move(default_channel_administrator_rights_))
{}

const std::int32_t botInfo::ID;

void botInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInfo");
    s.store_field("share_text", share_text_);
    s.store_field("description", description_);
    s.store_object_field("menu_button", static_cast<const BaseObject *>(menu_button_.get()));
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("default_group_administrator_rights", static_cast<const BaseObject *>(default_group_administrator_rights_.get()));
    s.store_object_field("default_channel_administrator_rights", static_cast<const BaseObject *>(default_channel_administrator_rights_.get()));
    s.store_class_end();
  }
}

botMenuButton::botMenuButton()
  : text_()
  , url_()
{}

botMenuButton::botMenuButton(string const &text_, string const &url_)
  : text_(text_)
  , url_(url_)
{}

const std::int32_t botMenuButton::ID;

void botMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMenuButton");
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

call::call()
  : id_()
  , user_id_()
  , is_outgoing_()
  , is_video_()
  , state_()
{}

call::call(int32 id_, int53 user_id_, bool is_outgoing_, bool is_video_, object_ptr<CallState> &&state_)
  : id_(id_)
  , user_id_(user_id_)
  , is_outgoing_(is_outgoing_)
  , is_video_(is_video_)
  , state_(std::move(state_))
{}

const std::int32_t call::ID;

void call::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "call");
    s.store_field("id", id_);
    s.store_field("user_id", user_id_);
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("is_video", is_video_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

callDiscardReasonEmpty::callDiscardReasonEmpty() {
}

const std::int32_t callDiscardReasonEmpty::ID;

void callDiscardReasonEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonEmpty");
    s.store_class_end();
  }
}

callDiscardReasonMissed::callDiscardReasonMissed() {
}

const std::int32_t callDiscardReasonMissed::ID;

void callDiscardReasonMissed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonMissed");
    s.store_class_end();
  }
}

callDiscardReasonDeclined::callDiscardReasonDeclined() {
}

const std::int32_t callDiscardReasonDeclined::ID;

void callDiscardReasonDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonDeclined");
    s.store_class_end();
  }
}

callDiscardReasonDisconnected::callDiscardReasonDisconnected() {
}

const std::int32_t callDiscardReasonDisconnected::ID;

void callDiscardReasonDisconnected::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonDisconnected");
    s.store_class_end();
  }
}

callDiscardReasonHungUp::callDiscardReasonHungUp() {
}

const std::int32_t callDiscardReasonHungUp::ID;

void callDiscardReasonHungUp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonHungUp");
    s.store_class_end();
  }
}

callId::callId()
  : id_()
{}

callId::callId(int32 id_)
  : id_(id_)
{}

const std::int32_t callId::ID;

void callId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

callProblemEcho::callProblemEcho() {
}

const std::int32_t callProblemEcho::ID;

void callProblemEcho::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemEcho");
    s.store_class_end();
  }
}

callProblemNoise::callProblemNoise() {
}

const std::int32_t callProblemNoise::ID;

void callProblemNoise::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemNoise");
    s.store_class_end();
  }
}

callProblemInterruptions::callProblemInterruptions() {
}

const std::int32_t callProblemInterruptions::ID;

void callProblemInterruptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemInterruptions");
    s.store_class_end();
  }
}

callProblemDistortedSpeech::callProblemDistortedSpeech() {
}

const std::int32_t callProblemDistortedSpeech::ID;

void callProblemDistortedSpeech::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemDistortedSpeech");
    s.store_class_end();
  }
}

callProblemSilentLocal::callProblemSilentLocal() {
}

const std::int32_t callProblemSilentLocal::ID;

void callProblemSilentLocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemSilentLocal");
    s.store_class_end();
  }
}

callProblemSilentRemote::callProblemSilentRemote() {
}

const std::int32_t callProblemSilentRemote::ID;

void callProblemSilentRemote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemSilentRemote");
    s.store_class_end();
  }
}

callProblemDropped::callProblemDropped() {
}

const std::int32_t callProblemDropped::ID;

void callProblemDropped::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemDropped");
    s.store_class_end();
  }
}

callProblemDistortedVideo::callProblemDistortedVideo() {
}

const std::int32_t callProblemDistortedVideo::ID;

void callProblemDistortedVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemDistortedVideo");
    s.store_class_end();
  }
}

callProblemPixelatedVideo::callProblemPixelatedVideo() {
}

const std::int32_t callProblemPixelatedVideo::ID;

void callProblemPixelatedVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProblemPixelatedVideo");
    s.store_class_end();
  }
}

callProtocol::callProtocol()
  : udp_p2p_()
  , udp_reflector_()
  , min_layer_()
  , max_layer_()
  , library_versions_()
{}

callProtocol::callProtocol(bool udp_p2p_, bool udp_reflector_, int32 min_layer_, int32 max_layer_, array<string> &&library_versions_)
  : udp_p2p_(udp_p2p_)
  , udp_reflector_(udp_reflector_)
  , min_layer_(min_layer_)
  , max_layer_(max_layer_)
  , library_versions_(std::move(library_versions_))
{}

const std::int32_t callProtocol::ID;

void callProtocol::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProtocol");
    s.store_field("udp_p2p", udp_p2p_);
    s.store_field("udp_reflector", udp_reflector_);
    s.store_field("min_layer", min_layer_);
    s.store_field("max_layer", max_layer_);
    { s.store_vector_begin("library_versions", library_versions_.size()); for (const auto &_value : library_versions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

callServer::callServer()
  : id_()
  , ip_address_()
  , ipv6_address_()
  , port_()
  , type_()
{}

callServer::callServer(int64 id_, string const &ip_address_, string const &ipv6_address_, int32 port_, object_ptr<CallServerType> &&type_)
  : id_(id_)
  , ip_address_(ip_address_)
  , ipv6_address_(ipv6_address_)
  , port_(port_)
  , type_(std::move(type_))
{}

const std::int32_t callServer::ID;

void callServer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callServer");
    s.store_field("id", id_);
    s.store_field("ip_address", ip_address_);
    s.store_field("ipv6_address", ipv6_address_);
    s.store_field("port", port_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

callServerTypeTelegramReflector::callServerTypeTelegramReflector()
  : peer_tag_()
{}

callServerTypeTelegramReflector::callServerTypeTelegramReflector(bytes const &peer_tag_)
  : peer_tag_(std::move(peer_tag_))
{}

const std::int32_t callServerTypeTelegramReflector::ID;

void callServerTypeTelegramReflector::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callServerTypeTelegramReflector");
    s.store_bytes_field("peer_tag", peer_tag_);
    s.store_class_end();
  }
}

callServerTypeWebrtc::callServerTypeWebrtc()
  : username_()
  , password_()
  , supports_turn_()
  , supports_stun_()
{}

callServerTypeWebrtc::callServerTypeWebrtc(string const &username_, string const &password_, bool supports_turn_, bool supports_stun_)
  : username_(username_)
  , password_(password_)
  , supports_turn_(supports_turn_)
  , supports_stun_(supports_stun_)
{}

const std::int32_t callServerTypeWebrtc::ID;

void callServerTypeWebrtc::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callServerTypeWebrtc");
    s.store_field("username", username_);
    s.store_field("password", password_);
    s.store_field("supports_turn", supports_turn_);
    s.store_field("supports_stun", supports_stun_);
    s.store_class_end();
  }
}

callStatePending::callStatePending()
  : is_created_()
  , is_received_()
{}

callStatePending::callStatePending(bool is_created_, bool is_received_)
  : is_created_(is_created_)
  , is_received_(is_received_)
{}

const std::int32_t callStatePending::ID;

void callStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStatePending");
    s.store_field("is_created", is_created_);
    s.store_field("is_received", is_received_);
    s.store_class_end();
  }
}

callStateExchangingKeys::callStateExchangingKeys() {
}

const std::int32_t callStateExchangingKeys::ID;

void callStateExchangingKeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateExchangingKeys");
    s.store_class_end();
  }
}

callStateReady::callStateReady()
  : protocol_()
  , servers_()
  , config_()
  , encryption_key_()
  , emojis_()
  , allow_p2p_()
{}

callStateReady::callStateReady(object_ptr<callProtocol> &&protocol_, array<object_ptr<callServer>> &&servers_, string const &config_, bytes const &encryption_key_, array<string> &&emojis_, bool allow_p2p_)
  : protocol_(std::move(protocol_))
  , servers_(std::move(servers_))
  , config_(config_)
  , encryption_key_(std::move(encryption_key_))
  , emojis_(std::move(emojis_))
  , allow_p2p_(allow_p2p_)
{}

const std::int32_t callStateReady::ID;

void callStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateReady");
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    { s.store_vector_begin("servers", servers_.size()); for (const auto &_value : servers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("config", config_);
    s.store_bytes_field("encryption_key", encryption_key_);
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("allow_p2p", allow_p2p_);
    s.store_class_end();
  }
}

callStateHangingUp::callStateHangingUp() {
}

const std::int32_t callStateHangingUp::ID;

void callStateHangingUp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateHangingUp");
    s.store_class_end();
  }
}

callStateDiscarded::callStateDiscarded()
  : reason_()
  , need_rating_()
  , need_debug_information_()
  , need_log_()
{}

callStateDiscarded::callStateDiscarded(object_ptr<CallDiscardReason> &&reason_, bool need_rating_, bool need_debug_information_, bool need_log_)
  : reason_(std::move(reason_))
  , need_rating_(need_rating_)
  , need_debug_information_(need_debug_information_)
  , need_log_(need_log_)
{}

const std::int32_t callStateDiscarded::ID;

void callStateDiscarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateDiscarded");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("need_rating", need_rating_);
    s.store_field("need_debug_information", need_debug_information_);
    s.store_field("need_log", need_log_);
    s.store_class_end();
  }
}

callStateError::callStateError()
  : error_()
{}

callStateError::callStateError(object_ptr<error> &&error_)
  : error_(std::move(error_))
{}

const std::int32_t callStateError::ID;

void callStateError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callStateError");
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

callbackQueryAnswer::callbackQueryAnswer()
  : text_()
  , show_alert_()
  , url_()
{}

callbackQueryAnswer::callbackQueryAnswer(string const &text_, bool show_alert_, string const &url_)
  : text_(text_)
  , show_alert_(show_alert_)
  , url_(url_)
{}

const std::int32_t callbackQueryAnswer::ID;

void callbackQueryAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryAnswer");
    s.store_field("text", text_);
    s.store_field("show_alert", show_alert_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

callbackQueryPayloadData::callbackQueryPayloadData()
  : data_()
{}

callbackQueryPayloadData::callbackQueryPayloadData(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t callbackQueryPayloadData::ID;

void callbackQueryPayloadData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryPayloadData");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

callbackQueryPayloadDataWithPassword::callbackQueryPayloadDataWithPassword()
  : password_()
  , data_()
{}

callbackQueryPayloadDataWithPassword::callbackQueryPayloadDataWithPassword(string const &password_, bytes const &data_)
  : password_(password_)
  , data_(std::move(data_))
{}

const std::int32_t callbackQueryPayloadDataWithPassword::ID;

void callbackQueryPayloadDataWithPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryPayloadDataWithPassword");
    s.store_field("password", password_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

callbackQueryPayloadGame::callbackQueryPayloadGame()
  : game_short_name_()
{}

callbackQueryPayloadGame::callbackQueryPayloadGame(string const &game_short_name_)
  : game_short_name_(game_short_name_)
{}

const std::int32_t callbackQueryPayloadGame::ID;

void callbackQueryPayloadGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryPayloadGame");
    s.store_field("game_short_name", game_short_name_);
    s.store_class_end();
  }
}

canTransferOwnershipResultOk::canTransferOwnershipResultOk() {
}

const std::int32_t canTransferOwnershipResultOk::ID;

void canTransferOwnershipResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultOk");
    s.store_class_end();
  }
}

canTransferOwnershipResultPasswordNeeded::canTransferOwnershipResultPasswordNeeded() {
}

const std::int32_t canTransferOwnershipResultPasswordNeeded::ID;

void canTransferOwnershipResultPasswordNeeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultPasswordNeeded");
    s.store_class_end();
  }
}

canTransferOwnershipResultPasswordTooFresh::canTransferOwnershipResultPasswordTooFresh()
  : retry_after_()
{}

canTransferOwnershipResultPasswordTooFresh::canTransferOwnershipResultPasswordTooFresh(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t canTransferOwnershipResultPasswordTooFresh::ID;

void canTransferOwnershipResultPasswordTooFresh::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultPasswordTooFresh");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

canTransferOwnershipResultSessionTooFresh::canTransferOwnershipResultSessionTooFresh()
  : retry_after_()
{}

canTransferOwnershipResultSessionTooFresh::canTransferOwnershipResultSessionTooFresh(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t canTransferOwnershipResultSessionTooFresh::ID;

void canTransferOwnershipResultSessionTooFresh::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnershipResultSessionTooFresh");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

chat::chat()
  : id_()
  , type_()
  , title_()
  , photo_()
  , permissions_()
  , last_message_()
  , positions_()
  , message_sender_id_()
  , has_protected_content_()
  , is_marked_as_unread_()
  , is_blocked_()
  , has_scheduled_messages_()
  , can_be_deleted_only_for_self_()
  , can_be_deleted_for_all_users_()
  , can_be_reported_()
  , default_disable_notification_()
  , unread_count_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , unread_mention_count_()
  , unread_reaction_count_()
  , notification_settings_()
  , available_reactions_()
  , message_ttl_()
  , theme_name_()
  , action_bar_()
  , video_chat_()
  , pending_join_requests_()
  , reply_markup_message_id_()
  , draft_message_()
  , client_data_()
{}

chat::chat(int53 id_, object_ptr<ChatType> &&type_, string const &title_, object_ptr<chatPhotoInfo> &&photo_, object_ptr<chatPermissions> &&permissions_, object_ptr<message> &&last_message_, array<object_ptr<chatPosition>> &&positions_, object_ptr<MessageSender> &&message_sender_id_, bool has_protected_content_, bool is_marked_as_unread_, bool is_blocked_, bool has_scheduled_messages_, bool can_be_deleted_only_for_self_, bool can_be_deleted_for_all_users_, bool can_be_reported_, bool default_disable_notification_, int32 unread_count_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int32 unread_mention_count_, int32 unread_reaction_count_, object_ptr<chatNotificationSettings> &&notification_settings_, array<string> &&available_reactions_, int32 message_ttl_, string const &theme_name_, object_ptr<ChatActionBar> &&action_bar_, object_ptr<videoChat> &&video_chat_, object_ptr<chatJoinRequestsInfo> &&pending_join_requests_, int53 reply_markup_message_id_, object_ptr<draftMessage> &&draft_message_, string const &client_data_)
  : id_(id_)
  , type_(std::move(type_))
  , title_(title_)
  , photo_(std::move(photo_))
  , permissions_(std::move(permissions_))
  , last_message_(std::move(last_message_))
  , positions_(std::move(positions_))
  , message_sender_id_(std::move(message_sender_id_))
  , has_protected_content_(has_protected_content_)
  , is_marked_as_unread_(is_marked_as_unread_)
  , is_blocked_(is_blocked_)
  , has_scheduled_messages_(has_scheduled_messages_)
  , can_be_deleted_only_for_self_(can_be_deleted_only_for_self_)
  , can_be_deleted_for_all_users_(can_be_deleted_for_all_users_)
  , can_be_reported_(can_be_reported_)
  , default_disable_notification_(default_disable_notification_)
  , unread_count_(unread_count_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , unread_mention_count_(unread_mention_count_)
  , unread_reaction_count_(unread_reaction_count_)
  , notification_settings_(std::move(notification_settings_))
  , available_reactions_(std::move(available_reactions_))
  , message_ttl_(message_ttl_)
  , theme_name_(theme_name_)
  , action_bar_(std::move(action_bar_))
  , video_chat_(std::move(video_chat_))
  , pending_join_requests_(std::move(pending_join_requests_))
  , reply_markup_message_id_(reply_markup_message_id_)
  , draft_message_(std::move(draft_message_))
  , client_data_(client_data_)
{}

const std::int32_t chat::ID;

void chat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chat");
    s.store_field("id", id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    s.store_field("has_protected_content", has_protected_content_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_field("is_blocked", is_blocked_);
    s.store_field("has_scheduled_messages", has_scheduled_messages_);
    s.store_field("can_be_deleted_only_for_self", can_be_deleted_only_for_self_);
    s.store_field("can_be_deleted_for_all_users", can_be_deleted_for_all_users_);
    s.store_field("can_be_reported", can_be_reported_);
    s.store_field("default_disable_notification", default_disable_notification_);
    s.store_field("unread_count", unread_count_);
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    { s.store_vector_begin("available_reactions", available_reactions_.size()); for (const auto &_value : available_reactions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("message_ttl", message_ttl_);
    s.store_field("theme_name", theme_name_);
    s.store_object_field("action_bar", static_cast<const BaseObject *>(action_bar_.get()));
    s.store_object_field("video_chat", static_cast<const BaseObject *>(video_chat_.get()));
    s.store_object_field("pending_join_requests", static_cast<const BaseObject *>(pending_join_requests_.get()));
    s.store_field("reply_markup_message_id", reply_markup_message_id_);
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_field("client_data", client_data_);
    s.store_class_end();
  }
}

chatActionTyping::chatActionTyping() {
}

const std::int32_t chatActionTyping::ID;

void chatActionTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionTyping");
    s.store_class_end();
  }
}

chatActionRecordingVideo::chatActionRecordingVideo() {
}

const std::int32_t chatActionRecordingVideo::ID;

void chatActionRecordingVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionRecordingVideo");
    s.store_class_end();
  }
}

chatActionUploadingVideo::chatActionUploadingVideo()
  : progress_()
{}

chatActionUploadingVideo::chatActionUploadingVideo(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingVideo::ID;

void chatActionUploadingVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingVideo");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionRecordingVoiceNote::chatActionRecordingVoiceNote() {
}

const std::int32_t chatActionRecordingVoiceNote::ID;

void chatActionRecordingVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionRecordingVoiceNote");
    s.store_class_end();
  }
}

chatActionUploadingVoiceNote::chatActionUploadingVoiceNote()
  : progress_()
{}

chatActionUploadingVoiceNote::chatActionUploadingVoiceNote(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingVoiceNote::ID;

void chatActionUploadingVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingVoiceNote");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionUploadingPhoto::chatActionUploadingPhoto()
  : progress_()
{}

chatActionUploadingPhoto::chatActionUploadingPhoto(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingPhoto::ID;

void chatActionUploadingPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingPhoto");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionUploadingDocument::chatActionUploadingDocument()
  : progress_()
{}

chatActionUploadingDocument::chatActionUploadingDocument(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingDocument::ID;

void chatActionUploadingDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingDocument");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionChoosingSticker::chatActionChoosingSticker() {
}

const std::int32_t chatActionChoosingSticker::ID;

void chatActionChoosingSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionChoosingSticker");
    s.store_class_end();
  }
}

chatActionChoosingLocation::chatActionChoosingLocation() {
}

const std::int32_t chatActionChoosingLocation::ID;

void chatActionChoosingLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionChoosingLocation");
    s.store_class_end();
  }
}

chatActionChoosingContact::chatActionChoosingContact() {
}

const std::int32_t chatActionChoosingContact::ID;

void chatActionChoosingContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionChoosingContact");
    s.store_class_end();
  }
}

chatActionStartPlayingGame::chatActionStartPlayingGame() {
}

const std::int32_t chatActionStartPlayingGame::ID;

void chatActionStartPlayingGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionStartPlayingGame");
    s.store_class_end();
  }
}

chatActionRecordingVideoNote::chatActionRecordingVideoNote() {
}

const std::int32_t chatActionRecordingVideoNote::ID;

void chatActionRecordingVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionRecordingVideoNote");
    s.store_class_end();
  }
}

chatActionUploadingVideoNote::chatActionUploadingVideoNote()
  : progress_()
{}

chatActionUploadingVideoNote::chatActionUploadingVideoNote(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingVideoNote::ID;

void chatActionUploadingVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingVideoNote");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionWatchingAnimations::chatActionWatchingAnimations()
  : emoji_()
{}

chatActionWatchingAnimations::chatActionWatchingAnimations(string const &emoji_)
  : emoji_(emoji_)
{}

const std::int32_t chatActionWatchingAnimations::ID;

void chatActionWatchingAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionWatchingAnimations");
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

chatActionCancel::chatActionCancel() {
}

const std::int32_t chatActionCancel::ID;

void chatActionCancel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionCancel");
    s.store_class_end();
  }
}

chatActionBarReportSpam::chatActionBarReportSpam()
  : can_unarchive_()
{}

chatActionBarReportSpam::chatActionBarReportSpam(bool can_unarchive_)
  : can_unarchive_(can_unarchive_)
{}

const std::int32_t chatActionBarReportSpam::ID;

void chatActionBarReportSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarReportSpam");
    s.store_field("can_unarchive", can_unarchive_);
    s.store_class_end();
  }
}

chatActionBarReportUnrelatedLocation::chatActionBarReportUnrelatedLocation() {
}

const std::int32_t chatActionBarReportUnrelatedLocation::ID;

void chatActionBarReportUnrelatedLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarReportUnrelatedLocation");
    s.store_class_end();
  }
}

chatActionBarInviteMembers::chatActionBarInviteMembers() {
}

const std::int32_t chatActionBarInviteMembers::ID;

void chatActionBarInviteMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarInviteMembers");
    s.store_class_end();
  }
}

chatActionBarReportAddBlock::chatActionBarReportAddBlock()
  : can_unarchive_()
  , distance_()
{}

chatActionBarReportAddBlock::chatActionBarReportAddBlock(bool can_unarchive_, int32 distance_)
  : can_unarchive_(can_unarchive_)
  , distance_(distance_)
{}

const std::int32_t chatActionBarReportAddBlock::ID;

void chatActionBarReportAddBlock::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarReportAddBlock");
    s.store_field("can_unarchive", can_unarchive_);
    s.store_field("distance", distance_);
    s.store_class_end();
  }
}

chatActionBarAddContact::chatActionBarAddContact() {
}

const std::int32_t chatActionBarAddContact::ID;

void chatActionBarAddContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarAddContact");
    s.store_class_end();
  }
}

chatActionBarSharePhoneNumber::chatActionBarSharePhoneNumber() {
}

const std::int32_t chatActionBarSharePhoneNumber::ID;

void chatActionBarSharePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarSharePhoneNumber");
    s.store_class_end();
  }
}

chatActionBarJoinRequest::chatActionBarJoinRequest()
  : title_()
  , is_channel_()
  , request_date_()
{}

chatActionBarJoinRequest::chatActionBarJoinRequest(string const &title_, bool is_channel_, int32 request_date_)
  : title_(title_)
  , is_channel_(is_channel_)
  , request_date_(request_date_)
{}

const std::int32_t chatActionBarJoinRequest::ID;

void chatActionBarJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionBarJoinRequest");
    s.store_field("title", title_);
    s.store_field("is_channel", is_channel_);
    s.store_field("request_date", request_date_);
    s.store_class_end();
  }
}

chatAdministrator::chatAdministrator()
  : user_id_()
  , custom_title_()
  , is_owner_()
{}

chatAdministrator::chatAdministrator(int53 user_id_, string const &custom_title_, bool is_owner_)
  : user_id_(user_id_)
  , custom_title_(custom_title_)
  , is_owner_(is_owner_)
{}

const std::int32_t chatAdministrator::ID;

void chatAdministrator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdministrator");
    s.store_field("user_id", user_id_);
    s.store_field("custom_title", custom_title_);
    s.store_field("is_owner", is_owner_);
    s.store_class_end();
  }
}

chatAdministratorRights::chatAdministratorRights()
  : can_manage_chat_()
  , can_change_info_()
  , can_post_messages_()
  , can_edit_messages_()
  , can_delete_messages_()
  , can_invite_users_()
  , can_restrict_members_()
  , can_pin_messages_()
  , can_promote_members_()
  , can_manage_video_chats_()
  , is_anonymous_()
{}

chatAdministratorRights::chatAdministratorRights(bool can_manage_chat_, bool can_change_info_, bool can_post_messages_, bool can_edit_messages_, bool can_delete_messages_, bool can_invite_users_, bool can_restrict_members_, bool can_pin_messages_, bool can_promote_members_, bool can_manage_video_chats_, bool is_anonymous_)
  : can_manage_chat_(can_manage_chat_)
  , can_change_info_(can_change_info_)
  , can_post_messages_(can_post_messages_)
  , can_edit_messages_(can_edit_messages_)
  , can_delete_messages_(can_delete_messages_)
  , can_invite_users_(can_invite_users_)
  , can_restrict_members_(can_restrict_members_)
  , can_pin_messages_(can_pin_messages_)
  , can_promote_members_(can_promote_members_)
  , can_manage_video_chats_(can_manage_video_chats_)
  , is_anonymous_(is_anonymous_)
{}

const std::int32_t chatAdministratorRights::ID;

void chatAdministratorRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdministratorRights");
    s.store_field("can_manage_chat", can_manage_chat_);
    s.store_field("can_change_info", can_change_info_);
    s.store_field("can_post_messages", can_post_messages_);
    s.store_field("can_edit_messages", can_edit_messages_);
    s.store_field("can_delete_messages", can_delete_messages_);
    s.store_field("can_invite_users", can_invite_users_);
    s.store_field("can_restrict_members", can_restrict_members_);
    s.store_field("can_pin_messages", can_pin_messages_);
    s.store_field("can_promote_members", can_promote_members_);
    s.store_field("can_manage_video_chats", can_manage_video_chats_);
    s.store_field("is_anonymous", is_anonymous_);
    s.store_class_end();
  }
}

chatAdministrators::chatAdministrators()
  : administrators_()
{}

chatAdministrators::chatAdministrators(array<object_ptr<chatAdministrator>> &&administrators_)
  : administrators_(std::move(administrators_))
{}

const std::int32_t chatAdministrators::ID;

void chatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdministrators");
    { s.store_vector_begin("administrators", administrators_.size()); for (const auto &_value : administrators_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatEvent::chatEvent()
  : id_()
  , date_()
  , member_id_()
  , action_()
{}

chatEvent::chatEvent(int64 id_, int32 date_, object_ptr<MessageSender> &&member_id_, object_ptr<ChatEventAction> &&action_)
  : id_(id_)
  , date_(date_)
  , member_id_(std::move(member_id_))
  , action_(std::move(action_))
{}

const std::int32_t chatEvent::ID;

void chatEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEvent");
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

chatEventMessageEdited::chatEventMessageEdited()
  : old_message_()
  , new_message_()
{}

chatEventMessageEdited::chatEventMessageEdited(object_ptr<message> &&old_message_, object_ptr<message> &&new_message_)
  : old_message_(std::move(old_message_))
  , new_message_(std::move(new_message_))
{}

const std::int32_t chatEventMessageEdited::ID;

void chatEventMessageEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageEdited");
    s.store_object_field("old_message", static_cast<const BaseObject *>(old_message_.get()));
    s.store_object_field("new_message", static_cast<const BaseObject *>(new_message_.get()));
    s.store_class_end();
  }
}

chatEventMessageDeleted::chatEventMessageDeleted()
  : message_()
{}

chatEventMessageDeleted::chatEventMessageDeleted(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t chatEventMessageDeleted::ID;

void chatEventMessageDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageDeleted");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

chatEventMessagePinned::chatEventMessagePinned()
  : message_()
{}

chatEventMessagePinned::chatEventMessagePinned(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t chatEventMessagePinned::ID;

void chatEventMessagePinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessagePinned");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

chatEventMessageUnpinned::chatEventMessageUnpinned()
  : message_()
{}

chatEventMessageUnpinned::chatEventMessageUnpinned(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t chatEventMessageUnpinned::ID;

void chatEventMessageUnpinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageUnpinned");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

chatEventPollStopped::chatEventPollStopped()
  : message_()
{}

chatEventPollStopped::chatEventPollStopped(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t chatEventPollStopped::ID;

void chatEventPollStopped::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventPollStopped");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

chatEventMemberJoined::chatEventMemberJoined() {
}

const std::int32_t chatEventMemberJoined::ID;

void chatEventMemberJoined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberJoined");
    s.store_class_end();
  }
}

chatEventMemberJoinedByInviteLink::chatEventMemberJoinedByInviteLink()
  : invite_link_()
{}

chatEventMemberJoinedByInviteLink::chatEventMemberJoinedByInviteLink(object_ptr<chatInviteLink> &&invite_link_)
  : invite_link_(std::move(invite_link_))
{}

const std::int32_t chatEventMemberJoinedByInviteLink::ID;

void chatEventMemberJoinedByInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberJoinedByInviteLink");
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

chatEventMemberJoinedByRequest::chatEventMemberJoinedByRequest()
  : approver_user_id_()
  , invite_link_()
{}

chatEventMemberJoinedByRequest::chatEventMemberJoinedByRequest(int53 approver_user_id_, object_ptr<chatInviteLink> &&invite_link_)
  : approver_user_id_(approver_user_id_)
  , invite_link_(std::move(invite_link_))
{}

const std::int32_t chatEventMemberJoinedByRequest::ID;

void chatEventMemberJoinedByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberJoinedByRequest");
    s.store_field("approver_user_id", approver_user_id_);
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

chatEventMemberInvited::chatEventMemberInvited()
  : user_id_()
  , status_()
{}

chatEventMemberInvited::chatEventMemberInvited(int53 user_id_, object_ptr<ChatMemberStatus> &&status_)
  : user_id_(user_id_)
  , status_(std::move(status_))
{}

const std::int32_t chatEventMemberInvited::ID;

void chatEventMemberInvited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberInvited");
    s.store_field("user_id", user_id_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

chatEventMemberLeft::chatEventMemberLeft() {
}

const std::int32_t chatEventMemberLeft::ID;

void chatEventMemberLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberLeft");
    s.store_class_end();
  }
}

chatEventMemberPromoted::chatEventMemberPromoted()
  : user_id_()
  , old_status_()
  , new_status_()
{}

chatEventMemberPromoted::chatEventMemberPromoted(int53 user_id_, object_ptr<ChatMemberStatus> &&old_status_, object_ptr<ChatMemberStatus> &&new_status_)
  : user_id_(user_id_)
  , old_status_(std::move(old_status_))
  , new_status_(std::move(new_status_))
{}

const std::int32_t chatEventMemberPromoted::ID;

void chatEventMemberPromoted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberPromoted");
    s.store_field("user_id", user_id_);
    s.store_object_field("old_status", static_cast<const BaseObject *>(old_status_.get()));
    s.store_object_field("new_status", static_cast<const BaseObject *>(new_status_.get()));
    s.store_class_end();
  }
}

chatEventMemberRestricted::chatEventMemberRestricted()
  : member_id_()
  , old_status_()
  , new_status_()
{}

chatEventMemberRestricted::chatEventMemberRestricted(object_ptr<MessageSender> &&member_id_, object_ptr<ChatMemberStatus> &&old_status_, object_ptr<ChatMemberStatus> &&new_status_)
  : member_id_(std::move(member_id_))
  , old_status_(std::move(old_status_))
  , new_status_(std::move(new_status_))
{}

const std::int32_t chatEventMemberRestricted::ID;

void chatEventMemberRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberRestricted");
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_object_field("old_status", static_cast<const BaseObject *>(old_status_.get()));
    s.store_object_field("new_status", static_cast<const BaseObject *>(new_status_.get()));
    s.store_class_end();
  }
}

chatEventAvailableReactionsChanged::chatEventAvailableReactionsChanged()
  : old_available_reactions_()
  , new_available_reactions_()
{}

chatEventAvailableReactionsChanged::chatEventAvailableReactionsChanged(array<string> &&old_available_reactions_, array<string> &&new_available_reactions_)
  : old_available_reactions_(std::move(old_available_reactions_))
  , new_available_reactions_(std::move(new_available_reactions_))
{}

const std::int32_t chatEventAvailableReactionsChanged::ID;

void chatEventAvailableReactionsChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventAvailableReactionsChanged");
    { s.store_vector_begin("old_available_reactions", old_available_reactions_.size()); for (const auto &_value : old_available_reactions_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("new_available_reactions", new_available_reactions_.size()); for (const auto &_value : new_available_reactions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatEventDescriptionChanged::chatEventDescriptionChanged()
  : old_description_()
  , new_description_()
{}

chatEventDescriptionChanged::chatEventDescriptionChanged(string const &old_description_, string const &new_description_)
  : old_description_(old_description_)
  , new_description_(new_description_)
{}

const std::int32_t chatEventDescriptionChanged::ID;

void chatEventDescriptionChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventDescriptionChanged");
    s.store_field("old_description", old_description_);
    s.store_field("new_description", new_description_);
    s.store_class_end();
  }
}

chatEventLinkedChatChanged::chatEventLinkedChatChanged()
  : old_linked_chat_id_()
  , new_linked_chat_id_()
{}

chatEventLinkedChatChanged::chatEventLinkedChatChanged(int53 old_linked_chat_id_, int53 new_linked_chat_id_)
  : old_linked_chat_id_(old_linked_chat_id_)
  , new_linked_chat_id_(new_linked_chat_id_)
{}

const std::int32_t chatEventLinkedChatChanged::ID;

void chatEventLinkedChatChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventLinkedChatChanged");
    s.store_field("old_linked_chat_id", old_linked_chat_id_);
    s.store_field("new_linked_chat_id", new_linked_chat_id_);
    s.store_class_end();
  }
}

chatEventLocationChanged::chatEventLocationChanged()
  : old_location_()
  , new_location_()
{}

chatEventLocationChanged::chatEventLocationChanged(object_ptr<chatLocation> &&old_location_, object_ptr<chatLocation> &&new_location_)
  : old_location_(std::move(old_location_))
  , new_location_(std::move(new_location_))
{}

const std::int32_t chatEventLocationChanged::ID;

void chatEventLocationChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventLocationChanged");
    s.store_object_field("old_location", static_cast<const BaseObject *>(old_location_.get()));
    s.store_object_field("new_location", static_cast<const BaseObject *>(new_location_.get()));
    s.store_class_end();
  }
}

chatEventMessageTtlChanged::chatEventMessageTtlChanged()
  : old_message_ttl_()
  , new_message_ttl_()
{}

chatEventMessageTtlChanged::chatEventMessageTtlChanged(int32 old_message_ttl_, int32 new_message_ttl_)
  : old_message_ttl_(old_message_ttl_)
  , new_message_ttl_(new_message_ttl_)
{}

const std::int32_t chatEventMessageTtlChanged::ID;

void chatEventMessageTtlChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageTtlChanged");
    s.store_field("old_message_ttl", old_message_ttl_);
    s.store_field("new_message_ttl", new_message_ttl_);
    s.store_class_end();
  }
}

chatEventPermissionsChanged::chatEventPermissionsChanged()
  : old_permissions_()
  , new_permissions_()
{}

chatEventPermissionsChanged::chatEventPermissionsChanged(object_ptr<chatPermissions> &&old_permissions_, object_ptr<chatPermissions> &&new_permissions_)
  : old_permissions_(std::move(old_permissions_))
  , new_permissions_(std::move(new_permissions_))
{}

const std::int32_t chatEventPermissionsChanged::ID;

void chatEventPermissionsChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventPermissionsChanged");
    s.store_object_field("old_permissions", static_cast<const BaseObject *>(old_permissions_.get()));
    s.store_object_field("new_permissions", static_cast<const BaseObject *>(new_permissions_.get()));
    s.store_class_end();
  }
}

chatEventPhotoChanged::chatEventPhotoChanged()
  : old_photo_()
  , new_photo_()
{}

chatEventPhotoChanged::chatEventPhotoChanged(object_ptr<chatPhoto> &&old_photo_, object_ptr<chatPhoto> &&new_photo_)
  : old_photo_(std::move(old_photo_))
  , new_photo_(std::move(new_photo_))
{}

const std::int32_t chatEventPhotoChanged::ID;

void chatEventPhotoChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventPhotoChanged");
    s.store_object_field("old_photo", static_cast<const BaseObject *>(old_photo_.get()));
    s.store_object_field("new_photo", static_cast<const BaseObject *>(new_photo_.get()));
    s.store_class_end();
  }
}

chatEventSlowModeDelayChanged::chatEventSlowModeDelayChanged()
  : old_slow_mode_delay_()
  , new_slow_mode_delay_()
{}

chatEventSlowModeDelayChanged::chatEventSlowModeDelayChanged(int32 old_slow_mode_delay_, int32 new_slow_mode_delay_)
  : old_slow_mode_delay_(old_slow_mode_delay_)
  , new_slow_mode_delay_(new_slow_mode_delay_)
{}

const std::int32_t chatEventSlowModeDelayChanged::ID;

void chatEventSlowModeDelayChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventSlowModeDelayChanged");
    s.store_field("old_slow_mode_delay", old_slow_mode_delay_);
    s.store_field("new_slow_mode_delay", new_slow_mode_delay_);
    s.store_class_end();
  }
}

chatEventStickerSetChanged::chatEventStickerSetChanged()
  : old_sticker_set_id_()
  , new_sticker_set_id_()
{}

chatEventStickerSetChanged::chatEventStickerSetChanged(int64 old_sticker_set_id_, int64 new_sticker_set_id_)
  : old_sticker_set_id_(old_sticker_set_id_)
  , new_sticker_set_id_(new_sticker_set_id_)
{}

const std::int32_t chatEventStickerSetChanged::ID;

void chatEventStickerSetChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventStickerSetChanged");
    s.store_field("old_sticker_set_id", old_sticker_set_id_);
    s.store_field("new_sticker_set_id", new_sticker_set_id_);
    s.store_class_end();
  }
}

chatEventTitleChanged::chatEventTitleChanged()
  : old_title_()
  , new_title_()
{}

chatEventTitleChanged::chatEventTitleChanged(string const &old_title_, string const &new_title_)
  : old_title_(old_title_)
  , new_title_(new_title_)
{}

const std::int32_t chatEventTitleChanged::ID;

void chatEventTitleChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventTitleChanged");
    s.store_field("old_title", old_title_);
    s.store_field("new_title", new_title_);
    s.store_class_end();
  }
}

chatEventUsernameChanged::chatEventUsernameChanged()
  : old_username_()
  , new_username_()
{}

chatEventUsernameChanged::chatEventUsernameChanged(string const &old_username_, string const &new_username_)
  : old_username_(old_username_)
  , new_username_(new_username_)
{}

const std::int32_t chatEventUsernameChanged::ID;

void chatEventUsernameChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventUsernameChanged");
    s.store_field("old_username", old_username_);
    s.store_field("new_username", new_username_);
    s.store_class_end();
  }
}

chatEventHasProtectedContentToggled::chatEventHasProtectedContentToggled()
  : has_protected_content_()
{}

chatEventHasProtectedContentToggled::chatEventHasProtectedContentToggled(bool has_protected_content_)
  : has_protected_content_(has_protected_content_)
{}

const std::int32_t chatEventHasProtectedContentToggled::ID;

void chatEventHasProtectedContentToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventHasProtectedContentToggled");
    s.store_field("has_protected_content", has_protected_content_);
    s.store_class_end();
  }
}

chatEventInvitesToggled::chatEventInvitesToggled()
  : can_invite_users_()
{}

chatEventInvitesToggled::chatEventInvitesToggled(bool can_invite_users_)
  : can_invite_users_(can_invite_users_)
{}

const std::int32_t chatEventInvitesToggled::ID;

void chatEventInvitesToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInvitesToggled");
    s.store_field("can_invite_users", can_invite_users_);
    s.store_class_end();
  }
}

chatEventIsAllHistoryAvailableToggled::chatEventIsAllHistoryAvailableToggled()
  : is_all_history_available_()
{}

chatEventIsAllHistoryAvailableToggled::chatEventIsAllHistoryAvailableToggled(bool is_all_history_available_)
  : is_all_history_available_(is_all_history_available_)
{}

const std::int32_t chatEventIsAllHistoryAvailableToggled::ID;

void chatEventIsAllHistoryAvailableToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventIsAllHistoryAvailableToggled");
    s.store_field("is_all_history_available", is_all_history_available_);
    s.store_class_end();
  }
}

chatEventSignMessagesToggled::chatEventSignMessagesToggled()
  : sign_messages_()
{}

chatEventSignMessagesToggled::chatEventSignMessagesToggled(bool sign_messages_)
  : sign_messages_(sign_messages_)
{}

const std::int32_t chatEventSignMessagesToggled::ID;

void chatEventSignMessagesToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventSignMessagesToggled");
    s.store_field("sign_messages", sign_messages_);
    s.store_class_end();
  }
}

chatEventInviteLinkEdited::chatEventInviteLinkEdited()
  : old_invite_link_()
  , new_invite_link_()
{}

chatEventInviteLinkEdited::chatEventInviteLinkEdited(object_ptr<chatInviteLink> &&old_invite_link_, object_ptr<chatInviteLink> &&new_invite_link_)
  : old_invite_link_(std::move(old_invite_link_))
  , new_invite_link_(std::move(new_invite_link_))
{}

const std::int32_t chatEventInviteLinkEdited::ID;

void chatEventInviteLinkEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInviteLinkEdited");
    s.store_object_field("old_invite_link", static_cast<const BaseObject *>(old_invite_link_.get()));
    s.store_object_field("new_invite_link", static_cast<const BaseObject *>(new_invite_link_.get()));
    s.store_class_end();
  }
}

chatEventInviteLinkRevoked::chatEventInviteLinkRevoked()
  : invite_link_()
{}

chatEventInviteLinkRevoked::chatEventInviteLinkRevoked(object_ptr<chatInviteLink> &&invite_link_)
  : invite_link_(std::move(invite_link_))
{}

const std::int32_t chatEventInviteLinkRevoked::ID;

void chatEventInviteLinkRevoked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInviteLinkRevoked");
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

chatEventInviteLinkDeleted::chatEventInviteLinkDeleted()
  : invite_link_()
{}

chatEventInviteLinkDeleted::chatEventInviteLinkDeleted(object_ptr<chatInviteLink> &&invite_link_)
  : invite_link_(std::move(invite_link_))
{}

const std::int32_t chatEventInviteLinkDeleted::ID;

void chatEventInviteLinkDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInviteLinkDeleted");
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

chatEventVideoChatCreated::chatEventVideoChatCreated()
  : group_call_id_()
{}

chatEventVideoChatCreated::chatEventVideoChatCreated(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t chatEventVideoChatCreated::ID;

void chatEventVideoChatCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatCreated");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

chatEventVideoChatEnded::chatEventVideoChatEnded()
  : group_call_id_()
{}

chatEventVideoChatEnded::chatEventVideoChatEnded(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t chatEventVideoChatEnded::ID;

void chatEventVideoChatEnded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatEnded");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

chatEventVideoChatMuteNewParticipantsToggled::chatEventVideoChatMuteNewParticipantsToggled()
  : mute_new_participants_()
{}

chatEventVideoChatMuteNewParticipantsToggled::chatEventVideoChatMuteNewParticipantsToggled(bool mute_new_participants_)
  : mute_new_participants_(mute_new_participants_)
{}

const std::int32_t chatEventVideoChatMuteNewParticipantsToggled::ID;

void chatEventVideoChatMuteNewParticipantsToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatMuteNewParticipantsToggled");
    s.store_field("mute_new_participants", mute_new_participants_);
    s.store_class_end();
  }
}

chatEventVideoChatParticipantIsMutedToggled::chatEventVideoChatParticipantIsMutedToggled()
  : participant_id_()
  , is_muted_()
{}

chatEventVideoChatParticipantIsMutedToggled::chatEventVideoChatParticipantIsMutedToggled(object_ptr<MessageSender> &&participant_id_, bool is_muted_)
  : participant_id_(std::move(participant_id_))
  , is_muted_(is_muted_)
{}

const std::int32_t chatEventVideoChatParticipantIsMutedToggled::ID;

void chatEventVideoChatParticipantIsMutedToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatParticipantIsMutedToggled");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_muted", is_muted_);
    s.store_class_end();
  }
}

chatEventVideoChatParticipantVolumeLevelChanged::chatEventVideoChatParticipantVolumeLevelChanged()
  : participant_id_()
  , volume_level_()
{}

chatEventVideoChatParticipantVolumeLevelChanged::chatEventVideoChatParticipantVolumeLevelChanged(object_ptr<MessageSender> &&participant_id_, int32 volume_level_)
  : participant_id_(std::move(participant_id_))
  , volume_level_(volume_level_)
{}

const std::int32_t chatEventVideoChatParticipantVolumeLevelChanged::ID;

void chatEventVideoChatParticipantVolumeLevelChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatParticipantVolumeLevelChanged");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("volume_level", volume_level_);
    s.store_class_end();
  }
}

chatEventLogFilters::chatEventLogFilters()
  : message_edits_()
  , message_deletions_()
  , message_pins_()
  , member_joins_()
  , member_leaves_()
  , member_invites_()
  , member_promotions_()
  , member_restrictions_()
  , info_changes_()
  , setting_changes_()
  , invite_link_changes_()
  , video_chat_changes_()
{}

chatEventLogFilters::chatEventLogFilters(bool message_edits_, bool message_deletions_, bool message_pins_, bool member_joins_, bool member_leaves_, bool member_invites_, bool member_promotions_, bool member_restrictions_, bool info_changes_, bool setting_changes_, bool invite_link_changes_, bool video_chat_changes_)
  : message_edits_(message_edits_)
  , message_deletions_(message_deletions_)
  , message_pins_(message_pins_)
  , member_joins_(member_joins_)
  , member_leaves_(member_leaves_)
  , member_invites_(member_invites_)
  , member_promotions_(member_promotions_)
  , member_restrictions_(member_restrictions_)
  , info_changes_(info_changes_)
  , setting_changes_(setting_changes_)
  , invite_link_changes_(invite_link_changes_)
  , video_chat_changes_(video_chat_changes_)
{}

const std::int32_t chatEventLogFilters::ID;

void chatEventLogFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventLogFilters");
    s.store_field("message_edits", message_edits_);
    s.store_field("message_deletions", message_deletions_);
    s.store_field("message_pins", message_pins_);
    s.store_field("member_joins", member_joins_);
    s.store_field("member_leaves", member_leaves_);
    s.store_field("member_invites", member_invites_);
    s.store_field("member_promotions", member_promotions_);
    s.store_field("member_restrictions", member_restrictions_);
    s.store_field("info_changes", info_changes_);
    s.store_field("setting_changes", setting_changes_);
    s.store_field("invite_link_changes", invite_link_changes_);
    s.store_field("video_chat_changes", video_chat_changes_);
    s.store_class_end();
  }
}

chatEvents::chatEvents()
  : events_()
{}

chatEvents::chatEvents(array<object_ptr<chatEvent>> &&events_)
  : events_(std::move(events_))
{}

const std::int32_t chatEvents::ID;

void chatEvents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEvents");
    { s.store_vector_begin("events", events_.size()); for (const auto &_value : events_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatFilter::chatFilter()
  : title_()
  , icon_name_()
  , pinned_chat_ids_()
  , included_chat_ids_()
  , excluded_chat_ids_()
  , exclude_muted_()
  , exclude_read_()
  , exclude_archived_()
  , include_contacts_()
  , include_non_contacts_()
  , include_bots_()
  , include_groups_()
  , include_channels_()
{}

chatFilter::chatFilter(string const &title_, string const &icon_name_, array<int53> &&pinned_chat_ids_, array<int53> &&included_chat_ids_, array<int53> &&excluded_chat_ids_, bool exclude_muted_, bool exclude_read_, bool exclude_archived_, bool include_contacts_, bool include_non_contacts_, bool include_bots_, bool include_groups_, bool include_channels_)
  : title_(title_)
  , icon_name_(icon_name_)
  , pinned_chat_ids_(std::move(pinned_chat_ids_))
  , included_chat_ids_(std::move(included_chat_ids_))
  , excluded_chat_ids_(std::move(excluded_chat_ids_))
  , exclude_muted_(exclude_muted_)
  , exclude_read_(exclude_read_)
  , exclude_archived_(exclude_archived_)
  , include_contacts_(include_contacts_)
  , include_non_contacts_(include_non_contacts_)
  , include_bots_(include_bots_)
  , include_groups_(include_groups_)
  , include_channels_(include_channels_)
{}

const std::int32_t chatFilter::ID;

void chatFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFilter");
    s.store_field("title", title_);
    s.store_field("icon_name", icon_name_);
    { s.store_vector_begin("pinned_chat_ids", pinned_chat_ids_.size()); for (const auto &_value : pinned_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("included_chat_ids", included_chat_ids_.size()); for (const auto &_value : included_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("excluded_chat_ids", excluded_chat_ids_.size()); for (const auto &_value : excluded_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("exclude_muted", exclude_muted_);
    s.store_field("exclude_read", exclude_read_);
    s.store_field("exclude_archived", exclude_archived_);
    s.store_field("include_contacts", include_contacts_);
    s.store_field("include_non_contacts", include_non_contacts_);
    s.store_field("include_bots", include_bots_);
    s.store_field("include_groups", include_groups_);
    s.store_field("include_channels", include_channels_);
    s.store_class_end();
  }
}

chatFilterInfo::chatFilterInfo()
  : id_()
  , title_()
  , icon_name_()
{}

chatFilterInfo::chatFilterInfo(int32 id_, string const &title_, string const &icon_name_)
  : id_(id_)
  , title_(title_)
  , icon_name_(icon_name_)
{}

const std::int32_t chatFilterInfo::ID;

void chatFilterInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFilterInfo");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("icon_name", icon_name_);
    s.store_class_end();
  }
}

chatInviteLink::chatInviteLink()
  : invite_link_()
  , name_()
  , creator_user_id_()
  , date_()
  , edit_date_()
  , expiration_date_()
  , member_limit_()
  , member_count_()
  , pending_join_request_count_()
  , creates_join_request_()
  , is_primary_()
  , is_revoked_()
{}

chatInviteLink::chatInviteLink(string const &invite_link_, string const &name_, int53 creator_user_id_, int32 date_, int32 edit_date_, int32 expiration_date_, int32 member_limit_, int32 member_count_, int32 pending_join_request_count_, bool creates_join_request_, bool is_primary_, bool is_revoked_)
  : invite_link_(invite_link_)
  , name_(name_)
  , creator_user_id_(creator_user_id_)
  , date_(date_)
  , edit_date_(edit_date_)
  , expiration_date_(expiration_date_)
  , member_limit_(member_limit_)
  , member_count_(member_count_)
  , pending_join_request_count_(pending_join_request_count_)
  , creates_join_request_(creates_join_request_)
  , is_primary_(is_primary_)
  , is_revoked_(is_revoked_)
{}

const std::int32_t chatInviteLink::ID;

void chatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    s.store_field("creator_user_id", creator_user_id_);
    s.store_field("date", date_);
    s.store_field("edit_date", edit_date_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("member_limit", member_limit_);
    s.store_field("member_count", member_count_);
    s.store_field("pending_join_request_count", pending_join_request_count_);
    s.store_field("creates_join_request", creates_join_request_);
    s.store_field("is_primary", is_primary_);
    s.store_field("is_revoked", is_revoked_);
    s.store_class_end();
  }
}

chatInviteLinkCount::chatInviteLinkCount()
  : user_id_()
  , invite_link_count_()
  , revoked_invite_link_count_()
{}

chatInviteLinkCount::chatInviteLinkCount(int53 user_id_, int32 invite_link_count_, int32 revoked_invite_link_count_)
  : user_id_(user_id_)
  , invite_link_count_(invite_link_count_)
  , revoked_invite_link_count_(revoked_invite_link_count_)
{}

const std::int32_t chatInviteLinkCount::ID;

void chatInviteLinkCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkCount");
    s.store_field("user_id", user_id_);
    s.store_field("invite_link_count", invite_link_count_);
    s.store_field("revoked_invite_link_count", revoked_invite_link_count_);
    s.store_class_end();
  }
}

chatInviteLinkCounts::chatInviteLinkCounts()
  : invite_link_counts_()
{}

chatInviteLinkCounts::chatInviteLinkCounts(array<object_ptr<chatInviteLinkCount>> &&invite_link_counts_)
  : invite_link_counts_(std::move(invite_link_counts_))
{}

const std::int32_t chatInviteLinkCounts::ID;

void chatInviteLinkCounts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkCounts");
    { s.store_vector_begin("invite_link_counts", invite_link_counts_.size()); for (const auto &_value : invite_link_counts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatInviteLinkInfo::chatInviteLinkInfo()
  : chat_id_()
  , accessible_for_()
  , type_()
  , title_()
  , photo_()
  , description_()
  , member_count_()
  , member_user_ids_()
  , creates_join_request_()
  , is_public_()
{}

chatInviteLinkInfo::chatInviteLinkInfo(int53 chat_id_, int32 accessible_for_, object_ptr<ChatType> &&type_, string const &title_, object_ptr<chatPhotoInfo> &&photo_, string const &description_, int32 member_count_, array<int53> &&member_user_ids_, bool creates_join_request_, bool is_public_)
  : chat_id_(chat_id_)
  , accessible_for_(accessible_for_)
  , type_(std::move(type_))
  , title_(title_)
  , photo_(std::move(photo_))
  , description_(description_)
  , member_count_(member_count_)
  , member_user_ids_(std::move(member_user_ids_))
  , creates_join_request_(creates_join_request_)
  , is_public_(is_public_)
{}

const std::int32_t chatInviteLinkInfo::ID;

void chatInviteLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("accessible_for", accessible_for_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("description", description_);
    s.store_field("member_count", member_count_);
    { s.store_vector_begin("member_user_ids", member_user_ids_.size()); for (const auto &_value : member_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("creates_join_request", creates_join_request_);
    s.store_field("is_public", is_public_);
    s.store_class_end();
  }
}

chatInviteLinkMember::chatInviteLinkMember()
  : user_id_()
  , joined_chat_date_()
  , approver_user_id_()
{}

chatInviteLinkMember::chatInviteLinkMember(int53 user_id_, int32 joined_chat_date_, int53 approver_user_id_)
  : user_id_(user_id_)
  , joined_chat_date_(joined_chat_date_)
  , approver_user_id_(approver_user_id_)
{}

const std::int32_t chatInviteLinkMember::ID;

void chatInviteLinkMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkMember");
    s.store_field("user_id", user_id_);
    s.store_field("joined_chat_date", joined_chat_date_);
    s.store_field("approver_user_id", approver_user_id_);
    s.store_class_end();
  }
}

chatInviteLinkMembers::chatInviteLinkMembers()
  : total_count_()
  , members_()
{}

chatInviteLinkMembers::chatInviteLinkMembers(int32 total_count_, array<object_ptr<chatInviteLinkMember>> &&members_)
  : total_count_(total_count_)
  , members_(std::move(members_))
{}

const std::int32_t chatInviteLinkMembers::ID;

void chatInviteLinkMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkMembers");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatInviteLinks::chatInviteLinks()
  : total_count_()
  , invite_links_()
{}

chatInviteLinks::chatInviteLinks(int32 total_count_, array<object_ptr<chatInviteLink>> &&invite_links_)
  : total_count_(total_count_)
  , invite_links_(std::move(invite_links_))
{}

const std::int32_t chatInviteLinks::ID;

void chatInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinks");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("invite_links", invite_links_.size()); for (const auto &_value : invite_links_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatJoinRequest::chatJoinRequest()
  : user_id_()
  , date_()
  , bio_()
{}

chatJoinRequest::chatJoinRequest(int53 user_id_, int32 date_, string const &bio_)
  : user_id_(user_id_)
  , date_(date_)
  , bio_(bio_)
{}

const std::int32_t chatJoinRequest::ID;

void chatJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequest");
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    s.store_field("bio", bio_);
    s.store_class_end();
  }
}

chatJoinRequests::chatJoinRequests()
  : total_count_()
  , requests_()
{}

chatJoinRequests::chatJoinRequests(int32 total_count_, array<object_ptr<chatJoinRequest>> &&requests_)
  : total_count_(total_count_)
  , requests_(std::move(requests_))
{}

const std::int32_t chatJoinRequests::ID;

void chatJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequests");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("requests", requests_.size()); for (const auto &_value : requests_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatJoinRequestsInfo::chatJoinRequestsInfo()
  : total_count_()
  , user_ids_()
{}

chatJoinRequestsInfo::chatJoinRequestsInfo(int32 total_count_, array<int53> &&user_ids_)
  : total_count_(total_count_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t chatJoinRequestsInfo::ID;

void chatJoinRequestsInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequestsInfo");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatListMain::chatListMain() {
}

const std::int32_t chatListMain::ID;

void chatListMain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatListMain");
    s.store_class_end();
  }
}

chatListArchive::chatListArchive() {
}

const std::int32_t chatListArchive::ID;

void chatListArchive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatListArchive");
    s.store_class_end();
  }
}

chatListFilter::chatListFilter()
  : chat_filter_id_()
{}

chatListFilter::chatListFilter(int32 chat_filter_id_)
  : chat_filter_id_(chat_filter_id_)
{}

const std::int32_t chatListFilter::ID;

void chatListFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatListFilter");
    s.store_field("chat_filter_id", chat_filter_id_);
    s.store_class_end();
  }
}

chatLists::chatLists()
  : chat_lists_()
{}

chatLists::chatLists(array<object_ptr<ChatList>> &&chat_lists_)
  : chat_lists_(std::move(chat_lists_))
{}

const std::int32_t chatLists::ID;

void chatLists::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatLists");
    { s.store_vector_begin("chat_lists", chat_lists_.size()); for (const auto &_value : chat_lists_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatLocation::chatLocation()
  : location_()
  , address_()
{}

chatLocation::chatLocation(object_ptr<location> &&location_, string const &address_)
  : location_(std::move(location_))
  , address_(address_)
{}

const std::int32_t chatLocation::ID;

void chatLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("address", address_);
    s.store_class_end();
  }
}

chatMember::chatMember()
  : member_id_()
  , inviter_user_id_()
  , joined_chat_date_()
  , status_()
{}

chatMember::chatMember(object_ptr<MessageSender> &&member_id_, int53 inviter_user_id_, int32 joined_chat_date_, object_ptr<ChatMemberStatus> &&status_)
  : member_id_(std::move(member_id_))
  , inviter_user_id_(inviter_user_id_)
  , joined_chat_date_(joined_chat_date_)
  , status_(std::move(status_))
{}

const std::int32_t chatMember::ID;

void chatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMember");
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_field("inviter_user_id", inviter_user_id_);
    s.store_field("joined_chat_date", joined_chat_date_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

chatMemberStatusCreator::chatMemberStatusCreator()
  : custom_title_()
  , is_anonymous_()
  , is_member_()
{}

chatMemberStatusCreator::chatMemberStatusCreator(string const &custom_title_, bool is_anonymous_, bool is_member_)
  : custom_title_(custom_title_)
  , is_anonymous_(is_anonymous_)
  , is_member_(is_member_)
{}

const std::int32_t chatMemberStatusCreator::ID;

void chatMemberStatusCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusCreator");
    s.store_field("custom_title", custom_title_);
    s.store_field("is_anonymous", is_anonymous_);
    s.store_field("is_member", is_member_);
    s.store_class_end();
  }
}

chatMemberStatusAdministrator::chatMemberStatusAdministrator()
  : custom_title_()
  , can_be_edited_()
  , rights_()
{}

chatMemberStatusAdministrator::chatMemberStatusAdministrator(string const &custom_title_, bool can_be_edited_, object_ptr<chatAdministratorRights> &&rights_)
  : custom_title_(custom_title_)
  , can_be_edited_(can_be_edited_)
  , rights_(std::move(rights_))
{}

const std::int32_t chatMemberStatusAdministrator::ID;

void chatMemberStatusAdministrator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusAdministrator");
    s.store_field("custom_title", custom_title_);
    s.store_field("can_be_edited", can_be_edited_);
    s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get()));
    s.store_class_end();
  }
}

chatMemberStatusMember::chatMemberStatusMember() {
}

const std::int32_t chatMemberStatusMember::ID;

void chatMemberStatusMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusMember");
    s.store_class_end();
  }
}

chatMemberStatusRestricted::chatMemberStatusRestricted()
  : is_member_()
  , restricted_until_date_()
  , permissions_()
{}

chatMemberStatusRestricted::chatMemberStatusRestricted(bool is_member_, int32 restricted_until_date_, object_ptr<chatPermissions> &&permissions_)
  : is_member_(is_member_)
  , restricted_until_date_(restricted_until_date_)
  , permissions_(std::move(permissions_))
{}

const std::int32_t chatMemberStatusRestricted::ID;

void chatMemberStatusRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusRestricted");
    s.store_field("is_member", is_member_);
    s.store_field("restricted_until_date", restricted_until_date_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_class_end();
  }
}

chatMemberStatusLeft::chatMemberStatusLeft() {
}

const std::int32_t chatMemberStatusLeft::ID;

void chatMemberStatusLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusLeft");
    s.store_class_end();
  }
}

chatMemberStatusBanned::chatMemberStatusBanned()
  : banned_until_date_()
{}

chatMemberStatusBanned::chatMemberStatusBanned(int32 banned_until_date_)
  : banned_until_date_(banned_until_date_)
{}

const std::int32_t chatMemberStatusBanned::ID;

void chatMemberStatusBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMemberStatusBanned");
    s.store_field("banned_until_date", banned_until_date_);
    s.store_class_end();
  }
}

chatMembers::chatMembers()
  : total_count_()
  , members_()
{}

chatMembers::chatMembers(int32 total_count_, array<object_ptr<chatMember>> &&members_)
  : total_count_(total_count_)
  , members_(std::move(members_))
{}

const std::int32_t chatMembers::ID;

void chatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembers");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatMembersFilterContacts::chatMembersFilterContacts() {
}

const std::int32_t chatMembersFilterContacts::ID;

void chatMembersFilterContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterContacts");
    s.store_class_end();
  }
}

chatMembersFilterAdministrators::chatMembersFilterAdministrators() {
}

const std::int32_t chatMembersFilterAdministrators::ID;

void chatMembersFilterAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterAdministrators");
    s.store_class_end();
  }
}

chatMembersFilterMembers::chatMembersFilterMembers() {
}

const std::int32_t chatMembersFilterMembers::ID;

void chatMembersFilterMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterMembers");
    s.store_class_end();
  }
}

chatMembersFilterMention::chatMembersFilterMention()
  : message_thread_id_()
{}

chatMembersFilterMention::chatMembersFilterMention(int53 message_thread_id_)
  : message_thread_id_(message_thread_id_)
{}

const std::int32_t chatMembersFilterMention::ID;

void chatMembersFilterMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterMention");
    s.store_field("message_thread_id", message_thread_id_);
    s.store_class_end();
  }
}

chatMembersFilterRestricted::chatMembersFilterRestricted() {
}

const std::int32_t chatMembersFilterRestricted::ID;

void chatMembersFilterRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterRestricted");
    s.store_class_end();
  }
}

chatMembersFilterBanned::chatMembersFilterBanned() {
}

const std::int32_t chatMembersFilterBanned::ID;

void chatMembersFilterBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterBanned");
    s.store_class_end();
  }
}

chatMembersFilterBots::chatMembersFilterBots() {
}

const std::int32_t chatMembersFilterBots::ID;

void chatMembersFilterBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterBots");
    s.store_class_end();
  }
}

chatNearby::chatNearby()
  : chat_id_()
  , distance_()
{}

chatNearby::chatNearby(int53 chat_id_, int32 distance_)
  : chat_id_(chat_id_)
  , distance_(distance_)
{}

const std::int32_t chatNearby::ID;

void chatNearby::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatNearby");
    s.store_field("chat_id", chat_id_);
    s.store_field("distance", distance_);
    s.store_class_end();
  }
}

chatNotificationSettings::chatNotificationSettings()
  : use_default_mute_for_()
  , mute_for_()
  , use_default_sound_()
  , sound_id_()
  , use_default_show_preview_()
  , show_preview_()
  , use_default_disable_pinned_message_notifications_()
  , disable_pinned_message_notifications_()
  , use_default_disable_mention_notifications_()
  , disable_mention_notifications_()
{}

chatNotificationSettings::chatNotificationSettings(bool use_default_mute_for_, int32 mute_for_, bool use_default_sound_, int64 sound_id_, bool use_default_show_preview_, bool show_preview_, bool use_default_disable_pinned_message_notifications_, bool disable_pinned_message_notifications_, bool use_default_disable_mention_notifications_, bool disable_mention_notifications_)
  : use_default_mute_for_(use_default_mute_for_)
  , mute_for_(mute_for_)
  , use_default_sound_(use_default_sound_)
  , sound_id_(sound_id_)
  , use_default_show_preview_(use_default_show_preview_)
  , show_preview_(show_preview_)
  , use_default_disable_pinned_message_notifications_(use_default_disable_pinned_message_notifications_)
  , disable_pinned_message_notifications_(disable_pinned_message_notifications_)
  , use_default_disable_mention_notifications_(use_default_disable_mention_notifications_)
  , disable_mention_notifications_(disable_mention_notifications_)
{}

const std::int32_t chatNotificationSettings::ID;

void chatNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatNotificationSettings");
    s.store_field("use_default_mute_for", use_default_mute_for_);
    s.store_field("mute_for", mute_for_);
    s.store_field("use_default_sound", use_default_sound_);
    s.store_field("sound_id", sound_id_);
    s.store_field("use_default_show_preview", use_default_show_preview_);
    s.store_field("show_preview", show_preview_);
    s.store_field("use_default_disable_pinned_message_notifications", use_default_disable_pinned_message_notifications_);
    s.store_field("disable_pinned_message_notifications", disable_pinned_message_notifications_);
    s.store_field("use_default_disable_mention_notifications", use_default_disable_mention_notifications_);
    s.store_field("disable_mention_notifications", disable_mention_notifications_);
    s.store_class_end();
  }
}

chatPermissions::chatPermissions()
  : can_send_messages_()
  , can_send_media_messages_()
  , can_send_polls_()
  , can_send_other_messages_()
  , can_add_web_page_previews_()
  , can_change_info_()
  , can_invite_users_()
  , can_pin_messages_()
{}

chatPermissions::chatPermissions(bool can_send_messages_, bool can_send_media_messages_, bool can_send_polls_, bool can_send_other_messages_, bool can_add_web_page_previews_, bool can_change_info_, bool can_invite_users_, bool can_pin_messages_)
  : can_send_messages_(can_send_messages_)
  , can_send_media_messages_(can_send_media_messages_)
  , can_send_polls_(can_send_polls_)
  , can_send_other_messages_(can_send_other_messages_)
  , can_add_web_page_previews_(can_add_web_page_previews_)
  , can_change_info_(can_change_info_)
  , can_invite_users_(can_invite_users_)
  , can_pin_messages_(can_pin_messages_)
{}

const std::int32_t chatPermissions::ID;

void chatPermissions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPermissions");
    s.store_field("can_send_messages", can_send_messages_);
    s.store_field("can_send_media_messages", can_send_media_messages_);
    s.store_field("can_send_polls", can_send_polls_);
    s.store_field("can_send_other_messages", can_send_other_messages_);
    s.store_field("can_add_web_page_previews", can_add_web_page_previews_);
    s.store_field("can_change_info", can_change_info_);
    s.store_field("can_invite_users", can_invite_users_);
    s.store_field("can_pin_messages", can_pin_messages_);
    s.store_class_end();
  }
}

chatPhoto::chatPhoto()
  : id_()
  , added_date_()
  , minithumbnail_()
  , sizes_()
  , animation_()
{}

chatPhoto::chatPhoto(int64 id_, int32 added_date_, object_ptr<minithumbnail> &&minithumbnail_, array<object_ptr<photoSize>> &&sizes_, object_ptr<animatedChatPhoto> &&animation_)
  : id_(id_)
  , added_date_(added_date_)
  , minithumbnail_(std::move(minithumbnail_))
  , sizes_(std::move(sizes_))
  , animation_(std::move(animation_))
{}

const std::int32_t chatPhoto::ID;

void chatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhoto");
    s.store_field("id", id_);
    s.store_field("added_date", added_date_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    { s.store_vector_begin("sizes", sizes_.size()); for (const auto &_value : sizes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

chatPhotoInfo::chatPhotoInfo()
  : small_()
  , big_()
  , minithumbnail_()
  , has_animation_()
{}

chatPhotoInfo::chatPhotoInfo(object_ptr<file> &&small_, object_ptr<file> &&big_, object_ptr<minithumbnail> &&minithumbnail_, bool has_animation_)
  : small_(std::move(small_))
  , big_(std::move(big_))
  , minithumbnail_(std::move(minithumbnail_))
  , has_animation_(has_animation_)
{}

const std::int32_t chatPhotoInfo::ID;

void chatPhotoInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotoInfo");
    s.store_object_field("small", static_cast<const BaseObject *>(small_.get()));
    s.store_object_field("big", static_cast<const BaseObject *>(big_.get()));
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_field("has_animation", has_animation_);
    s.store_class_end();
  }
}

chatPhotos::chatPhotos()
  : total_count_()
  , photos_()
{}

chatPhotos::chatPhotos(int32 total_count_, array<object_ptr<chatPhoto>> &&photos_)
  : total_count_(total_count_)
  , photos_(std::move(photos_))
{}

const std::int32_t chatPhotos::ID;

void chatPhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotos");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("photos", photos_.size()); for (const auto &_value : photos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatPosition::chatPosition()
  : list_()
  , order_()
  , is_pinned_()
  , source_()
{}

chatPosition::chatPosition(object_ptr<ChatList> &&list_, int64 order_, bool is_pinned_, object_ptr<ChatSource> &&source_)
  : list_(std::move(list_))
  , order_(order_)
  , is_pinned_(is_pinned_)
  , source_(std::move(source_))
{}

const std::int32_t chatPosition::ID;

void chatPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPosition");
    s.store_object_field("list", static_cast<const BaseObject *>(list_.get()));
    s.store_field("order", order_);
    s.store_field("is_pinned", is_pinned_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

chatReportReasonSpam::chatReportReasonSpam() {
}

const std::int32_t chatReportReasonSpam::ID;

void chatReportReasonSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReportReasonSpam");
    s.store_class_end();
  }
}

chatReportReasonViolence::chatReportReasonViolence() {
}

const std::int32_t chatReportReasonViolence::ID;

void chatReportReasonViolence::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReportReasonViolence");
    s.store_class_end();
  }
}

chatReportReasonPornography::chatReportReasonPornography() {
}

const std::int32_t chatReportReasonPornography::ID;

void chatReportReasonPornography::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReportReasonPornography");
    s.store_class_end();
  }
}

chatReportReasonChildAbuse::chatReportReasonChildAbuse() {
}

const std::int32_t chatReportReasonChildAbuse::ID;

void chatReportReasonChildAbuse::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReportReasonChildAbuse");
    s.store_class_end();
  }
}

chatReportReasonCopyright::chatReportReasonCopyright() {
}

const std::int32_t chatReportReasonCopyright::ID;

void chatReportReasonCopyright::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReportReasonCopyright");
    s.store_class_end();
  }
}

chatReportReasonUnrelatedLocation::chatReportReasonUnrelatedLocation() {
}

const std::int32_t chatReportReasonUnrelatedLocation::ID;

void chatReportReasonUnrelatedLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReportReasonUnrelatedLocation");
    s.store_class_end();
  }
}

chatReportReasonFake::chatReportReasonFake() {
}

const std::int32_t chatReportReasonFake::ID;

void chatReportReasonFake::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReportReasonFake");
    s.store_class_end();
  }
}

chatReportReasonIllegalDrugs::chatReportReasonIllegalDrugs() {
}

const std::int32_t chatReportReasonIllegalDrugs::ID;

void chatReportReasonIllegalDrugs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReportReasonIllegalDrugs");
    s.store_class_end();
  }
}

chatReportReasonPersonalDetails::chatReportReasonPersonalDetails() {
}

const std::int32_t chatReportReasonPersonalDetails::ID;

void chatReportReasonPersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReportReasonPersonalDetails");
    s.store_class_end();
  }
}

chatReportReasonCustom::chatReportReasonCustom() {
}

const std::int32_t chatReportReasonCustom::ID;

void chatReportReasonCustom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReportReasonCustom");
    s.store_class_end();
  }
}

chatSourceMtprotoProxy::chatSourceMtprotoProxy() {
}

const std::int32_t chatSourceMtprotoProxy::ID;

void chatSourceMtprotoProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatSourceMtprotoProxy");
    s.store_class_end();
  }
}

chatSourcePublicServiceAnnouncement::chatSourcePublicServiceAnnouncement()
  : type_()
  , text_()
{}

chatSourcePublicServiceAnnouncement::chatSourcePublicServiceAnnouncement(string const &type_, string const &text_)
  : type_(type_)
  , text_(text_)
{}

const std::int32_t chatSourcePublicServiceAnnouncement::ID;

void chatSourcePublicServiceAnnouncement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatSourcePublicServiceAnnouncement");
    s.store_field("type", type_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

chatStatisticsSupergroup::chatStatisticsSupergroup()
  : period_()
  , member_count_()
  , message_count_()
  , viewer_count_()
  , sender_count_()
  , member_count_graph_()
  , join_graph_()
  , join_by_source_graph_()
  , language_graph_()
  , message_content_graph_()
  , action_graph_()
  , day_graph_()
  , week_graph_()
  , top_senders_()
  , top_administrators_()
  , top_inviters_()
{}

chatStatisticsSupergroup::chatStatisticsSupergroup(object_ptr<dateRange> &&period_, object_ptr<statisticalValue> &&member_count_, object_ptr<statisticalValue> &&message_count_, object_ptr<statisticalValue> &&viewer_count_, object_ptr<statisticalValue> &&sender_count_, object_ptr<StatisticalGraph> &&member_count_graph_, object_ptr<StatisticalGraph> &&join_graph_, object_ptr<StatisticalGraph> &&join_by_source_graph_, object_ptr<StatisticalGraph> &&language_graph_, object_ptr<StatisticalGraph> &&message_content_graph_, object_ptr<StatisticalGraph> &&action_graph_, object_ptr<StatisticalGraph> &&day_graph_, object_ptr<StatisticalGraph> &&week_graph_, array<object_ptr<chatStatisticsMessageSenderInfo>> &&top_senders_, array<object_ptr<chatStatisticsAdministratorActionsInfo>> &&top_administrators_, array<object_ptr<chatStatisticsInviterInfo>> &&top_inviters_)
  : period_(std::move(period_))
  , member_count_(std::move(member_count_))
  , message_count_(std::move(message_count_))
  , viewer_count_(std::move(viewer_count_))
  , sender_count_(std::move(sender_count_))
  , member_count_graph_(std::move(member_count_graph_))
  , join_graph_(std::move(join_graph_))
  , join_by_source_graph_(std::move(join_by_source_graph_))
  , language_graph_(std::move(language_graph_))
  , message_content_graph_(std::move(message_content_graph_))
  , action_graph_(std::move(action_graph_))
  , day_graph_(std::move(day_graph_))
  , week_graph_(std::move(week_graph_))
  , top_senders_(std::move(top_senders_))
  , top_administrators_(std::move(top_administrators_))
  , top_inviters_(std::move(top_inviters_))
{}

const std::int32_t chatStatisticsSupergroup::ID;

void chatStatisticsSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsSupergroup");
    s.store_object_field("period", static_cast<const BaseObject *>(period_.get()));
    s.store_object_field("member_count", static_cast<const BaseObject *>(member_count_.get()));
    s.store_object_field("message_count", static_cast<const BaseObject *>(message_count_.get()));
    s.store_object_field("viewer_count", static_cast<const BaseObject *>(viewer_count_.get()));
    s.store_object_field("sender_count", static_cast<const BaseObject *>(sender_count_.get()));
    s.store_object_field("member_count_graph", static_cast<const BaseObject *>(member_count_graph_.get()));
    s.store_object_field("join_graph", static_cast<const BaseObject *>(join_graph_.get()));
    s.store_object_field("join_by_source_graph", static_cast<const BaseObject *>(join_by_source_graph_.get()));
    s.store_object_field("language_graph", static_cast<const BaseObject *>(language_graph_.get()));
    s.store_object_field("message_content_graph", static_cast<const BaseObject *>(message_content_graph_.get()));
    s.store_object_field("action_graph", static_cast<const BaseObject *>(action_graph_.get()));
    s.store_object_field("day_graph", static_cast<const BaseObject *>(day_graph_.get()));
    s.store_object_field("week_graph", static_cast<const BaseObject *>(week_graph_.get()));
    { s.store_vector_begin("top_senders", top_senders_.size()); for (const auto &_value : top_senders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_administrators", top_administrators_.size()); for (const auto &_value : top_administrators_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_inviters", top_inviters_.size()); for (const auto &_value : top_inviters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatStatisticsChannel::chatStatisticsChannel()
  : period_()
  , member_count_()
  , mean_view_count_()
  , mean_share_count_()
  , enabled_notifications_percentage_()
  , member_count_graph_()
  , join_graph_()
  , mute_graph_()
  , view_count_by_hour_graph_()
  , view_count_by_source_graph_()
  , join_by_source_graph_()
  , language_graph_()
  , message_interaction_graph_()
  , instant_view_interaction_graph_()
  , recent_message_interactions_()
{}

chatStatisticsChannel::chatStatisticsChannel(object_ptr<dateRange> &&period_, object_ptr<statisticalValue> &&member_count_, object_ptr<statisticalValue> &&mean_view_count_, object_ptr<statisticalValue> &&mean_share_count_, double enabled_notifications_percentage_, object_ptr<StatisticalGraph> &&member_count_graph_, object_ptr<StatisticalGraph> &&join_graph_, object_ptr<StatisticalGraph> &&mute_graph_, object_ptr<StatisticalGraph> &&view_count_by_hour_graph_, object_ptr<StatisticalGraph> &&view_count_by_source_graph_, object_ptr<StatisticalGraph> &&join_by_source_graph_, object_ptr<StatisticalGraph> &&language_graph_, object_ptr<StatisticalGraph> &&message_interaction_graph_, object_ptr<StatisticalGraph> &&instant_view_interaction_graph_, array<object_ptr<chatStatisticsMessageInteractionInfo>> &&recent_message_interactions_)
  : period_(std::move(period_))
  , member_count_(std::move(member_count_))
  , mean_view_count_(std::move(mean_view_count_))
  , mean_share_count_(std::move(mean_share_count_))
  , enabled_notifications_percentage_(enabled_notifications_percentage_)
  , member_count_graph_(std::move(member_count_graph_))
  , join_graph_(std::move(join_graph_))
  , mute_graph_(std::move(mute_graph_))
  , view_count_by_hour_graph_(std::move(view_count_by_hour_graph_))
  , view_count_by_source_graph_(std::move(view_count_by_source_graph_))
  , join_by_source_graph_(std::move(join_by_source_graph_))
  , language_graph_(std::move(language_graph_))
  , message_interaction_graph_(std::move(message_interaction_graph_))
  , instant_view_interaction_graph_(std::move(instant_view_interaction_graph_))
  , recent_message_interactions_(std::move(recent_message_interactions_))
{}

const std::int32_t chatStatisticsChannel::ID;

void chatStatisticsChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsChannel");
    s.store_object_field("period", static_cast<const BaseObject *>(period_.get()));
    s.store_object_field("member_count", static_cast<const BaseObject *>(member_count_.get()));
    s.store_object_field("mean_view_count", static_cast<const BaseObject *>(mean_view_count_.get()));
    s.store_object_field("mean_share_count", static_cast<const BaseObject *>(mean_share_count_.get()));
    s.store_field("enabled_notifications_percentage", enabled_notifications_percentage_);
    s.store_object_field("member_count_graph", static_cast<const BaseObject *>(member_count_graph_.get()));
    s.store_object_field("join_graph", static_cast<const BaseObject *>(join_graph_.get()));
    s.store_object_field("mute_graph", static_cast<const BaseObject *>(mute_graph_.get()));
    s.store_object_field("view_count_by_hour_graph", static_cast<const BaseObject *>(view_count_by_hour_graph_.get()));
    s.store_object_field("view_count_by_source_graph", static_cast<const BaseObject *>(view_count_by_source_graph_.get()));
    s.store_object_field("join_by_source_graph", static_cast<const BaseObject *>(join_by_source_graph_.get()));
    s.store_object_field("language_graph", static_cast<const BaseObject *>(language_graph_.get()));
    s.store_object_field("message_interaction_graph", static_cast<const BaseObject *>(message_interaction_graph_.get()));
    s.store_object_field("instant_view_interaction_graph", static_cast<const BaseObject *>(instant_view_interaction_graph_.get()));
    { s.store_vector_begin("recent_message_interactions", recent_message_interactions_.size()); for (const auto &_value : recent_message_interactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatStatisticsAdministratorActionsInfo::chatStatisticsAdministratorActionsInfo()
  : user_id_()
  , deleted_message_count_()
  , banned_user_count_()
  , restricted_user_count_()
{}

chatStatisticsAdministratorActionsInfo::chatStatisticsAdministratorActionsInfo(int53 user_id_, int32 deleted_message_count_, int32 banned_user_count_, int32 restricted_user_count_)
  : user_id_(user_id_)
  , deleted_message_count_(deleted_message_count_)
  , banned_user_count_(banned_user_count_)
  , restricted_user_count_(restricted_user_count_)
{}

const std::int32_t chatStatisticsAdministratorActionsInfo::ID;

void chatStatisticsAdministratorActionsInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsAdministratorActionsInfo");
    s.store_field("user_id", user_id_);
    s.store_field("deleted_message_count", deleted_message_count_);
    s.store_field("banned_user_count", banned_user_count_);
    s.store_field("restricted_user_count", restricted_user_count_);
    s.store_class_end();
  }
}

chatStatisticsInviterInfo::chatStatisticsInviterInfo()
  : user_id_()
  , added_member_count_()
{}

chatStatisticsInviterInfo::chatStatisticsInviterInfo(int53 user_id_, int32 added_member_count_)
  : user_id_(user_id_)
  , added_member_count_(added_member_count_)
{}

const std::int32_t chatStatisticsInviterInfo::ID;

void chatStatisticsInviterInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsInviterInfo");
    s.store_field("user_id", user_id_);
    s.store_field("added_member_count", added_member_count_);
    s.store_class_end();
  }
}

chatStatisticsMessageInteractionInfo::chatStatisticsMessageInteractionInfo()
  : message_id_()
  , view_count_()
  , forward_count_()
{}

chatStatisticsMessageInteractionInfo::chatStatisticsMessageInteractionInfo(int53 message_id_, int32 view_count_, int32 forward_count_)
  : message_id_(message_id_)
  , view_count_(view_count_)
  , forward_count_(forward_count_)
{}

const std::int32_t chatStatisticsMessageInteractionInfo::ID;

void chatStatisticsMessageInteractionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsMessageInteractionInfo");
    s.store_field("message_id", message_id_);
    s.store_field("view_count", view_count_);
    s.store_field("forward_count", forward_count_);
    s.store_class_end();
  }
}

chatStatisticsMessageSenderInfo::chatStatisticsMessageSenderInfo()
  : user_id_()
  , sent_message_count_()
  , average_character_count_()
{}

chatStatisticsMessageSenderInfo::chatStatisticsMessageSenderInfo(int53 user_id_, int32 sent_message_count_, int32 average_character_count_)
  : user_id_(user_id_)
  , sent_message_count_(sent_message_count_)
  , average_character_count_(average_character_count_)
{}

const std::int32_t chatStatisticsMessageSenderInfo::ID;

void chatStatisticsMessageSenderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsMessageSenderInfo");
    s.store_field("user_id", user_id_);
    s.store_field("sent_message_count", sent_message_count_);
    s.store_field("average_character_count", average_character_count_);
    s.store_class_end();
  }
}

chatTheme::chatTheme()
  : name_()
  , light_settings_()
  , dark_settings_()
{}

chatTheme::chatTheme(string const &name_, object_ptr<themeSettings> &&light_settings_, object_ptr<themeSettings> &&dark_settings_)
  : name_(name_)
  , light_settings_(std::move(light_settings_))
  , dark_settings_(std::move(dark_settings_))
{}

const std::int32_t chatTheme::ID;

void chatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTheme");
    s.store_field("name", name_);
    s.store_object_field("light_settings", static_cast<const BaseObject *>(light_settings_.get()));
    s.store_object_field("dark_settings", static_cast<const BaseObject *>(dark_settings_.get()));
    s.store_class_end();
  }
}

chatTypePrivate::chatTypePrivate()
  : user_id_()
{}

chatTypePrivate::chatTypePrivate(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t chatTypePrivate::ID;

void chatTypePrivate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypePrivate");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

chatTypeBasicGroup::chatTypeBasicGroup()
  : basic_group_id_()
{}

chatTypeBasicGroup::chatTypeBasicGroup(int53 basic_group_id_)
  : basic_group_id_(basic_group_id_)
{}

const std::int32_t chatTypeBasicGroup::ID;

void chatTypeBasicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypeBasicGroup");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

chatTypeSupergroup::chatTypeSupergroup()
  : supergroup_id_()
  , is_channel_()
{}

chatTypeSupergroup::chatTypeSupergroup(int53 supergroup_id_, bool is_channel_)
  : supergroup_id_(supergroup_id_)
  , is_channel_(is_channel_)
{}

const std::int32_t chatTypeSupergroup::ID;

void chatTypeSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypeSupergroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("is_channel", is_channel_);
    s.store_class_end();
  }
}

chatTypeSecret::chatTypeSecret()
  : secret_chat_id_()
  , user_id_()
{}

chatTypeSecret::chatTypeSecret(int32 secret_chat_id_, int53 user_id_)
  : secret_chat_id_(secret_chat_id_)
  , user_id_(user_id_)
{}

const std::int32_t chatTypeSecret::ID;

void chatTypeSecret::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTypeSecret");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

chats::chats()
  : total_count_()
  , chat_ids_()
{}

chats::chats(int32 total_count_, array<int53> &&chat_ids_)
  : total_count_(total_count_)
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t chats::ID;

void chats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chats");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatsNearby::chatsNearby()
  : users_nearby_()
  , supergroups_nearby_()
{}

chatsNearby::chatsNearby(array<object_ptr<chatNearby>> &&users_nearby_, array<object_ptr<chatNearby>> &&supergroups_nearby_)
  : users_nearby_(std::move(users_nearby_))
  , supergroups_nearby_(std::move(supergroups_nearby_))
{}

const std::int32_t chatsNearby::ID;

void chatsNearby::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatsNearby");
    { s.store_vector_begin("users_nearby", users_nearby_.size()); for (const auto &_value : users_nearby_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("supergroups_nearby", supergroups_nearby_.size()); for (const auto &_value : supergroups_nearby_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

checkChatUsernameResultOk::checkChatUsernameResultOk() {
}

const std::int32_t checkChatUsernameResultOk::ID;

void checkChatUsernameResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultOk");
    s.store_class_end();
  }
}

checkChatUsernameResultUsernameInvalid::checkChatUsernameResultUsernameInvalid() {
}

const std::int32_t checkChatUsernameResultUsernameInvalid::ID;

void checkChatUsernameResultUsernameInvalid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultUsernameInvalid");
    s.store_class_end();
  }
}

checkChatUsernameResultUsernameOccupied::checkChatUsernameResultUsernameOccupied() {
}

const std::int32_t checkChatUsernameResultUsernameOccupied::ID;

void checkChatUsernameResultUsernameOccupied::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultUsernameOccupied");
    s.store_class_end();
  }
}

checkChatUsernameResultPublicChatsTooMuch::checkChatUsernameResultPublicChatsTooMuch() {
}

const std::int32_t checkChatUsernameResultPublicChatsTooMuch::ID;

void checkChatUsernameResultPublicChatsTooMuch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultPublicChatsTooMuch");
    s.store_class_end();
  }
}

checkChatUsernameResultPublicGroupsUnavailable::checkChatUsernameResultPublicGroupsUnavailable() {
}

const std::int32_t checkChatUsernameResultPublicGroupsUnavailable::ID;

void checkChatUsernameResultPublicGroupsUnavailable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultPublicGroupsUnavailable");
    s.store_class_end();
  }
}

checkStickerSetNameResultOk::checkStickerSetNameResultOk() {
}

const std::int32_t checkStickerSetNameResultOk::ID;

void checkStickerSetNameResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetNameResultOk");
    s.store_class_end();
  }
}

checkStickerSetNameResultNameInvalid::checkStickerSetNameResultNameInvalid() {
}

const std::int32_t checkStickerSetNameResultNameInvalid::ID;

void checkStickerSetNameResultNameInvalid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetNameResultNameInvalid");
    s.store_class_end();
  }
}

checkStickerSetNameResultNameOccupied::checkStickerSetNameResultNameOccupied() {
}

const std::int32_t checkStickerSetNameResultNameOccupied::ID;

void checkStickerSetNameResultNameOccupied::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetNameResultNameOccupied");
    s.store_class_end();
  }
}

closedVectorPath::closedVectorPath()
  : commands_()
{}

closedVectorPath::closedVectorPath(array<object_ptr<VectorPathCommand>> &&commands_)
  : commands_(std::move(commands_))
{}

const std::int32_t closedVectorPath::ID;

void closedVectorPath::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closedVectorPath");
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

connectedWebsite::connectedWebsite()
  : id_()
  , domain_name_()
  , bot_user_id_()
  , browser_()
  , platform_()
  , log_in_date_()
  , last_active_date_()
  , ip_()
  , location_()
{}

connectedWebsite::connectedWebsite(int64 id_, string const &domain_name_, int53 bot_user_id_, string const &browser_, string const &platform_, int32 log_in_date_, int32 last_active_date_, string const &ip_, string const &location_)
  : id_(id_)
  , domain_name_(domain_name_)
  , bot_user_id_(bot_user_id_)
  , browser_(browser_)
  , platform_(platform_)
  , log_in_date_(log_in_date_)
  , last_active_date_(last_active_date_)
  , ip_(ip_)
  , location_(location_)
{}

const std::int32_t connectedWebsite::ID;

void connectedWebsite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedWebsite");
    s.store_field("id", id_);
    s.store_field("domain_name", domain_name_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("browser", browser_);
    s.store_field("platform", platform_);
    s.store_field("log_in_date", log_in_date_);
    s.store_field("last_active_date", last_active_date_);
    s.store_field("ip", ip_);
    s.store_field("location", location_);
    s.store_class_end();
  }
}

connectedWebsites::connectedWebsites()
  : websites_()
{}

connectedWebsites::connectedWebsites(array<object_ptr<connectedWebsite>> &&websites_)
  : websites_(std::move(websites_))
{}

const std::int32_t connectedWebsites::ID;

void connectedWebsites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedWebsites");
    { s.store_vector_begin("websites", websites_.size()); for (const auto &_value : websites_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

connectionStateWaitingForNetwork::connectionStateWaitingForNetwork() {
}

const std::int32_t connectionStateWaitingForNetwork::ID;

void connectionStateWaitingForNetwork::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateWaitingForNetwork");
    s.store_class_end();
  }
}

connectionStateConnectingToProxy::connectionStateConnectingToProxy() {
}

const std::int32_t connectionStateConnectingToProxy::ID;

void connectionStateConnectingToProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateConnectingToProxy");
    s.store_class_end();
  }
}

connectionStateConnecting::connectionStateConnecting() {
}

const std::int32_t connectionStateConnecting::ID;

void connectionStateConnecting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateConnecting");
    s.store_class_end();
  }
}

connectionStateUpdating::connectionStateUpdating() {
}

const std::int32_t connectionStateUpdating::ID;

void connectionStateUpdating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateUpdating");
    s.store_class_end();
  }
}

connectionStateReady::connectionStateReady() {
}

const std::int32_t connectionStateReady::ID;

void connectionStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectionStateReady");
    s.store_class_end();
  }
}

contact::contact()
  : phone_number_()
  , first_name_()
  , last_name_()
  , vcard_()
  , user_id_()
{}

contact::contact(string const &phone_number_, string const &first_name_, string const &last_name_, string const &vcard_, int53 user_id_)
  : phone_number_(phone_number_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , vcard_(vcard_)
  , user_id_(user_id_)
{}

const std::int32_t contact::ID;

void contact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contact");
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("vcard", vcard_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

count::count()
  : count_()
{}

count::count(int32 count_)
  : count_(count_)
{}

const std::int32_t count::ID;

void count::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "count");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

countries::countries()
  : countries_()
{}

countries::countries(array<object_ptr<countryInfo>> &&countries_)
  : countries_(std::move(countries_))
{}

const std::int32_t countries::ID;

void countries::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "countries");
    { s.store_vector_begin("countries", countries_.size()); for (const auto &_value : countries_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

countryInfo::countryInfo()
  : country_code_()
  , name_()
  , english_name_()
  , is_hidden_()
  , calling_codes_()
{}

countryInfo::countryInfo(string const &country_code_, string const &name_, string const &english_name_, bool is_hidden_, array<string> &&calling_codes_)
  : country_code_(country_code_)
  , name_(name_)
  , english_name_(english_name_)
  , is_hidden_(is_hidden_)
  , calling_codes_(std::move(calling_codes_))
{}

const std::int32_t countryInfo::ID;

void countryInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "countryInfo");
    s.store_field("country_code", country_code_);
    s.store_field("name", name_);
    s.store_field("english_name", english_name_);
    s.store_field("is_hidden", is_hidden_);
    { s.store_vector_begin("calling_codes", calling_codes_.size()); for (const auto &_value : calling_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

customRequestResult::customRequestResult()
  : result_()
{}

customRequestResult::customRequestResult(string const &result_)
  : result_(result_)
{}

const std::int32_t customRequestResult::ID;

void customRequestResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "customRequestResult");
    s.store_field("result", result_);
    s.store_class_end();
  }
}

databaseStatistics::databaseStatistics()
  : statistics_()
{}

databaseStatistics::databaseStatistics(string const &statistics_)
  : statistics_(statistics_)
{}

const std::int32_t databaseStatistics::ID;

void databaseStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "databaseStatistics");
    s.store_field("statistics", statistics_);
    s.store_class_end();
  }
}

date::date()
  : day_()
  , month_()
  , year_()
{}

date::date(int32 day_, int32 month_, int32 year_)
  : day_(day_)
  , month_(month_)
  , year_(year_)
{}

const std::int32_t date::ID;

void date::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "date");
    s.store_field("day", day_);
    s.store_field("month", month_);
    s.store_field("year", year_);
    s.store_class_end();
  }
}

dateRange::dateRange()
  : start_date_()
  , end_date_()
{}

dateRange::dateRange(int32 start_date_, int32 end_date_)
  : start_date_(start_date_)
  , end_date_(end_date_)
{}

const std::int32_t dateRange::ID;

void dateRange::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateRange");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_class_end();
  }
}

datedFile::datedFile()
  : file_()
  , date_()
{}

datedFile::datedFile(object_ptr<file> &&file_, int32 date_)
  : file_(std::move(file_))
  , date_(date_)
{}

const std::int32_t datedFile::ID;

void datedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "datedFile");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

deepLinkInfo::deepLinkInfo()
  : text_()
  , need_update_application_()
{}

deepLinkInfo::deepLinkInfo(object_ptr<formattedText> &&text_, bool need_update_application_)
  : text_(std::move(text_))
  , need_update_application_(need_update_application_)
{}

const std::int32_t deepLinkInfo::ID;

void deepLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deepLinkInfo");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("need_update_application", need_update_application_);
    s.store_class_end();
  }
}

deviceTokenFirebaseCloudMessaging::deviceTokenFirebaseCloudMessaging()
  : token_()
  , encrypt_()
{}

deviceTokenFirebaseCloudMessaging::deviceTokenFirebaseCloudMessaging(string const &token_, bool encrypt_)
  : token_(token_)
  , encrypt_(encrypt_)
{}

const std::int32_t deviceTokenFirebaseCloudMessaging::ID;

void deviceTokenFirebaseCloudMessaging::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenFirebaseCloudMessaging");
    s.store_field("token", token_);
    s.store_field("encrypt", encrypt_);
    s.store_class_end();
  }
}

deviceTokenApplePush::deviceTokenApplePush()
  : device_token_()
  , is_app_sandbox_()
{}

deviceTokenApplePush::deviceTokenApplePush(string const &device_token_, bool is_app_sandbox_)
  : device_token_(device_token_)
  , is_app_sandbox_(is_app_sandbox_)
{}

const std::int32_t deviceTokenApplePush::ID;

void deviceTokenApplePush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenApplePush");
    s.store_field("device_token", device_token_);
    s.store_field("is_app_sandbox", is_app_sandbox_);
    s.store_class_end();
  }
}

deviceTokenApplePushVoIP::deviceTokenApplePushVoIP()
  : device_token_()
  , is_app_sandbox_()
  , encrypt_()
{}

deviceTokenApplePushVoIP::deviceTokenApplePushVoIP(string const &device_token_, bool is_app_sandbox_, bool encrypt_)
  : device_token_(device_token_)
  , is_app_sandbox_(is_app_sandbox_)
  , encrypt_(encrypt_)
{}

const std::int32_t deviceTokenApplePushVoIP::ID;

void deviceTokenApplePushVoIP::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenApplePushVoIP");
    s.store_field("device_token", device_token_);
    s.store_field("is_app_sandbox", is_app_sandbox_);
    s.store_field("encrypt", encrypt_);
    s.store_class_end();
  }
}

deviceTokenWindowsPush::deviceTokenWindowsPush()
  : access_token_()
{}

deviceTokenWindowsPush::deviceTokenWindowsPush(string const &access_token_)
  : access_token_(access_token_)
{}

const std::int32_t deviceTokenWindowsPush::ID;

void deviceTokenWindowsPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenWindowsPush");
    s.store_field("access_token", access_token_);
    s.store_class_end();
  }
}

deviceTokenMicrosoftPush::deviceTokenMicrosoftPush()
  : channel_uri_()
{}

deviceTokenMicrosoftPush::deviceTokenMicrosoftPush(string const &channel_uri_)
  : channel_uri_(channel_uri_)
{}

const std::int32_t deviceTokenMicrosoftPush::ID;

void deviceTokenMicrosoftPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenMicrosoftPush");
    s.store_field("channel_uri", channel_uri_);
    s.store_class_end();
  }
}

deviceTokenMicrosoftPushVoIP::deviceTokenMicrosoftPushVoIP()
  : channel_uri_()
{}

deviceTokenMicrosoftPushVoIP::deviceTokenMicrosoftPushVoIP(string const &channel_uri_)
  : channel_uri_(channel_uri_)
{}

const std::int32_t deviceTokenMicrosoftPushVoIP::ID;

void deviceTokenMicrosoftPushVoIP::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenMicrosoftPushVoIP");
    s.store_field("channel_uri", channel_uri_);
    s.store_class_end();
  }
}

deviceTokenWebPush::deviceTokenWebPush()
  : endpoint_()
  , p256dh_base64url_()
  , auth_base64url_()
{}

deviceTokenWebPush::deviceTokenWebPush(string const &endpoint_, string const &p256dh_base64url_, string const &auth_base64url_)
  : endpoint_(endpoint_)
  , p256dh_base64url_(p256dh_base64url_)
  , auth_base64url_(auth_base64url_)
{}

const std::int32_t deviceTokenWebPush::ID;

void deviceTokenWebPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenWebPush");
    s.store_field("endpoint", endpoint_);
    s.store_field("p256dh_base64url", p256dh_base64url_);
    s.store_field("auth_base64url", auth_base64url_);
    s.store_class_end();
  }
}

deviceTokenSimplePush::deviceTokenSimplePush()
  : endpoint_()
{}

deviceTokenSimplePush::deviceTokenSimplePush(string const &endpoint_)
  : endpoint_(endpoint_)
{}

const std::int32_t deviceTokenSimplePush::ID;

void deviceTokenSimplePush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenSimplePush");
    s.store_field("endpoint", endpoint_);
    s.store_class_end();
  }
}

deviceTokenUbuntuPush::deviceTokenUbuntuPush()
  : token_()
{}

deviceTokenUbuntuPush::deviceTokenUbuntuPush(string const &token_)
  : token_(token_)
{}

const std::int32_t deviceTokenUbuntuPush::ID;

void deviceTokenUbuntuPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenUbuntuPush");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

deviceTokenBlackBerryPush::deviceTokenBlackBerryPush()
  : token_()
{}

deviceTokenBlackBerryPush::deviceTokenBlackBerryPush(string const &token_)
  : token_(token_)
{}

const std::int32_t deviceTokenBlackBerryPush::ID;

void deviceTokenBlackBerryPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenBlackBerryPush");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

deviceTokenTizenPush::deviceTokenTizenPush()
  : reg_id_()
{}

deviceTokenTizenPush::deviceTokenTizenPush(string const &reg_id_)
  : reg_id_(reg_id_)
{}

const std::int32_t deviceTokenTizenPush::ID;

void deviceTokenTizenPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenTizenPush");
    s.store_field("reg_id", reg_id_);
    s.store_class_end();
  }
}

diceStickersRegular::diceStickersRegular()
  : sticker_()
{}

diceStickersRegular::diceStickersRegular(object_ptr<sticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t diceStickersRegular::ID;

void diceStickersRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diceStickersRegular");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

diceStickersSlotMachine::diceStickersSlotMachine()
  : background_()
  , lever_()
  , left_reel_()
  , center_reel_()
  , right_reel_()
{}

diceStickersSlotMachine::diceStickersSlotMachine(object_ptr<sticker> &&background_, object_ptr<sticker> &&lever_, object_ptr<sticker> &&left_reel_, object_ptr<sticker> &&center_reel_, object_ptr<sticker> &&right_reel_)
  : background_(std::move(background_))
  , lever_(std::move(lever_))
  , left_reel_(std::move(left_reel_))
  , center_reel_(std::move(center_reel_))
  , right_reel_(std::move(right_reel_))
{}

const std::int32_t diceStickersSlotMachine::ID;

void diceStickersSlotMachine::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diceStickersSlotMachine");
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("lever", static_cast<const BaseObject *>(lever_.get()));
    s.store_object_field("left_reel", static_cast<const BaseObject *>(left_reel_.get()));
    s.store_object_field("center_reel", static_cast<const BaseObject *>(center_reel_.get()));
    s.store_object_field("right_reel", static_cast<const BaseObject *>(right_reel_.get()));
    s.store_class_end();
  }
}

document::document()
  : file_name_()
  , mime_type_()
  , minithumbnail_()
  , thumbnail_()
  , document_()
{}

document::document(string const &file_name_, string const &mime_type_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&document_)
  : file_name_(file_name_)
  , mime_type_(mime_type_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , document_(std::move(document_))
{}

const std::int32_t document::ID;

void document::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "document");
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_class_end();
  }
}

downloadedFileCounts::downloadedFileCounts()
  : active_count_()
  , paused_count_()
  , completed_count_()
{}

downloadedFileCounts::downloadedFileCounts(int32 active_count_, int32 paused_count_, int32 completed_count_)
  : active_count_(active_count_)
  , paused_count_(paused_count_)
  , completed_count_(completed_count_)
{}

const std::int32_t downloadedFileCounts::ID;

void downloadedFileCounts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "downloadedFileCounts");
    s.store_field("active_count", active_count_);
    s.store_field("paused_count", paused_count_);
    s.store_field("completed_count", completed_count_);
    s.store_class_end();
  }
}

draftMessage::draftMessage()
  : reply_to_message_id_()
  , date_()
  , input_message_text_()
{}

draftMessage::draftMessage(int53 reply_to_message_id_, int32 date_, object_ptr<InputMessageContent> &&input_message_text_)
  : reply_to_message_id_(reply_to_message_id_)
  , date_(date_)
  , input_message_text_(std::move(input_message_text_))
{}

const std::int32_t draftMessage::ID;

void draftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessage");
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_field("date", date_);
    s.store_object_field("input_message_text", static_cast<const BaseObject *>(input_message_text_.get()));
    s.store_class_end();
  }
}

emailAddressAuthenticationCodeInfo::emailAddressAuthenticationCodeInfo()
  : email_address_pattern_()
  , length_()
{}

emailAddressAuthenticationCodeInfo::emailAddressAuthenticationCodeInfo(string const &email_address_pattern_, int32 length_)
  : email_address_pattern_(email_address_pattern_)
  , length_(length_)
{}

const std::int32_t emailAddressAuthenticationCodeInfo::ID;

void emailAddressAuthenticationCodeInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressAuthenticationCodeInfo");
    s.store_field("email_address_pattern", email_address_pattern_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

emojis::emojis()
  : emojis_()
{}

emojis::emojis(array<string> &&emojis_)
  : emojis_(std::move(emojis_))
{}

const std::int32_t emojis::ID;

void emojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojis");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

encryptedCredentials::encryptedCredentials()
  : data_()
  , hash_()
  , secret_()
{}

encryptedCredentials::encryptedCredentials(bytes const &data_, bytes const &hash_, bytes const &secret_)
  : data_(std::move(data_))
  , hash_(std::move(hash_))
  , secret_(std::move(secret_))
{}

const std::int32_t encryptedCredentials::ID;

void encryptedCredentials::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedCredentials");
    s.store_bytes_field("data", data_);
    s.store_bytes_field("hash", hash_);
    s.store_bytes_field("secret", secret_);
    s.store_class_end();
  }
}

encryptedPassportElement::encryptedPassportElement()
  : type_()
  , data_()
  , front_side_()
  , reverse_side_()
  , selfie_()
  , translation_()
  , files_()
  , value_()
  , hash_()
{}

encryptedPassportElement::encryptedPassportElement(object_ptr<PassportElementType> &&type_, bytes const &data_, object_ptr<datedFile> &&front_side_, object_ptr<datedFile> &&reverse_side_, object_ptr<datedFile> &&selfie_, array<object_ptr<datedFile>> &&translation_, array<object_ptr<datedFile>> &&files_, string const &value_, string const &hash_)
  : type_(std::move(type_))
  , data_(std::move(data_))
  , front_side_(std::move(front_side_))
  , reverse_side_(std::move(reverse_side_))
  , selfie_(std::move(selfie_))
  , translation_(std::move(translation_))
  , files_(std::move(files_))
  , value_(value_)
  , hash_(hash_)
{}

const std::int32_t encryptedPassportElement::ID;

void encryptedPassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedPassportElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("data", data_);
    s.store_object_field("front_side", static_cast<const BaseObject *>(front_side_.get()));
    s.store_object_field("reverse_side", static_cast<const BaseObject *>(reverse_side_.get()));
    s.store_object_field("selfie", static_cast<const BaseObject *>(selfie_.get()));
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("value", value_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

error::error()
  : code_()
  , message_()
{}

error::error(int32 code_, string const &message_)
  : code_(code_)
  , message_(message_)
{}

const std::int32_t error::ID;

void error::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "error");
    s.store_field("code", code_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

file::file()
  : id_()
  , size_()
  , expected_size_()
  , local_()
  , remote_()
{}

file::file(int32 id_, int32 size_, int32 expected_size_, object_ptr<localFile> &&local_, object_ptr<remoteFile> &&remote_)
  : id_(id_)
  , size_(size_)
  , expected_size_(expected_size_)
  , local_(std::move(local_))
  , remote_(std::move(remote_))
{}

const std::int32_t file::ID;

void file::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "file");
    s.store_field("id", id_);
    s.store_field("size", size_);
    s.store_field("expected_size", expected_size_);
    s.store_object_field("local", static_cast<const BaseObject *>(local_.get()));
    s.store_object_field("remote", static_cast<const BaseObject *>(remote_.get()));
    s.store_class_end();
  }
}

fileDownload::fileDownload()
  : file_id_()
  , message_()
  , add_date_()
  , complete_date_()
  , is_paused_()
{}

fileDownload::fileDownload(int32 file_id_, object_ptr<message> &&message_, int32 add_date_, int32 complete_date_, bool is_paused_)
  : file_id_(file_id_)
  , message_(std::move(message_))
  , add_date_(add_date_)
  , complete_date_(complete_date_)
  , is_paused_(is_paused_)
{}

const std::int32_t fileDownload::ID;

void fileDownload::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileDownload");
    s.store_field("file_id", file_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("add_date", add_date_);
    s.store_field("complete_date", complete_date_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

filePart::filePart()
  : data_()
{}

filePart::filePart(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t filePart::ID;

void filePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "filePart");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

fileTypeNone::fileTypeNone() {
}

const std::int32_t fileTypeNone::ID;

void fileTypeNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeNone");
    s.store_class_end();
  }
}

fileTypeAnimation::fileTypeAnimation() {
}

const std::int32_t fileTypeAnimation::ID;

void fileTypeAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeAnimation");
    s.store_class_end();
  }
}

fileTypeAudio::fileTypeAudio() {
}

const std::int32_t fileTypeAudio::ID;

void fileTypeAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeAudio");
    s.store_class_end();
  }
}

fileTypeDocument::fileTypeDocument() {
}

const std::int32_t fileTypeDocument::ID;

void fileTypeDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeDocument");
    s.store_class_end();
  }
}

fileTypeNotificationSound::fileTypeNotificationSound() {
}

const std::int32_t fileTypeNotificationSound::ID;

void fileTypeNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeNotificationSound");
    s.store_class_end();
  }
}

fileTypePhoto::fileTypePhoto() {
}

const std::int32_t fileTypePhoto::ID;

void fileTypePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypePhoto");
    s.store_class_end();
  }
}

fileTypeProfilePhoto::fileTypeProfilePhoto() {
}

const std::int32_t fileTypeProfilePhoto::ID;

void fileTypeProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeProfilePhoto");
    s.store_class_end();
  }
}

fileTypeSecret::fileTypeSecret() {
}

const std::int32_t fileTypeSecret::ID;

void fileTypeSecret::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSecret");
    s.store_class_end();
  }
}

fileTypeSecretThumbnail::fileTypeSecretThumbnail() {
}

const std::int32_t fileTypeSecretThumbnail::ID;

void fileTypeSecretThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSecretThumbnail");
    s.store_class_end();
  }
}

fileTypeSecure::fileTypeSecure() {
}

const std::int32_t fileTypeSecure::ID;

void fileTypeSecure::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSecure");
    s.store_class_end();
  }
}

fileTypeSticker::fileTypeSticker() {
}

const std::int32_t fileTypeSticker::ID;

void fileTypeSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeSticker");
    s.store_class_end();
  }
}

fileTypeThumbnail::fileTypeThumbnail() {
}

const std::int32_t fileTypeThumbnail::ID;

void fileTypeThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeThumbnail");
    s.store_class_end();
  }
}

fileTypeUnknown::fileTypeUnknown() {
}

const std::int32_t fileTypeUnknown::ID;

void fileTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeUnknown");
    s.store_class_end();
  }
}

fileTypeVideo::fileTypeVideo() {
}

const std::int32_t fileTypeVideo::ID;

void fileTypeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeVideo");
    s.store_class_end();
  }
}

fileTypeVideoNote::fileTypeVideoNote() {
}

const std::int32_t fileTypeVideoNote::ID;

void fileTypeVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeVideoNote");
    s.store_class_end();
  }
}

fileTypeVoiceNote::fileTypeVoiceNote() {
}

const std::int32_t fileTypeVoiceNote::ID;

void fileTypeVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeVoiceNote");
    s.store_class_end();
  }
}

fileTypeWallpaper::fileTypeWallpaper() {
}

const std::int32_t fileTypeWallpaper::ID;

void fileTypeWallpaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileTypeWallpaper");
    s.store_class_end();
  }
}

formattedText::formattedText()
  : text_()
  , entities_()
{}

formattedText::formattedText(string const &text_, array<object_ptr<textEntity>> &&entities_)
  : text_(text_)
  , entities_(std::move(entities_))
{}

const std::int32_t formattedText::ID;

void formattedText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "formattedText");
    s.store_field("text", text_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

foundFileDownloads::foundFileDownloads()
  : total_counts_()
  , files_()
  , next_offset_()
{}

foundFileDownloads::foundFileDownloads(object_ptr<downloadedFileCounts> &&total_counts_, array<object_ptr<fileDownload>> &&files_, string const &next_offset_)
  : total_counts_(std::move(total_counts_))
  , files_(std::move(files_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundFileDownloads::ID;

void foundFileDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundFileDownloads");
    s.store_object_field("total_counts", static_cast<const BaseObject *>(total_counts_.get()));
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

foundMessages::foundMessages()
  : total_count_()
  , messages_()
  , next_offset_()
{}

foundMessages::foundMessages(int32 total_count_, array<object_ptr<message>> &&messages_, string const &next_offset_)
  : total_count_(total_count_)
  , messages_(std::move(messages_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundMessages::ID;

void foundMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundMessages");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

game::game()
  : id_()
  , short_name_()
  , title_()
  , text_()
  , description_()
  , photo_()
  , animation_()
{}

game::game(int64 id_, string const &short_name_, string const &title_, object_ptr<formattedText> &&text_, string const &description_, object_ptr<photo> &&photo_, object_ptr<animation> &&animation_)
  : id_(id_)
  , short_name_(short_name_)
  , title_(title_)
  , text_(std::move(text_))
  , description_(description_)
  , photo_(std::move(photo_))
  , animation_(std::move(animation_))
{}

const std::int32_t game::ID;

void game::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "game");
    s.store_field("id", id_);
    s.store_field("short_name", short_name_);
    s.store_field("title", title_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

gameHighScore::gameHighScore()
  : position_()
  , user_id_()
  , score_()
{}

gameHighScore::gameHighScore(int32 position_, int53 user_id_, int32 score_)
  : position_(position_)
  , user_id_(user_id_)
  , score_(score_)
{}

const std::int32_t gameHighScore::ID;

void gameHighScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "gameHighScore");
    s.store_field("position", position_);
    s.store_field("user_id", user_id_);
    s.store_field("score", score_);
    s.store_class_end();
  }
}

gameHighScores::gameHighScores()
  : scores_()
{}

gameHighScores::gameHighScores(array<object_ptr<gameHighScore>> &&scores_)
  : scores_(std::move(scores_))
{}

const std::int32_t gameHighScores::ID;

void gameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "gameHighScores");
    { s.store_vector_begin("scores", scores_.size()); for (const auto &_value : scores_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

groupCall::groupCall()
  : id_()
  , title_()
  , scheduled_start_date_()
  , enabled_start_notification_()
  , is_active_()
  , is_rtmp_stream_()
  , is_joined_()
  , need_rejoin_()
  , can_be_managed_()
  , participant_count_()
  , has_hidden_listeners_()
  , loaded_all_participants_()
  , recent_speakers_()
  , is_my_video_enabled_()
  , is_my_video_paused_()
  , can_enable_video_()
  , mute_new_participants_()
  , can_toggle_mute_new_participants_()
  , record_duration_()
  , is_video_recorded_()
  , duration_()
{}

groupCall::groupCall(int32 id_, string const &title_, int32 scheduled_start_date_, bool enabled_start_notification_, bool is_active_, bool is_rtmp_stream_, bool is_joined_, bool need_rejoin_, bool can_be_managed_, int32 participant_count_, bool has_hidden_listeners_, bool loaded_all_participants_, array<object_ptr<groupCallRecentSpeaker>> &&recent_speakers_, bool is_my_video_enabled_, bool is_my_video_paused_, bool can_enable_video_, bool mute_new_participants_, bool can_toggle_mute_new_participants_, int32 record_duration_, bool is_video_recorded_, int32 duration_)
  : id_(id_)
  , title_(title_)
  , scheduled_start_date_(scheduled_start_date_)
  , enabled_start_notification_(enabled_start_notification_)
  , is_active_(is_active_)
  , is_rtmp_stream_(is_rtmp_stream_)
  , is_joined_(is_joined_)
  , need_rejoin_(need_rejoin_)
  , can_be_managed_(can_be_managed_)
  , participant_count_(participant_count_)
  , has_hidden_listeners_(has_hidden_listeners_)
  , loaded_all_participants_(loaded_all_participants_)
  , recent_speakers_(std::move(recent_speakers_))
  , is_my_video_enabled_(is_my_video_enabled_)
  , is_my_video_paused_(is_my_video_paused_)
  , can_enable_video_(can_enable_video_)
  , mute_new_participants_(mute_new_participants_)
  , can_toggle_mute_new_participants_(can_toggle_mute_new_participants_)
  , record_duration_(record_duration_)
  , is_video_recorded_(is_video_recorded_)
  , duration_(duration_)
{}

const std::int32_t groupCall::ID;

void groupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCall");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("scheduled_start_date", scheduled_start_date_);
    s.store_field("enabled_start_notification", enabled_start_notification_);
    s.store_field("is_active", is_active_);
    s.store_field("is_rtmp_stream", is_rtmp_stream_);
    s.store_field("is_joined", is_joined_);
    s.store_field("need_rejoin", need_rejoin_);
    s.store_field("can_be_managed", can_be_managed_);
    s.store_field("participant_count", participant_count_);
    s.store_field("has_hidden_listeners", has_hidden_listeners_);
    s.store_field("loaded_all_participants", loaded_all_participants_);
    { s.store_vector_begin("recent_speakers", recent_speakers_.size()); for (const auto &_value : recent_speakers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_my_video_enabled", is_my_video_enabled_);
    s.store_field("is_my_video_paused", is_my_video_paused_);
    s.store_field("can_enable_video", can_enable_video_);
    s.store_field("mute_new_participants", mute_new_participants_);
    s.store_field("can_toggle_mute_new_participants", can_toggle_mute_new_participants_);
    s.store_field("record_duration", record_duration_);
    s.store_field("is_video_recorded", is_video_recorded_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

groupCallId::groupCallId()
  : id_()
{}

groupCallId::groupCallId(int32 id_)
  : id_(id_)
{}

const std::int32_t groupCallId::ID;

void groupCallId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

groupCallParticipant::groupCallParticipant()
  : participant_id_()
  , audio_source_id_()
  , screen_sharing_audio_source_id_()
  , video_info_()
  , screen_sharing_video_info_()
  , bio_()
  , is_current_user_()
  , is_speaking_()
  , is_hand_raised_()
  , can_be_muted_for_all_users_()
  , can_be_unmuted_for_all_users_()
  , can_be_muted_for_current_user_()
  , can_be_unmuted_for_current_user_()
  , is_muted_for_all_users_()
  , is_muted_for_current_user_()
  , can_unmute_self_()
  , volume_level_()
  , order_()
{}

groupCallParticipant::groupCallParticipant(object_ptr<MessageSender> &&participant_id_, int32 audio_source_id_, int32 screen_sharing_audio_source_id_, object_ptr<groupCallParticipantVideoInfo> &&video_info_, object_ptr<groupCallParticipantVideoInfo> &&screen_sharing_video_info_, string const &bio_, bool is_current_user_, bool is_speaking_, bool is_hand_raised_, bool can_be_muted_for_all_users_, bool can_be_unmuted_for_all_users_, bool can_be_muted_for_current_user_, bool can_be_unmuted_for_current_user_, bool is_muted_for_all_users_, bool is_muted_for_current_user_, bool can_unmute_self_, int32 volume_level_, string const &order_)
  : participant_id_(std::move(participant_id_))
  , audio_source_id_(audio_source_id_)
  , screen_sharing_audio_source_id_(screen_sharing_audio_source_id_)
  , video_info_(std::move(video_info_))
  , screen_sharing_video_info_(std::move(screen_sharing_video_info_))
  , bio_(bio_)
  , is_current_user_(is_current_user_)
  , is_speaking_(is_speaking_)
  , is_hand_raised_(is_hand_raised_)
  , can_be_muted_for_all_users_(can_be_muted_for_all_users_)
  , can_be_unmuted_for_all_users_(can_be_unmuted_for_all_users_)
  , can_be_muted_for_current_user_(can_be_muted_for_current_user_)
  , can_be_unmuted_for_current_user_(can_be_unmuted_for_current_user_)
  , is_muted_for_all_users_(is_muted_for_all_users_)
  , is_muted_for_current_user_(is_muted_for_current_user_)
  , can_unmute_self_(can_unmute_self_)
  , volume_level_(volume_level_)
  , order_(order_)
{}

const std::int32_t groupCallParticipant::ID;

void groupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipant");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("audio_source_id", audio_source_id_);
    s.store_field("screen_sharing_audio_source_id", screen_sharing_audio_source_id_);
    s.store_object_field("video_info", static_cast<const BaseObject *>(video_info_.get()));
    s.store_object_field("screen_sharing_video_info", static_cast<const BaseObject *>(screen_sharing_video_info_.get()));
    s.store_field("bio", bio_);
    s.store_field("is_current_user", is_current_user_);
    s.store_field("is_speaking", is_speaking_);
    s.store_field("is_hand_raised", is_hand_raised_);
    s.store_field("can_be_muted_for_all_users", can_be_muted_for_all_users_);
    s.store_field("can_be_unmuted_for_all_users", can_be_unmuted_for_all_users_);
    s.store_field("can_be_muted_for_current_user", can_be_muted_for_current_user_);
    s.store_field("can_be_unmuted_for_current_user", can_be_unmuted_for_current_user_);
    s.store_field("is_muted_for_all_users", is_muted_for_all_users_);
    s.store_field("is_muted_for_current_user", is_muted_for_current_user_);
    s.store_field("can_unmute_self", can_unmute_self_);
    s.store_field("volume_level", volume_level_);
    s.store_field("order", order_);
    s.store_class_end();
  }
}

groupCallParticipantVideoInfo::groupCallParticipantVideoInfo()
  : source_groups_()
  , endpoint_id_()
  , is_paused_()
{}

groupCallParticipantVideoInfo::groupCallParticipantVideoInfo(array<object_ptr<groupCallVideoSourceGroup>> &&source_groups_, string const &endpoint_id_, bool is_paused_)
  : source_groups_(std::move(source_groups_))
  , endpoint_id_(endpoint_id_)
  , is_paused_(is_paused_)
{}

const std::int32_t groupCallParticipantVideoInfo::ID;

void groupCallParticipantVideoInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipantVideoInfo");
    { s.store_vector_begin("source_groups", source_groups_.size()); for (const auto &_value : source_groups_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("endpoint_id", endpoint_id_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

groupCallRecentSpeaker::groupCallRecentSpeaker()
  : participant_id_()
  , is_speaking_()
{}

groupCallRecentSpeaker::groupCallRecentSpeaker(object_ptr<MessageSender> &&participant_id_, bool is_speaking_)
  : participant_id_(std::move(participant_id_))
  , is_speaking_(is_speaking_)
{}

const std::int32_t groupCallRecentSpeaker::ID;

void groupCallRecentSpeaker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallRecentSpeaker");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_speaking", is_speaking_);
    s.store_class_end();
  }
}

groupCallStream::groupCallStream()
  : channel_id_()
  , scale_()
  , time_offset_()
{}

groupCallStream::groupCallStream(int32 channel_id_, int32 scale_, int53 time_offset_)
  : channel_id_(channel_id_)
  , scale_(scale_)
  , time_offset_(time_offset_)
{}

const std::int32_t groupCallStream::ID;

void groupCallStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallStream");
    s.store_field("channel_id", channel_id_);
    s.store_field("scale", scale_);
    s.store_field("time_offset", time_offset_);
    s.store_class_end();
  }
}

groupCallStreams::groupCallStreams()
  : streams_()
{}

groupCallStreams::groupCallStreams(array<object_ptr<groupCallStream>> &&streams_)
  : streams_(std::move(streams_))
{}

const std::int32_t groupCallStreams::ID;

void groupCallStreams::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallStreams");
    { s.store_vector_begin("streams", streams_.size()); for (const auto &_value : streams_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

groupCallVideoQualityThumbnail::groupCallVideoQualityThumbnail() {
}

const std::int32_t groupCallVideoQualityThumbnail::ID;

void groupCallVideoQualityThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoQualityThumbnail");
    s.store_class_end();
  }
}

groupCallVideoQualityMedium::groupCallVideoQualityMedium() {
}

const std::int32_t groupCallVideoQualityMedium::ID;

void groupCallVideoQualityMedium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoQualityMedium");
    s.store_class_end();
  }
}

groupCallVideoQualityFull::groupCallVideoQualityFull() {
}

const std::int32_t groupCallVideoQualityFull::ID;

void groupCallVideoQualityFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoQualityFull");
    s.store_class_end();
  }
}

groupCallVideoSourceGroup::groupCallVideoSourceGroup()
  : semantics_()
  , source_ids_()
{}

groupCallVideoSourceGroup::groupCallVideoSourceGroup(string const &semantics_, array<int32> &&source_ids_)
  : semantics_(semantics_)
  , source_ids_(std::move(source_ids_))
{}

const std::int32_t groupCallVideoSourceGroup::ID;

void groupCallVideoSourceGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoSourceGroup");
    s.store_field("semantics", semantics_);
    { s.store_vector_begin("source_ids", source_ids_.size()); for (const auto &_value : source_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

hashtags::hashtags()
  : hashtags_()
{}

hashtags::hashtags(array<string> &&hashtags_)
  : hashtags_(std::move(hashtags_))
{}

const std::int32_t hashtags::ID;

void hashtags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "hashtags");
    { s.store_vector_begin("hashtags", hashtags_.size()); for (const auto &_value : hashtags_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

httpUrl::httpUrl()
  : url_()
{}

httpUrl::httpUrl(string const &url_)
  : url_(url_)
{}

const std::int32_t httpUrl::ID;

void httpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "httpUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

identityDocument::identityDocument()
  : number_()
  , expiry_date_()
  , front_side_()
  , reverse_side_()
  , selfie_()
  , translation_()
{}

identityDocument::identityDocument(string const &number_, object_ptr<date> &&expiry_date_, object_ptr<datedFile> &&front_side_, object_ptr<datedFile> &&reverse_side_, object_ptr<datedFile> &&selfie_, array<object_ptr<datedFile>> &&translation_)
  : number_(number_)
  , expiry_date_(std::move(expiry_date_))
  , front_side_(std::move(front_side_))
  , reverse_side_(std::move(reverse_side_))
  , selfie_(std::move(selfie_))
  , translation_(std::move(translation_))
{}

const std::int32_t identityDocument::ID;

void identityDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "identityDocument");
    s.store_field("number", number_);
    s.store_object_field("expiry_date", static_cast<const BaseObject *>(expiry_date_.get()));
    s.store_object_field("front_side", static_cast<const BaseObject *>(front_side_.get()));
    s.store_object_field("reverse_side", static_cast<const BaseObject *>(reverse_side_.get()));
    s.store_object_field("selfie", static_cast<const BaseObject *>(selfie_.get()));
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

importedContacts::importedContacts()
  : user_ids_()
  , importer_count_()
{}

importedContacts::importedContacts(array<int53> &&user_ids_, array<int32> &&importer_count_)
  : user_ids_(std::move(user_ids_))
  , importer_count_(std::move(importer_count_))
{}

const std::int32_t importedContacts::ID;

void importedContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importedContacts");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("importer_count", importer_count_.size()); for (const auto &_value : importer_count_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inlineKeyboardButton::inlineKeyboardButton()
  : text_()
  , type_()
{}

inlineKeyboardButton::inlineKeyboardButton(string const &text_, object_ptr<InlineKeyboardButtonType> &&type_)
  : text_(text_)
  , type_(std::move(type_))
{}

const std::int32_t inlineKeyboardButton::ID;

void inlineKeyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButton");
    s.store_field("text", text_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeUrl::inlineKeyboardButtonTypeUrl()
  : url_()
{}

inlineKeyboardButtonTypeUrl::inlineKeyboardButtonTypeUrl(string const &url_)
  : url_(url_)
{}

const std::int32_t inlineKeyboardButtonTypeUrl::ID;

void inlineKeyboardButtonTypeUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeLoginUrl::inlineKeyboardButtonTypeLoginUrl()
  : url_()
  , id_()
  , forward_text_()
{}

inlineKeyboardButtonTypeLoginUrl::inlineKeyboardButtonTypeLoginUrl(string const &url_, int53 id_, string const &forward_text_)
  : url_(url_)
  , id_(id_)
  , forward_text_(forward_text_)
{}

const std::int32_t inlineKeyboardButtonTypeLoginUrl::ID;

void inlineKeyboardButtonTypeLoginUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeLoginUrl");
    s.store_field("url", url_);
    s.store_field("id", id_);
    s.store_field("forward_text", forward_text_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeWebApp::inlineKeyboardButtonTypeWebApp()
  : url_()
{}

inlineKeyboardButtonTypeWebApp::inlineKeyboardButtonTypeWebApp(string const &url_)
  : url_(url_)
{}

const std::int32_t inlineKeyboardButtonTypeWebApp::ID;

void inlineKeyboardButtonTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeWebApp");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeCallback::inlineKeyboardButtonTypeCallback()
  : data_()
{}

inlineKeyboardButtonTypeCallback::inlineKeyboardButtonTypeCallback(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t inlineKeyboardButtonTypeCallback::ID;

void inlineKeyboardButtonTypeCallback::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeCallback");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeCallbackWithPassword::inlineKeyboardButtonTypeCallbackWithPassword()
  : data_()
{}

inlineKeyboardButtonTypeCallbackWithPassword::inlineKeyboardButtonTypeCallbackWithPassword(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t inlineKeyboardButtonTypeCallbackWithPassword::ID;

void inlineKeyboardButtonTypeCallbackWithPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeCallbackWithPassword");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeCallbackGame::inlineKeyboardButtonTypeCallbackGame() {
}

const std::int32_t inlineKeyboardButtonTypeCallbackGame::ID;

void inlineKeyboardButtonTypeCallbackGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeCallbackGame");
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeSwitchInline::inlineKeyboardButtonTypeSwitchInline()
  : query_()
  , in_current_chat_()
{}

inlineKeyboardButtonTypeSwitchInline::inlineKeyboardButtonTypeSwitchInline(string const &query_, bool in_current_chat_)
  : query_(query_)
  , in_current_chat_(in_current_chat_)
{}

const std::int32_t inlineKeyboardButtonTypeSwitchInline::ID;

void inlineKeyboardButtonTypeSwitchInline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeSwitchInline");
    s.store_field("query", query_);
    s.store_field("in_current_chat", in_current_chat_);
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeBuy::inlineKeyboardButtonTypeBuy() {
}

const std::int32_t inlineKeyboardButtonTypeBuy::ID;

void inlineKeyboardButtonTypeBuy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeBuy");
    s.store_class_end();
  }
}

inlineKeyboardButtonTypeUser::inlineKeyboardButtonTypeUser()
  : user_id_()
{}

inlineKeyboardButtonTypeUser::inlineKeyboardButtonTypeUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t inlineKeyboardButtonTypeUser::ID;

void inlineKeyboardButtonTypeUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButtonTypeUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

inlineQueryResultArticle::inlineQueryResultArticle()
  : id_()
  , url_()
  , hide_url_()
  , title_()
  , description_()
  , thumbnail_()
{}

inlineQueryResultArticle::inlineQueryResultArticle(string const &id_, string const &url_, bool hide_url_, string const &title_, string const &description_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , url_(url_)
  , hide_url_(hide_url_)
  , title_(title_)
  , description_(description_)
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultArticle::ID;

void inlineQueryResultArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultArticle");
    s.store_field("id", id_);
    s.store_field("url", url_);
    s.store_field("hide_url", hide_url_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultContact::inlineQueryResultContact()
  : id_()
  , contact_()
  , thumbnail_()
{}

inlineQueryResultContact::inlineQueryResultContact(string const &id_, object_ptr<contact> &&contact_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , contact_(std::move(contact_))
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultContact::ID;

void inlineQueryResultContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultContact");
    s.store_field("id", id_);
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultLocation::inlineQueryResultLocation()
  : id_()
  , location_()
  , title_()
  , thumbnail_()
{}

inlineQueryResultLocation::inlineQueryResultLocation(string const &id_, object_ptr<location> &&location_, string const &title_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , location_(std::move(location_))
  , title_(title_)
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultLocation::ID;

void inlineQueryResultLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultLocation");
    s.store_field("id", id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("title", title_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultVenue::inlineQueryResultVenue()
  : id_()
  , venue_()
  , thumbnail_()
{}

inlineQueryResultVenue::inlineQueryResultVenue(string const &id_, object_ptr<venue> &&venue_, object_ptr<thumbnail> &&thumbnail_)
  : id_(id_)
  , venue_(std::move(venue_))
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t inlineQueryResultVenue::ID;

void inlineQueryResultVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultVenue");
    s.store_field("id", id_);
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

inlineQueryResultGame::inlineQueryResultGame()
  : id_()
  , game_()
{}

inlineQueryResultGame::inlineQueryResultGame(string const &id_, object_ptr<game> &&game_)
  : id_(id_)
  , game_(std::move(game_))
{}

const std::int32_t inlineQueryResultGame::ID;

void inlineQueryResultGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultGame");
    s.store_field("id", id_);
    s.store_object_field("game", static_cast<const BaseObject *>(game_.get()));
    s.store_class_end();
  }
}

inlineQueryResultAnimation::inlineQueryResultAnimation()
  : id_()
  , animation_()
  , title_()
{}

inlineQueryResultAnimation::inlineQueryResultAnimation(string const &id_, object_ptr<animation> &&animation_, string const &title_)
  : id_(id_)
  , animation_(std::move(animation_))
  , title_(title_)
{}

const std::int32_t inlineQueryResultAnimation::ID;

void inlineQueryResultAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultAnimation");
    s.store_field("id", id_);
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

inlineQueryResultAudio::inlineQueryResultAudio()
  : id_()
  , audio_()
{}

inlineQueryResultAudio::inlineQueryResultAudio(string const &id_, object_ptr<audio> &&audio_)
  : id_(id_)
  , audio_(std::move(audio_))
{}

const std::int32_t inlineQueryResultAudio::ID;

void inlineQueryResultAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultAudio");
    s.store_field("id", id_);
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_class_end();
  }
}

inlineQueryResultDocument::inlineQueryResultDocument()
  : id_()
  , document_()
  , title_()
  , description_()
{}

inlineQueryResultDocument::inlineQueryResultDocument(string const &id_, object_ptr<document> &&document_, string const &title_, string const &description_)
  : id_(id_)
  , document_(std::move(document_))
  , title_(title_)
  , description_(description_)
{}

const std::int32_t inlineQueryResultDocument::ID;

void inlineQueryResultDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultDocument");
    s.store_field("id", id_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

inlineQueryResultPhoto::inlineQueryResultPhoto()
  : id_()
  , photo_()
  , title_()
  , description_()
{}

inlineQueryResultPhoto::inlineQueryResultPhoto(string const &id_, object_ptr<photo> &&photo_, string const &title_, string const &description_)
  : id_(id_)
  , photo_(std::move(photo_))
  , title_(title_)
  , description_(description_)
{}

const std::int32_t inlineQueryResultPhoto::ID;

void inlineQueryResultPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultPhoto");
    s.store_field("id", id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

inlineQueryResultSticker::inlineQueryResultSticker()
  : id_()
  , sticker_()
{}

inlineQueryResultSticker::inlineQueryResultSticker(string const &id_, object_ptr<sticker> &&sticker_)
  : id_(id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t inlineQueryResultSticker::ID;

void inlineQueryResultSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultSticker");
    s.store_field("id", id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

inlineQueryResultVideo::inlineQueryResultVideo()
  : id_()
  , video_()
  , title_()
  , description_()
{}

inlineQueryResultVideo::inlineQueryResultVideo(string const &id_, object_ptr<video> &&video_, string const &title_, string const &description_)
  : id_(id_)
  , video_(std::move(video_))
  , title_(title_)
  , description_(description_)
{}

const std::int32_t inlineQueryResultVideo::ID;

void inlineQueryResultVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultVideo");
    s.store_field("id", id_);
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

inlineQueryResultVoiceNote::inlineQueryResultVoiceNote()
  : id_()
  , voice_note_()
  , title_()
{}

inlineQueryResultVoiceNote::inlineQueryResultVoiceNote(string const &id_, object_ptr<voiceNote> &&voice_note_, string const &title_)
  : id_(id_)
  , voice_note_(std::move(voice_note_))
  , title_(title_)
{}

const std::int32_t inlineQueryResultVoiceNote::ID;

void inlineQueryResultVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultVoiceNote");
    s.store_field("id", id_);
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

inlineQueryResults::inlineQueryResults()
  : inline_query_id_()
  , next_offset_()
  , results_()
  , switch_pm_text_()
  , switch_pm_parameter_()
{}

inlineQueryResults::inlineQueryResults(int64 inline_query_id_, string const &next_offset_, array<object_ptr<InlineQueryResult>> &&results_, string const &switch_pm_text_, string const &switch_pm_parameter_)
  : inline_query_id_(inline_query_id_)
  , next_offset_(next_offset_)
  , results_(std::move(results_))
  , switch_pm_text_(switch_pm_text_)
  , switch_pm_parameter_(switch_pm_parameter_)
{}

const std::int32_t inlineQueryResults::ID;

void inlineQueryResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResults");
    s.store_field("inline_query_id", inline_query_id_);
    s.store_field("next_offset", next_offset_);
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("switch_pm_text", switch_pm_text_);
    s.store_field("switch_pm_parameter", switch_pm_parameter_);
    s.store_class_end();
  }
}

inputBackgroundLocal::inputBackgroundLocal()
  : background_()
{}

inputBackgroundLocal::inputBackgroundLocal(object_ptr<InputFile> &&background_)
  : background_(std::move(background_))
{}

const std::int32_t inputBackgroundLocal::ID;

void inputBackgroundLocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBackgroundLocal");
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_class_end();
  }
}

inputBackgroundRemote::inputBackgroundRemote()
  : background_id_()
{}

inputBackgroundRemote::inputBackgroundRemote(int64 background_id_)
  : background_id_(background_id_)
{}

const std::int32_t inputBackgroundRemote::ID;

void inputBackgroundRemote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBackgroundRemote");
    s.store_field("background_id", background_id_);
    s.store_class_end();
  }
}

inputChatPhotoPrevious::inputChatPhotoPrevious()
  : chat_photo_id_()
{}

inputChatPhotoPrevious::inputChatPhotoPrevious(int64 chat_photo_id_)
  : chat_photo_id_(chat_photo_id_)
{}

const std::int32_t inputChatPhotoPrevious::ID;

void inputChatPhotoPrevious::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoPrevious");
    s.store_field("chat_photo_id", chat_photo_id_);
    s.store_class_end();
  }
}

inputChatPhotoStatic::inputChatPhotoStatic()
  : photo_()
{}

inputChatPhotoStatic::inputChatPhotoStatic(object_ptr<InputFile> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t inputChatPhotoStatic::ID;

void inputChatPhotoStatic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoStatic");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

inputChatPhotoAnimation::inputChatPhotoAnimation()
  : animation_()
  , main_frame_timestamp_()
{}

inputChatPhotoAnimation::inputChatPhotoAnimation(object_ptr<InputFile> &&animation_, double main_frame_timestamp_)
  : animation_(std::move(animation_))
  , main_frame_timestamp_(main_frame_timestamp_)
{}

const std::int32_t inputChatPhotoAnimation::ID;

void inputChatPhotoAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_field("main_frame_timestamp", main_frame_timestamp_);
    s.store_class_end();
  }
}

inputCredentialsSaved::inputCredentialsSaved()
  : saved_credentials_id_()
{}

inputCredentialsSaved::inputCredentialsSaved(string const &saved_credentials_id_)
  : saved_credentials_id_(saved_credentials_id_)
{}

const std::int32_t inputCredentialsSaved::ID;

void inputCredentialsSaved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsSaved");
    s.store_field("saved_credentials_id", saved_credentials_id_);
    s.store_class_end();
  }
}

inputCredentialsNew::inputCredentialsNew()
  : data_()
  , allow_save_()
{}

inputCredentialsNew::inputCredentialsNew(string const &data_, bool allow_save_)
  : data_(data_)
  , allow_save_(allow_save_)
{}

const std::int32_t inputCredentialsNew::ID;

void inputCredentialsNew::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsNew");
    s.store_field("data", data_);
    s.store_field("allow_save", allow_save_);
    s.store_class_end();
  }
}

inputCredentialsApplePay::inputCredentialsApplePay()
  : data_()
{}

inputCredentialsApplePay::inputCredentialsApplePay(string const &data_)
  : data_(data_)
{}

const std::int32_t inputCredentialsApplePay::ID;

void inputCredentialsApplePay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsApplePay");
    s.store_field("data", data_);
    s.store_class_end();
  }
}

inputCredentialsGooglePay::inputCredentialsGooglePay()
  : data_()
{}

inputCredentialsGooglePay::inputCredentialsGooglePay(string const &data_)
  : data_(data_)
{}

const std::int32_t inputCredentialsGooglePay::ID;

void inputCredentialsGooglePay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsGooglePay");
    s.store_field("data", data_);
    s.store_class_end();
  }
}

inputFileId::inputFileId()
  : id_()
{}

inputFileId::inputFileId(int32 id_)
  : id_(id_)
{}

const std::int32_t inputFileId::ID;

void inputFileId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputFileRemote::inputFileRemote()
  : id_()
{}

inputFileRemote::inputFileRemote(string const &id_)
  : id_(id_)
{}

const std::int32_t inputFileRemote::ID;

void inputFileRemote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileRemote");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputFileLocal::inputFileLocal()
  : path_()
{}

inputFileLocal::inputFileLocal(string const &path_)
  : path_(path_)
{}

const std::int32_t inputFileLocal::ID;

void inputFileLocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileLocal");
    s.store_field("path", path_);
    s.store_class_end();
  }
}

inputFileGenerated::inputFileGenerated()
  : original_path_()
  , conversion_()
  , expected_size_()
{}

inputFileGenerated::inputFileGenerated(string const &original_path_, string const &conversion_, int32 expected_size_)
  : original_path_(original_path_)
  , conversion_(conversion_)
  , expected_size_(expected_size_)
{}

const std::int32_t inputFileGenerated::ID;

void inputFileGenerated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileGenerated");
    s.store_field("original_path", original_path_);
    s.store_field("conversion", conversion_);
    s.store_field("expected_size", expected_size_);
    s.store_class_end();
  }
}

inputIdentityDocument::inputIdentityDocument()
  : number_()
  , expiry_date_()
  , front_side_()
  , reverse_side_()
  , selfie_()
  , translation_()
{}

inputIdentityDocument::inputIdentityDocument(string const &number_, object_ptr<date> &&expiry_date_, object_ptr<InputFile> &&front_side_, object_ptr<InputFile> &&reverse_side_, object_ptr<InputFile> &&selfie_, array<object_ptr<InputFile>> &&translation_)
  : number_(number_)
  , expiry_date_(std::move(expiry_date_))
  , front_side_(std::move(front_side_))
  , reverse_side_(std::move(reverse_side_))
  , selfie_(std::move(selfie_))
  , translation_(std::move(translation_))
{}

const std::int32_t inputIdentityDocument::ID;

void inputIdentityDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputIdentityDocument");
    s.store_field("number", number_);
    s.store_object_field("expiry_date", static_cast<const BaseObject *>(expiry_date_.get()));
    s.store_object_field("front_side", static_cast<const BaseObject *>(front_side_.get()));
    s.store_object_field("reverse_side", static_cast<const BaseObject *>(reverse_side_.get()));
    s.store_object_field("selfie", static_cast<const BaseObject *>(selfie_.get()));
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputInlineQueryResultAnimation::inputInlineQueryResultAnimation()
  : id_()
  , title_()
  , thumbnail_url_()
  , thumbnail_mime_type_()
  , video_url_()
  , video_mime_type_()
  , video_duration_()
  , video_width_()
  , video_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultAnimation::inputInlineQueryResultAnimation(string const &id_, string const &title_, string const &thumbnail_url_, string const &thumbnail_mime_type_, string const &video_url_, string const &video_mime_type_, int32 video_duration_, int32 video_width_, int32 video_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_mime_type_(thumbnail_mime_type_)
  , video_url_(video_url_)
  , video_mime_type_(video_mime_type_)
  , video_duration_(video_duration_)
  , video_width_(video_width_)
  , video_height_(video_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultAnimation::ID;

void inputInlineQueryResultAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultAnimation");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_mime_type", thumbnail_mime_type_);
    s.store_field("video_url", video_url_);
    s.store_field("video_mime_type", video_mime_type_);
    s.store_field("video_duration", video_duration_);
    s.store_field("video_width", video_width_);
    s.store_field("video_height", video_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultArticle::inputInlineQueryResultArticle()
  : id_()
  , url_()
  , hide_url_()
  , title_()
  , description_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultArticle::inputInlineQueryResultArticle(string const &id_, string const &url_, bool hide_url_, string const &title_, string const &description_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , url_(url_)
  , hide_url_(hide_url_)
  , title_(title_)
  , description_(description_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultArticle::ID;

void inputInlineQueryResultArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultArticle");
    s.store_field("id", id_);
    s.store_field("url", url_);
    s.store_field("hide_url", hide_url_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultAudio::inputInlineQueryResultAudio()
  : id_()
  , title_()
  , performer_()
  , audio_url_()
  , audio_duration_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultAudio::inputInlineQueryResultAudio(string const &id_, string const &title_, string const &performer_, string const &audio_url_, int32 audio_duration_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , performer_(performer_)
  , audio_url_(audio_url_)
  , audio_duration_(audio_duration_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultAudio::ID;

void inputInlineQueryResultAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultAudio");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("performer", performer_);
    s.store_field("audio_url", audio_url_);
    s.store_field("audio_duration", audio_duration_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultContact::inputInlineQueryResultContact()
  : id_()
  , contact_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultContact::inputInlineQueryResultContact(string const &id_, object_ptr<contact> &&contact_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , contact_(std::move(contact_))
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultContact::ID;

void inputInlineQueryResultContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultContact");
    s.store_field("id", id_);
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultDocument::inputInlineQueryResultDocument()
  : id_()
  , title_()
  , description_()
  , document_url_()
  , mime_type_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultDocument::inputInlineQueryResultDocument(string const &id_, string const &title_, string const &description_, string const &document_url_, string const &mime_type_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , description_(description_)
  , document_url_(document_url_)
  , mime_type_(mime_type_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultDocument::ID;

void inputInlineQueryResultDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultDocument");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("document_url", document_url_);
    s.store_field("mime_type", mime_type_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultGame::inputInlineQueryResultGame()
  : id_()
  , game_short_name_()
  , reply_markup_()
{}

inputInlineQueryResultGame::inputInlineQueryResultGame(string const &id_, string const &game_short_name_, object_ptr<ReplyMarkup> &&reply_markup_)
  : id_(id_)
  , game_short_name_(game_short_name_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputInlineQueryResultGame::ID;

void inputInlineQueryResultGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultGame");
    s.store_field("id", id_);
    s.store_field("game_short_name", game_short_name_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultLocation::inputInlineQueryResultLocation()
  : id_()
  , location_()
  , live_period_()
  , title_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultLocation::inputInlineQueryResultLocation(string const &id_, object_ptr<location> &&location_, int32 live_period_, string const &title_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , location_(std::move(location_))
  , live_period_(live_period_)
  , title_(title_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultLocation::ID;

void inputInlineQueryResultLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultLocation");
    s.store_field("id", id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("live_period", live_period_);
    s.store_field("title", title_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultPhoto::inputInlineQueryResultPhoto()
  : id_()
  , title_()
  , description_()
  , thumbnail_url_()
  , photo_url_()
  , photo_width_()
  , photo_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultPhoto::inputInlineQueryResultPhoto(string const &id_, string const &title_, string const &description_, string const &thumbnail_url_, string const &photo_url_, int32 photo_width_, int32 photo_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , description_(description_)
  , thumbnail_url_(thumbnail_url_)
  , photo_url_(photo_url_)
  , photo_width_(photo_width_)
  , photo_height_(photo_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultPhoto::ID;

void inputInlineQueryResultPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultPhoto");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("photo_url", photo_url_);
    s.store_field("photo_width", photo_width_);
    s.store_field("photo_height", photo_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultSticker::inputInlineQueryResultSticker()
  : id_()
  , thumbnail_url_()
  , sticker_url_()
  , sticker_width_()
  , sticker_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultSticker::inputInlineQueryResultSticker(string const &id_, string const &thumbnail_url_, string const &sticker_url_, int32 sticker_width_, int32 sticker_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , thumbnail_url_(thumbnail_url_)
  , sticker_url_(sticker_url_)
  , sticker_width_(sticker_width_)
  , sticker_height_(sticker_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultSticker::ID;

void inputInlineQueryResultSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultSticker");
    s.store_field("id", id_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("sticker_url", sticker_url_);
    s.store_field("sticker_width", sticker_width_);
    s.store_field("sticker_height", sticker_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultVenue::inputInlineQueryResultVenue()
  : id_()
  , venue_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultVenue::inputInlineQueryResultVenue(string const &id_, object_ptr<venue> &&venue_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , venue_(std::move(venue_))
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultVenue::ID;

void inputInlineQueryResultVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultVenue");
    s.store_field("id", id_);
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultVideo::inputInlineQueryResultVideo()
  : id_()
  , title_()
  , description_()
  , thumbnail_url_()
  , video_url_()
  , mime_type_()
  , video_width_()
  , video_height_()
  , video_duration_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultVideo::inputInlineQueryResultVideo(string const &id_, string const &title_, string const &description_, string const &thumbnail_url_, string const &video_url_, string const &mime_type_, int32 video_width_, int32 video_height_, int32 video_duration_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , description_(description_)
  , thumbnail_url_(thumbnail_url_)
  , video_url_(video_url_)
  , mime_type_(mime_type_)
  , video_width_(video_width_)
  , video_height_(video_height_)
  , video_duration_(video_duration_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultVideo::ID;

void inputInlineQueryResultVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultVideo");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("video_url", video_url_);
    s.store_field("mime_type", mime_type_);
    s.store_field("video_width", video_width_);
    s.store_field("video_height", video_height_);
    s.store_field("video_duration", video_duration_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultVoiceNote::inputInlineQueryResultVoiceNote()
  : id_()
  , title_()
  , voice_note_url_()
  , voice_note_duration_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultVoiceNote::inputInlineQueryResultVoiceNote(string const &id_, string const &title_, string const &voice_note_url_, int32 voice_note_duration_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , voice_note_url_(voice_note_url_)
  , voice_note_duration_(voice_note_duration_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultVoiceNote::ID;

void inputInlineQueryResultVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultVoiceNote");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("voice_note_url", voice_note_url_);
    s.store_field("voice_note_duration", voice_note_duration_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputMessageText::inputMessageText()
  : text_()
  , disable_web_page_preview_()
  , clear_draft_()
{}

inputMessageText::inputMessageText(object_ptr<formattedText> &&text_, bool disable_web_page_preview_, bool clear_draft_)
  : text_(std::move(text_))
  , disable_web_page_preview_(disable_web_page_preview_)
  , clear_draft_(clear_draft_)
{}

const std::int32_t inputMessageText::ID;

void inputMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("disable_web_page_preview", disable_web_page_preview_);
    s.store_field("clear_draft", clear_draft_);
    s.store_class_end();
  }
}

inputMessageAnimation::inputMessageAnimation()
  : animation_()
  , thumbnail_()
  , added_sticker_file_ids_()
  , duration_()
  , width_()
  , height_()
  , caption_()
{}

inputMessageAnimation::inputMessageAnimation(object_ptr<InputFile> &&animation_, object_ptr<inputThumbnail> &&thumbnail_, array<int32> &&added_sticker_file_ids_, int32 duration_, int32 width_, int32 height_, object_ptr<formattedText> &&caption_)
  : animation_(std::move(animation_))
  , thumbnail_(std::move(thumbnail_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
  , caption_(std::move(caption_))
{}

const std::int32_t inputMessageAnimation::ID;

void inputMessageAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputMessageAudio::inputMessageAudio()
  : audio_()
  , album_cover_thumbnail_()
  , duration_()
  , title_()
  , performer_()
  , caption_()
{}

inputMessageAudio::inputMessageAudio(object_ptr<InputFile> &&audio_, object_ptr<inputThumbnail> &&album_cover_thumbnail_, int32 duration_, string const &title_, string const &performer_, object_ptr<formattedText> &&caption_)
  : audio_(std::move(audio_))
  , album_cover_thumbnail_(std::move(album_cover_thumbnail_))
  , duration_(duration_)
  , title_(title_)
  , performer_(performer_)
  , caption_(std::move(caption_))
{}

const std::int32_t inputMessageAudio::ID;

void inputMessageAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("album_cover_thumbnail", static_cast<const BaseObject *>(album_cover_thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("title", title_);
    s.store_field("performer", performer_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputMessageDocument::inputMessageDocument()
  : document_()
  , thumbnail_()
  , disable_content_type_detection_()
  , caption_()
{}

inputMessageDocument::inputMessageDocument(object_ptr<InputFile> &&document_, object_ptr<inputThumbnail> &&thumbnail_, bool disable_content_type_detection_, object_ptr<formattedText> &&caption_)
  : document_(std::move(document_))
  , thumbnail_(std::move(thumbnail_))
  , disable_content_type_detection_(disable_content_type_detection_)
  , caption_(std::move(caption_))
{}

const std::int32_t inputMessageDocument::ID;

void inputMessageDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("disable_content_type_detection", disable_content_type_detection_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputMessagePhoto::inputMessagePhoto()
  : photo_()
  , thumbnail_()
  , added_sticker_file_ids_()
  , width_()
  , height_()
  , caption_()
  , ttl_()
{}

inputMessagePhoto::inputMessagePhoto(object_ptr<InputFile> &&photo_, object_ptr<inputThumbnail> &&thumbnail_, array<int32> &&added_sticker_file_ids_, int32 width_, int32 height_, object_ptr<formattedText> &&caption_, int32 ttl_)
  : photo_(std::move(photo_))
  , thumbnail_(std::move(thumbnail_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , width_(width_)
  , height_(height_)
  , caption_(std::move(caption_))
  , ttl_(ttl_)
{}

const std::int32_t inputMessagePhoto::ID;

void inputMessagePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("ttl", ttl_);
    s.store_class_end();
  }
}

inputMessageSticker::inputMessageSticker()
  : sticker_()
  , thumbnail_()
  , width_()
  , height_()
  , emoji_()
{}

inputMessageSticker::inputMessageSticker(object_ptr<InputFile> &&sticker_, object_ptr<inputThumbnail> &&thumbnail_, int32 width_, int32 height_, string const &emoji_)
  : sticker_(std::move(sticker_))
  , thumbnail_(std::move(thumbnail_))
  , width_(width_)
  , height_(height_)
  , emoji_(emoji_)
{}

const std::int32_t inputMessageSticker::ID;

void inputMessageSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

inputMessageVideo::inputMessageVideo()
  : video_()
  , thumbnail_()
  , added_sticker_file_ids_()
  , duration_()
  , width_()
  , height_()
  , supports_streaming_()
  , caption_()
  , ttl_()
{}

inputMessageVideo::inputMessageVideo(object_ptr<InputFile> &&video_, object_ptr<inputThumbnail> &&thumbnail_, array<int32> &&added_sticker_file_ids_, int32 duration_, int32 width_, int32 height_, bool supports_streaming_, object_ptr<formattedText> &&caption_, int32 ttl_)
  : video_(std::move(video_))
  , thumbnail_(std::move(thumbnail_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
  , supports_streaming_(supports_streaming_)
  , caption_(std::move(caption_))
  , ttl_(ttl_)
{}

const std::int32_t inputMessageVideo::ID;

void inputMessageVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("supports_streaming", supports_streaming_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("ttl", ttl_);
    s.store_class_end();
  }
}

inputMessageVideoNote::inputMessageVideoNote()
  : video_note_()
  , thumbnail_()
  , duration_()
  , length_()
{}

inputMessageVideoNote::inputMessageVideoNote(object_ptr<InputFile> &&video_note_, object_ptr<inputThumbnail> &&thumbnail_, int32 duration_, int32 length_)
  : video_note_(std::move(video_note_))
  , thumbnail_(std::move(thumbnail_))
  , duration_(duration_)
  , length_(length_)
{}

const std::int32_t inputMessageVideoNote::ID;

void inputMessageVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

inputMessageVoiceNote::inputMessageVoiceNote()
  : voice_note_()
  , duration_()
  , waveform_()
  , caption_()
{}

inputMessageVoiceNote::inputMessageVoiceNote(object_ptr<InputFile> &&voice_note_, int32 duration_, bytes const &waveform_, object_ptr<formattedText> &&caption_)
  : voice_note_(std::move(voice_note_))
  , duration_(duration_)
  , waveform_(std::move(waveform_))
  , caption_(std::move(caption_))
{}

const std::int32_t inputMessageVoiceNote::ID;

void inputMessageVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_field("duration", duration_);
    s.store_bytes_field("waveform", waveform_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputMessageLocation::inputMessageLocation()
  : location_()
  , live_period_()
  , heading_()
  , proximity_alert_radius_()
{}

inputMessageLocation::inputMessageLocation(object_ptr<location> &&location_, int32 live_period_, int32 heading_, int32 proximity_alert_radius_)
  : location_(std::move(location_))
  , live_period_(live_period_)
  , heading_(heading_)
  , proximity_alert_radius_(proximity_alert_radius_)
{}

const std::int32_t inputMessageLocation::ID;

void inputMessageLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("live_period", live_period_);
    s.store_field("heading", heading_);
    s.store_field("proximity_alert_radius", proximity_alert_radius_);
    s.store_class_end();
  }
}

inputMessageVenue::inputMessageVenue()
  : venue_()
{}

inputMessageVenue::inputMessageVenue(object_ptr<venue> &&venue_)
  : venue_(std::move(venue_))
{}

const std::int32_t inputMessageVenue::ID;

void inputMessageVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVenue");
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_class_end();
  }
}

inputMessageContact::inputMessageContact()
  : contact_()
{}

inputMessageContact::inputMessageContact(object_ptr<contact> &&contact_)
  : contact_(std::move(contact_))
{}

const std::int32_t inputMessageContact::ID;

void inputMessageContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageContact");
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_class_end();
  }
}

inputMessageDice::inputMessageDice()
  : emoji_()
  , clear_draft_()
{}

inputMessageDice::inputMessageDice(string const &emoji_, bool clear_draft_)
  : emoji_(emoji_)
  , clear_draft_(clear_draft_)
{}

const std::int32_t inputMessageDice::ID;

void inputMessageDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageDice");
    s.store_field("emoji", emoji_);
    s.store_field("clear_draft", clear_draft_);
    s.store_class_end();
  }
}

inputMessageGame::inputMessageGame()
  : bot_user_id_()
  , game_short_name_()
{}

inputMessageGame::inputMessageGame(int53 bot_user_id_, string const &game_short_name_)
  : bot_user_id_(bot_user_id_)
  , game_short_name_(game_short_name_)
{}

const std::int32_t inputMessageGame::ID;

void inputMessageGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageGame");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("game_short_name", game_short_name_);
    s.store_class_end();
  }
}

inputMessageInvoice::inputMessageInvoice()
  : invoice_()
  , title_()
  , description_()
  , photo_url_()
  , photo_size_()
  , photo_width_()
  , photo_height_()
  , payload_()
  , provider_token_()
  , provider_data_()
  , start_parameter_()
{}

inputMessageInvoice::inputMessageInvoice(object_ptr<invoice> &&invoice_, string const &title_, string const &description_, string const &photo_url_, int32 photo_size_, int32 photo_width_, int32 photo_height_, bytes const &payload_, string const &provider_token_, string const &provider_data_, string const &start_parameter_)
  : invoice_(std::move(invoice_))
  , title_(title_)
  , description_(description_)
  , photo_url_(photo_url_)
  , photo_size_(photo_size_)
  , photo_width_(photo_width_)
  , photo_height_(photo_height_)
  , payload_(std::move(payload_))
  , provider_token_(provider_token_)
  , provider_data_(provider_data_)
  , start_parameter_(start_parameter_)
{}

const std::int32_t inputMessageInvoice::ID;

void inputMessageInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageInvoice");
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("photo_url", photo_url_);
    s.store_field("photo_size", photo_size_);
    s.store_field("photo_width", photo_width_);
    s.store_field("photo_height", photo_height_);
    s.store_bytes_field("payload", payload_);
    s.store_field("provider_token", provider_token_);
    s.store_field("provider_data", provider_data_);
    s.store_field("start_parameter", start_parameter_);
    s.store_class_end();
  }
}

inputMessagePoll::inputMessagePoll()
  : question_()
  , options_()
  , is_anonymous_()
  , type_()
  , open_period_()
  , close_date_()
  , is_closed_()
{}

inputMessagePoll::inputMessagePoll(string const &question_, array<string> &&options_, bool is_anonymous_, object_ptr<PollType> &&type_, int32 open_period_, int32 close_date_, bool is_closed_)
  : question_(question_)
  , options_(std::move(options_))
  , is_anonymous_(is_anonymous_)
  , type_(std::move(type_))
  , open_period_(open_period_)
  , close_date_(close_date_)
  , is_closed_(is_closed_)
{}

const std::int32_t inputMessagePoll::ID;

void inputMessagePoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagePoll");
    s.store_field("question", question_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("is_anonymous", is_anonymous_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("open_period", open_period_);
    s.store_field("close_date", close_date_);
    s.store_field("is_closed", is_closed_);
    s.store_class_end();
  }
}

inputMessageForwarded::inputMessageForwarded()
  : from_chat_id_()
  , message_id_()
  , in_game_share_()
  , copy_options_()
{}

inputMessageForwarded::inputMessageForwarded(int53 from_chat_id_, int53 message_id_, bool in_game_share_, object_ptr<messageCopyOptions> &&copy_options_)
  : from_chat_id_(from_chat_id_)
  , message_id_(message_id_)
  , in_game_share_(in_game_share_)
  , copy_options_(std::move(copy_options_))
{}

const std::int32_t inputMessageForwarded::ID;

void inputMessageForwarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageForwarded");
    s.store_field("from_chat_id", from_chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("in_game_share", in_game_share_);
    s.store_object_field("copy_options", static_cast<const BaseObject *>(copy_options_.get()));
    s.store_class_end();
  }
}

inputPassportElementPersonalDetails::inputPassportElementPersonalDetails()
  : personal_details_()
{}

inputPassportElementPersonalDetails::inputPassportElementPersonalDetails(object_ptr<personalDetails> &&personal_details_)
  : personal_details_(std::move(personal_details_))
{}

const std::int32_t inputPassportElementPersonalDetails::ID;

void inputPassportElementPersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPersonalDetails");
    s.store_object_field("personal_details", static_cast<const BaseObject *>(personal_details_.get()));
    s.store_class_end();
  }
}

inputPassportElementPassport::inputPassportElementPassport()
  : passport_()
{}

inputPassportElementPassport::inputPassportElementPassport(object_ptr<inputIdentityDocument> &&passport_)
  : passport_(std::move(passport_))
{}

const std::int32_t inputPassportElementPassport::ID;

void inputPassportElementPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPassport");
    s.store_object_field("passport", static_cast<const BaseObject *>(passport_.get()));
    s.store_class_end();
  }
}

inputPassportElementDriverLicense::inputPassportElementDriverLicense()
  : driver_license_()
{}

inputPassportElementDriverLicense::inputPassportElementDriverLicense(object_ptr<inputIdentityDocument> &&driver_license_)
  : driver_license_(std::move(driver_license_))
{}

const std::int32_t inputPassportElementDriverLicense::ID;

void inputPassportElementDriverLicense::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementDriverLicense");
    s.store_object_field("driver_license", static_cast<const BaseObject *>(driver_license_.get()));
    s.store_class_end();
  }
}

inputPassportElementIdentityCard::inputPassportElementIdentityCard()
  : identity_card_()
{}

inputPassportElementIdentityCard::inputPassportElementIdentityCard(object_ptr<inputIdentityDocument> &&identity_card_)
  : identity_card_(std::move(identity_card_))
{}

const std::int32_t inputPassportElementIdentityCard::ID;

void inputPassportElementIdentityCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementIdentityCard");
    s.store_object_field("identity_card", static_cast<const BaseObject *>(identity_card_.get()));
    s.store_class_end();
  }
}

inputPassportElementInternalPassport::inputPassportElementInternalPassport()
  : internal_passport_()
{}

inputPassportElementInternalPassport::inputPassportElementInternalPassport(object_ptr<inputIdentityDocument> &&internal_passport_)
  : internal_passport_(std::move(internal_passport_))
{}

const std::int32_t inputPassportElementInternalPassport::ID;

void inputPassportElementInternalPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementInternalPassport");
    s.store_object_field("internal_passport", static_cast<const BaseObject *>(internal_passport_.get()));
    s.store_class_end();
  }
}

inputPassportElementAddress::inputPassportElementAddress()
  : address_()
{}

inputPassportElementAddress::inputPassportElementAddress(object_ptr<address> &&address_)
  : address_(std::move(address_))
{}

const std::int32_t inputPassportElementAddress::ID;

void inputPassportElementAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementAddress");
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_class_end();
  }
}

inputPassportElementUtilityBill::inputPassportElementUtilityBill()
  : utility_bill_()
{}

inputPassportElementUtilityBill::inputPassportElementUtilityBill(object_ptr<inputPersonalDocument> &&utility_bill_)
  : utility_bill_(std::move(utility_bill_))
{}

const std::int32_t inputPassportElementUtilityBill::ID;

void inputPassportElementUtilityBill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementUtilityBill");
    s.store_object_field("utility_bill", static_cast<const BaseObject *>(utility_bill_.get()));
    s.store_class_end();
  }
}

inputPassportElementBankStatement::inputPassportElementBankStatement()
  : bank_statement_()
{}

inputPassportElementBankStatement::inputPassportElementBankStatement(object_ptr<inputPersonalDocument> &&bank_statement_)
  : bank_statement_(std::move(bank_statement_))
{}

const std::int32_t inputPassportElementBankStatement::ID;

void inputPassportElementBankStatement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementBankStatement");
    s.store_object_field("bank_statement", static_cast<const BaseObject *>(bank_statement_.get()));
    s.store_class_end();
  }
}

inputPassportElementRentalAgreement::inputPassportElementRentalAgreement()
  : rental_agreement_()
{}

inputPassportElementRentalAgreement::inputPassportElementRentalAgreement(object_ptr<inputPersonalDocument> &&rental_agreement_)
  : rental_agreement_(std::move(rental_agreement_))
{}

const std::int32_t inputPassportElementRentalAgreement::ID;

void inputPassportElementRentalAgreement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementRentalAgreement");
    s.store_object_field("rental_agreement", static_cast<const BaseObject *>(rental_agreement_.get()));
    s.store_class_end();
  }
}

inputPassportElementPassportRegistration::inputPassportElementPassportRegistration()
  : passport_registration_()
{}

inputPassportElementPassportRegistration::inputPassportElementPassportRegistration(object_ptr<inputPersonalDocument> &&passport_registration_)
  : passport_registration_(std::move(passport_registration_))
{}

const std::int32_t inputPassportElementPassportRegistration::ID;

void inputPassportElementPassportRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPassportRegistration");
    s.store_object_field("passport_registration", static_cast<const BaseObject *>(passport_registration_.get()));
    s.store_class_end();
  }
}

inputPassportElementTemporaryRegistration::inputPassportElementTemporaryRegistration()
  : temporary_registration_()
{}

inputPassportElementTemporaryRegistration::inputPassportElementTemporaryRegistration(object_ptr<inputPersonalDocument> &&temporary_registration_)
  : temporary_registration_(std::move(temporary_registration_))
{}

const std::int32_t inputPassportElementTemporaryRegistration::ID;

void inputPassportElementTemporaryRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementTemporaryRegistration");
    s.store_object_field("temporary_registration", static_cast<const BaseObject *>(temporary_registration_.get()));
    s.store_class_end();
  }
}

inputPassportElementPhoneNumber::inputPassportElementPhoneNumber()
  : phone_number_()
{}

inputPassportElementPhoneNumber::inputPassportElementPhoneNumber(string const &phone_number_)
  : phone_number_(phone_number_)
{}

const std::int32_t inputPassportElementPhoneNumber::ID;

void inputPassportElementPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

inputPassportElementEmailAddress::inputPassportElementEmailAddress()
  : email_address_()
{}

inputPassportElementEmailAddress::inputPassportElementEmailAddress(string const &email_address_)
  : email_address_(email_address_)
{}

const std::int32_t inputPassportElementEmailAddress::ID;

void inputPassportElementEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementEmailAddress");
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

inputPassportElementError::inputPassportElementError()
  : type_()
  , message_()
  , source_()
{}

inputPassportElementError::inputPassportElementError(object_ptr<PassportElementType> &&type_, string const &message_, object_ptr<InputPassportElementErrorSource> &&source_)
  : type_(std::move(type_))
  , message_(message_)
  , source_(std::move(source_))
{}

const std::int32_t inputPassportElementError::ID;

void inputPassportElementError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementError");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("message", message_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

inputPassportElementErrorSourceUnspecified::inputPassportElementErrorSourceUnspecified()
  : element_hash_()
{}

inputPassportElementErrorSourceUnspecified::inputPassportElementErrorSourceUnspecified(bytes const &element_hash_)
  : element_hash_(std::move(element_hash_))
{}

const std::int32_t inputPassportElementErrorSourceUnspecified::ID;

void inputPassportElementErrorSourceUnspecified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceUnspecified");
    s.store_bytes_field("element_hash", element_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceDataField::inputPassportElementErrorSourceDataField()
  : field_name_()
  , data_hash_()
{}

inputPassportElementErrorSourceDataField::inputPassportElementErrorSourceDataField(string const &field_name_, bytes const &data_hash_)
  : field_name_(field_name_)
  , data_hash_(std::move(data_hash_))
{}

const std::int32_t inputPassportElementErrorSourceDataField::ID;

void inputPassportElementErrorSourceDataField::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceDataField");
    s.store_field("field_name", field_name_);
    s.store_bytes_field("data_hash", data_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceFrontSide::inputPassportElementErrorSourceFrontSide()
  : file_hash_()
{}

inputPassportElementErrorSourceFrontSide::inputPassportElementErrorSourceFrontSide(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceFrontSide::ID;

void inputPassportElementErrorSourceFrontSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceFrontSide");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceReverseSide::inputPassportElementErrorSourceReverseSide()
  : file_hash_()
{}

inputPassportElementErrorSourceReverseSide::inputPassportElementErrorSourceReverseSide(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceReverseSide::ID;

void inputPassportElementErrorSourceReverseSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceReverseSide");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceSelfie::inputPassportElementErrorSourceSelfie()
  : file_hash_()
{}

inputPassportElementErrorSourceSelfie::inputPassportElementErrorSourceSelfie(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceSelfie::ID;

void inputPassportElementErrorSourceSelfie::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceSelfie");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceTranslationFile::inputPassportElementErrorSourceTranslationFile()
  : file_hash_()
{}

inputPassportElementErrorSourceTranslationFile::inputPassportElementErrorSourceTranslationFile(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceTranslationFile::ID;

void inputPassportElementErrorSourceTranslationFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceTranslationFile");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceTranslationFiles::inputPassportElementErrorSourceTranslationFiles()
  : file_hashes_()
{}

inputPassportElementErrorSourceTranslationFiles::inputPassportElementErrorSourceTranslationFiles(array<bytes> &&file_hashes_)
  : file_hashes_(std::move(file_hashes_))
{}

const std::int32_t inputPassportElementErrorSourceTranslationFiles::ID;

void inputPassportElementErrorSourceTranslationFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceTranslationFiles");
    { s.store_vector_begin("file_hashes", file_hashes_.size()); for (const auto &_value : file_hashes_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPassportElementErrorSourceFile::inputPassportElementErrorSourceFile()
  : file_hash_()
{}

inputPassportElementErrorSourceFile::inputPassportElementErrorSourceFile(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceFile::ID;

void inputPassportElementErrorSourceFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceFile");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceFiles::inputPassportElementErrorSourceFiles()
  : file_hashes_()
{}

inputPassportElementErrorSourceFiles::inputPassportElementErrorSourceFiles(array<bytes> &&file_hashes_)
  : file_hashes_(std::move(file_hashes_))
{}

const std::int32_t inputPassportElementErrorSourceFiles::ID;

void inputPassportElementErrorSourceFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceFiles");
    { s.store_vector_begin("file_hashes", file_hashes_.size()); for (const auto &_value : file_hashes_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPersonalDocument::inputPersonalDocument()
  : files_()
  , translation_()
{}

inputPersonalDocument::inputPersonalDocument(array<object_ptr<InputFile>> &&files_, array<object_ptr<InputFile>> &&translation_)
  : files_(std::move(files_))
  , translation_(std::move(translation_))
{}

const std::int32_t inputPersonalDocument::ID;

void inputPersonalDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPersonalDocument");
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputSticker::inputSticker()
  : sticker_()
  , emojis_()
  , type_()
{}

inputSticker::inputSticker(object_ptr<InputFile> &&sticker_, string const &emojis_, object_ptr<StickerType> &&type_)
  : sticker_(std::move(sticker_))
  , emojis_(emojis_)
  , type_(std::move(type_))
{}

const std::int32_t inputSticker::ID;

void inputSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("emojis", emojis_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

inputThumbnail::inputThumbnail()
  : thumbnail_()
  , width_()
  , height_()
{}

inputThumbnail::inputThumbnail(object_ptr<InputFile> &&thumbnail_, int32 width_, int32 height_)
  : thumbnail_(std::move(thumbnail_))
  , width_(width_)
  , height_(height_)
{}

const std::int32_t inputThumbnail::ID;

void inputThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputThumbnail");
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

internalLinkTypeActiveSessions::internalLinkTypeActiveSessions() {
}

const std::int32_t internalLinkTypeActiveSessions::ID;

void internalLinkTypeActiveSessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeActiveSessions");
    s.store_class_end();
  }
}

internalLinkTypeAttachmentMenuBot::internalLinkTypeAttachmentMenuBot()
  : chat_link_()
  , bot_username_()
  , url_()
{}

internalLinkTypeAttachmentMenuBot::internalLinkTypeAttachmentMenuBot(object_ptr<InternalLinkType> &&chat_link_, string const &bot_username_, string const &url_)
  : chat_link_(std::move(chat_link_))
  , bot_username_(bot_username_)
  , url_(url_)
{}

const std::int32_t internalLinkTypeAttachmentMenuBot::ID;

void internalLinkTypeAttachmentMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeAttachmentMenuBot");
    s.store_object_field("chat_link", static_cast<const BaseObject *>(chat_link_.get()));
    s.store_field("bot_username", bot_username_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

internalLinkTypeAuthenticationCode::internalLinkTypeAuthenticationCode()
  : code_()
{}

internalLinkTypeAuthenticationCode::internalLinkTypeAuthenticationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t internalLinkTypeAuthenticationCode::ID;

void internalLinkTypeAuthenticationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeAuthenticationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

internalLinkTypeBackground::internalLinkTypeBackground()
  : background_name_()
{}

internalLinkTypeBackground::internalLinkTypeBackground(string const &background_name_)
  : background_name_(background_name_)
{}

const std::int32_t internalLinkTypeBackground::ID;

void internalLinkTypeBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBackground");
    s.store_field("background_name", background_name_);
    s.store_class_end();
  }
}

internalLinkTypeBotStart::internalLinkTypeBotStart()
  : bot_username_()
  , start_parameter_()
{}

internalLinkTypeBotStart::internalLinkTypeBotStart(string const &bot_username_, string const &start_parameter_)
  : bot_username_(bot_username_)
  , start_parameter_(start_parameter_)
{}

const std::int32_t internalLinkTypeBotStart::ID;

void internalLinkTypeBotStart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBotStart");
    s.store_field("bot_username", bot_username_);
    s.store_field("start_parameter", start_parameter_);
    s.store_class_end();
  }
}

internalLinkTypeBotStartInGroup::internalLinkTypeBotStartInGroup()
  : bot_username_()
  , start_parameter_()
  , administrator_rights_()
{}

internalLinkTypeBotStartInGroup::internalLinkTypeBotStartInGroup(string const &bot_username_, string const &start_parameter_, object_ptr<chatAdministratorRights> &&administrator_rights_)
  : bot_username_(bot_username_)
  , start_parameter_(start_parameter_)
  , administrator_rights_(std::move(administrator_rights_))
{}

const std::int32_t internalLinkTypeBotStartInGroup::ID;

void internalLinkTypeBotStartInGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBotStartInGroup");
    s.store_field("bot_username", bot_username_);
    s.store_field("start_parameter", start_parameter_);
    s.store_object_field("administrator_rights", static_cast<const BaseObject *>(administrator_rights_.get()));
    s.store_class_end();
  }
}

internalLinkTypeBotAddToChannel::internalLinkTypeBotAddToChannel()
  : bot_username_()
  , administrator_rights_()
{}

internalLinkTypeBotAddToChannel::internalLinkTypeBotAddToChannel(string const &bot_username_, object_ptr<chatAdministratorRights> &&administrator_rights_)
  : bot_username_(bot_username_)
  , administrator_rights_(std::move(administrator_rights_))
{}

const std::int32_t internalLinkTypeBotAddToChannel::ID;

void internalLinkTypeBotAddToChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBotAddToChannel");
    s.store_field("bot_username", bot_username_);
    s.store_object_field("administrator_rights", static_cast<const BaseObject *>(administrator_rights_.get()));
    s.store_class_end();
  }
}

internalLinkTypeChangePhoneNumber::internalLinkTypeChangePhoneNumber() {
}

const std::int32_t internalLinkTypeChangePhoneNumber::ID;

void internalLinkTypeChangePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChangePhoneNumber");
    s.store_class_end();
  }
}

internalLinkTypeChatInvite::internalLinkTypeChatInvite()
  : invite_link_()
{}

internalLinkTypeChatInvite::internalLinkTypeChatInvite(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t internalLinkTypeChatInvite::ID;

void internalLinkTypeChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChatInvite");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

internalLinkTypeFilterSettings::internalLinkTypeFilterSettings() {
}

const std::int32_t internalLinkTypeFilterSettings::ID;

void internalLinkTypeFilterSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeFilterSettings");
    s.store_class_end();
  }
}

internalLinkTypeGame::internalLinkTypeGame()
  : bot_username_()
  , game_short_name_()
{}

internalLinkTypeGame::internalLinkTypeGame(string const &bot_username_, string const &game_short_name_)
  : bot_username_(bot_username_)
  , game_short_name_(game_short_name_)
{}

const std::int32_t internalLinkTypeGame::ID;

void internalLinkTypeGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeGame");
    s.store_field("bot_username", bot_username_);
    s.store_field("game_short_name", game_short_name_);
    s.store_class_end();
  }
}

internalLinkTypeLanguagePack::internalLinkTypeLanguagePack()
  : language_pack_id_()
{}

internalLinkTypeLanguagePack::internalLinkTypeLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t internalLinkTypeLanguagePack::ID;

void internalLinkTypeLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

internalLinkTypeLanguageSettings::internalLinkTypeLanguageSettings() {
}

const std::int32_t internalLinkTypeLanguageSettings::ID;

void internalLinkTypeLanguageSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeLanguageSettings");
    s.store_class_end();
  }
}

internalLinkTypeMessage::internalLinkTypeMessage()
  : url_()
{}

internalLinkTypeMessage::internalLinkTypeMessage(string const &url_)
  : url_(url_)
{}

const std::int32_t internalLinkTypeMessage::ID;

void internalLinkTypeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeMessage");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

internalLinkTypeMessageDraft::internalLinkTypeMessageDraft()
  : text_()
  , contains_link_()
{}

internalLinkTypeMessageDraft::internalLinkTypeMessageDraft(object_ptr<formattedText> &&text_, bool contains_link_)
  : text_(std::move(text_))
  , contains_link_(contains_link_)
{}

const std::int32_t internalLinkTypeMessageDraft::ID;

void internalLinkTypeMessageDraft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeMessageDraft");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("contains_link", contains_link_);
    s.store_class_end();
  }
}

internalLinkTypePassportDataRequest::internalLinkTypePassportDataRequest()
  : bot_user_id_()
  , scope_()
  , public_key_()
  , nonce_()
  , callback_url_()
{}

internalLinkTypePassportDataRequest::internalLinkTypePassportDataRequest(int53 bot_user_id_, string const &scope_, string const &public_key_, string const &nonce_, string const &callback_url_)
  : bot_user_id_(bot_user_id_)
  , scope_(scope_)
  , public_key_(public_key_)
  , nonce_(nonce_)
  , callback_url_(callback_url_)
{}

const std::int32_t internalLinkTypePassportDataRequest::ID;

void internalLinkTypePassportDataRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePassportDataRequest");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("scope", scope_);
    s.store_field("public_key", public_key_);
    s.store_field("nonce", nonce_);
    s.store_field("callback_url", callback_url_);
    s.store_class_end();
  }
}

internalLinkTypePhoneNumberConfirmation::internalLinkTypePhoneNumberConfirmation()
  : hash_()
  , phone_number_()
{}

internalLinkTypePhoneNumberConfirmation::internalLinkTypePhoneNumberConfirmation(string const &hash_, string const &phone_number_)
  : hash_(hash_)
  , phone_number_(phone_number_)
{}

const std::int32_t internalLinkTypePhoneNumberConfirmation::ID;

void internalLinkTypePhoneNumberConfirmation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePhoneNumberConfirmation");
    s.store_field("hash", hash_);
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

internalLinkTypePrivacyAndSecuritySettings::internalLinkTypePrivacyAndSecuritySettings() {
}

const std::int32_t internalLinkTypePrivacyAndSecuritySettings::ID;

void internalLinkTypePrivacyAndSecuritySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePrivacyAndSecuritySettings");
    s.store_class_end();
  }
}

internalLinkTypeProxy::internalLinkTypeProxy()
  : server_()
  , port_()
  , type_()
{}

internalLinkTypeProxy::internalLinkTypeProxy(string const &server_, int32 port_, object_ptr<ProxyType> &&type_)
  : server_(server_)
  , port_(port_)
  , type_(std::move(type_))
{}

const std::int32_t internalLinkTypeProxy::ID;

void internalLinkTypeProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeProxy");
    s.store_field("server", server_);
    s.store_field("port", port_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

internalLinkTypePublicChat::internalLinkTypePublicChat()
  : chat_username_()
{}

internalLinkTypePublicChat::internalLinkTypePublicChat(string const &chat_username_)
  : chat_username_(chat_username_)
{}

const std::int32_t internalLinkTypePublicChat::ID;

void internalLinkTypePublicChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePublicChat");
    s.store_field("chat_username", chat_username_);
    s.store_class_end();
  }
}

internalLinkTypeQrCodeAuthentication::internalLinkTypeQrCodeAuthentication() {
}

const std::int32_t internalLinkTypeQrCodeAuthentication::ID;

void internalLinkTypeQrCodeAuthentication::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeQrCodeAuthentication");
    s.store_class_end();
  }
}

internalLinkTypeSettings::internalLinkTypeSettings() {
}

const std::int32_t internalLinkTypeSettings::ID;

void internalLinkTypeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeSettings");
    s.store_class_end();
  }
}

internalLinkTypeStickerSet::internalLinkTypeStickerSet()
  : sticker_set_name_()
{}

internalLinkTypeStickerSet::internalLinkTypeStickerSet(string const &sticker_set_name_)
  : sticker_set_name_(sticker_set_name_)
{}

const std::int32_t internalLinkTypeStickerSet::ID;

void internalLinkTypeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeStickerSet");
    s.store_field("sticker_set_name", sticker_set_name_);
    s.store_class_end();
  }
}

internalLinkTypeTheme::internalLinkTypeTheme()
  : theme_name_()
{}

internalLinkTypeTheme::internalLinkTypeTheme(string const &theme_name_)
  : theme_name_(theme_name_)
{}

const std::int32_t internalLinkTypeTheme::ID;

void internalLinkTypeTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeTheme");
    s.store_field("theme_name", theme_name_);
    s.store_class_end();
  }
}

internalLinkTypeThemeSettings::internalLinkTypeThemeSettings() {
}

const std::int32_t internalLinkTypeThemeSettings::ID;

void internalLinkTypeThemeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeThemeSettings");
    s.store_class_end();
  }
}

internalLinkTypeUnknownDeepLink::internalLinkTypeUnknownDeepLink()
  : link_()
{}

internalLinkTypeUnknownDeepLink::internalLinkTypeUnknownDeepLink(string const &link_)
  : link_(link_)
{}

const std::int32_t internalLinkTypeUnknownDeepLink::ID;

void internalLinkTypeUnknownDeepLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeUnknownDeepLink");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

internalLinkTypeUnsupportedProxy::internalLinkTypeUnsupportedProxy() {
}

const std::int32_t internalLinkTypeUnsupportedProxy::ID;

void internalLinkTypeUnsupportedProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeUnsupportedProxy");
    s.store_class_end();
  }
}

internalLinkTypeUserPhoneNumber::internalLinkTypeUserPhoneNumber()
  : phone_number_()
{}

internalLinkTypeUserPhoneNumber::internalLinkTypeUserPhoneNumber(string const &phone_number_)
  : phone_number_(phone_number_)
{}

const std::int32_t internalLinkTypeUserPhoneNumber::ID;

void internalLinkTypeUserPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeUserPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

internalLinkTypeVideoChat::internalLinkTypeVideoChat()
  : chat_username_()
  , invite_hash_()
  , is_live_stream_()
{}

internalLinkTypeVideoChat::internalLinkTypeVideoChat(string const &chat_username_, string const &invite_hash_, bool is_live_stream_)
  : chat_username_(chat_username_)
  , invite_hash_(invite_hash_)
  , is_live_stream_(is_live_stream_)
{}

const std::int32_t internalLinkTypeVideoChat::ID;

void internalLinkTypeVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeVideoChat");
    s.store_field("chat_username", chat_username_);
    s.store_field("invite_hash", invite_hash_);
    s.store_field("is_live_stream", is_live_stream_);
    s.store_class_end();
  }
}

invoice::invoice()
  : currency_()
  , price_parts_()
  , max_tip_amount_()
  , suggested_tip_amounts_()
  , is_test_()
  , need_name_()
  , need_phone_number_()
  , need_email_address_()
  , need_shipping_address_()
  , send_phone_number_to_provider_()
  , send_email_address_to_provider_()
  , is_flexible_()
{}

invoice::invoice(string const &currency_, array<object_ptr<labeledPricePart>> &&price_parts_, int53 max_tip_amount_, array<int53> &&suggested_tip_amounts_, bool is_test_, bool need_name_, bool need_phone_number_, bool need_email_address_, bool need_shipping_address_, bool send_phone_number_to_provider_, bool send_email_address_to_provider_, bool is_flexible_)
  : currency_(currency_)
  , price_parts_(std::move(price_parts_))
  , max_tip_amount_(max_tip_amount_)
  , suggested_tip_amounts_(std::move(suggested_tip_amounts_))
  , is_test_(is_test_)
  , need_name_(need_name_)
  , need_phone_number_(need_phone_number_)
  , need_email_address_(need_email_address_)
  , need_shipping_address_(need_shipping_address_)
  , send_phone_number_to_provider_(send_phone_number_to_provider_)
  , send_email_address_to_provider_(send_email_address_to_provider_)
  , is_flexible_(is_flexible_)
{}

const std::int32_t invoice::ID;

void invoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invoice");
    s.store_field("currency", currency_);
    { s.store_vector_begin("price_parts", price_parts_.size()); for (const auto &_value : price_parts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("max_tip_amount", max_tip_amount_);
    { s.store_vector_begin("suggested_tip_amounts", suggested_tip_amounts_.size()); for (const auto &_value : suggested_tip_amounts_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("is_test", is_test_);
    s.store_field("need_name", need_name_);
    s.store_field("need_phone_number", need_phone_number_);
    s.store_field("need_email_address", need_email_address_);
    s.store_field("need_shipping_address", need_shipping_address_);
    s.store_field("send_phone_number_to_provider", send_phone_number_to_provider_);
    s.store_field("send_email_address_to_provider", send_email_address_to_provider_);
    s.store_field("is_flexible", is_flexible_);
    s.store_class_end();
  }
}

jsonObjectMember::jsonObjectMember()
  : key_()
  , value_()
{}

jsonObjectMember::jsonObjectMember(string const &key_, object_ptr<JsonValue> &&value_)
  : key_(key_)
  , value_(std::move(value_))
{}

const std::int32_t jsonObjectMember::ID;

void jsonObjectMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonObjectMember");
    s.store_field("key", key_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

jsonValueNull::jsonValueNull() {
}

const std::int32_t jsonValueNull::ID;

void jsonValueNull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueNull");
    s.store_class_end();
  }
}

jsonValueBoolean::jsonValueBoolean()
  : value_()
{}

jsonValueBoolean::jsonValueBoolean(bool value_)
  : value_(value_)
{}

const std::int32_t jsonValueBoolean::ID;

void jsonValueBoolean::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueBoolean");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonValueNumber::jsonValueNumber()
  : value_()
{}

jsonValueNumber::jsonValueNumber(double value_)
  : value_(value_)
{}

const std::int32_t jsonValueNumber::ID;

void jsonValueNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueNumber");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonValueString::jsonValueString()
  : value_()
{}

jsonValueString::jsonValueString(string const &value_)
  : value_(value_)
{}

const std::int32_t jsonValueString::ID;

void jsonValueString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueString");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonValueArray::jsonValueArray()
  : values_()
{}

jsonValueArray::jsonValueArray(array<object_ptr<JsonValue>> &&values_)
  : values_(std::move(values_))
{}

const std::int32_t jsonValueArray::ID;

void jsonValueArray::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueArray");
    { s.store_vector_begin("values", values_.size()); for (const auto &_value : values_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

jsonValueObject::jsonValueObject()
  : members_()
{}

jsonValueObject::jsonValueObject(array<object_ptr<jsonObjectMember>> &&members_)
  : members_(std::move(members_))
{}

const std::int32_t jsonValueObject::ID;

void jsonValueObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueObject");
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

keyboardButton::keyboardButton()
  : text_()
  , type_()
{}

keyboardButton::keyboardButton(string const &text_, object_ptr<KeyboardButtonType> &&type_)
  : text_(text_)
  , type_(std::move(type_))
{}

const std::int32_t keyboardButton::ID;

void keyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButton");
    s.store_field("text", text_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

keyboardButtonTypeText::keyboardButtonTypeText() {
}

const std::int32_t keyboardButtonTypeText::ID;

void keyboardButtonTypeText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeText");
    s.store_class_end();
  }
}

keyboardButtonTypeRequestPhoneNumber::keyboardButtonTypeRequestPhoneNumber() {
}

const std::int32_t keyboardButtonTypeRequestPhoneNumber::ID;

void keyboardButtonTypeRequestPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestPhoneNumber");
    s.store_class_end();
  }
}

keyboardButtonTypeRequestLocation::keyboardButtonTypeRequestLocation() {
}

const std::int32_t keyboardButtonTypeRequestLocation::ID;

void keyboardButtonTypeRequestLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestLocation");
    s.store_class_end();
  }
}

keyboardButtonTypeRequestPoll::keyboardButtonTypeRequestPoll()
  : force_regular_()
  , force_quiz_()
{}

keyboardButtonTypeRequestPoll::keyboardButtonTypeRequestPoll(bool force_regular_, bool force_quiz_)
  : force_regular_(force_regular_)
  , force_quiz_(force_quiz_)
{}

const std::int32_t keyboardButtonTypeRequestPoll::ID;

void keyboardButtonTypeRequestPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestPoll");
    s.store_field("force_regular", force_regular_);
    s.store_field("force_quiz", force_quiz_);
    s.store_class_end();
  }
}

keyboardButtonTypeWebApp::keyboardButtonTypeWebApp()
  : url_()
{}

keyboardButtonTypeWebApp::keyboardButtonTypeWebApp(string const &url_)
  : url_(url_)
{}

const std::int32_t keyboardButtonTypeWebApp::ID;

void keyboardButtonTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeWebApp");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

labeledPricePart::labeledPricePart()
  : label_()
  , amount_()
{}

labeledPricePart::labeledPricePart(string const &label_, int53 amount_)
  : label_(label_)
  , amount_(amount_)
{}

const std::int32_t labeledPricePart::ID;

void labeledPricePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "labeledPricePart");
    s.store_field("label", label_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

languagePackInfo::languagePackInfo()
  : id_()
  , base_language_pack_id_()
  , name_()
  , native_name_()
  , plural_code_()
  , is_official_()
  , is_rtl_()
  , is_beta_()
  , is_installed_()
  , total_string_count_()
  , translated_string_count_()
  , local_string_count_()
  , translation_url_()
{}

languagePackInfo::languagePackInfo(string const &id_, string const &base_language_pack_id_, string const &name_, string const &native_name_, string const &plural_code_, bool is_official_, bool is_rtl_, bool is_beta_, bool is_installed_, int32 total_string_count_, int32 translated_string_count_, int32 local_string_count_, string const &translation_url_)
  : id_(id_)
  , base_language_pack_id_(base_language_pack_id_)
  , name_(name_)
  , native_name_(native_name_)
  , plural_code_(plural_code_)
  , is_official_(is_official_)
  , is_rtl_(is_rtl_)
  , is_beta_(is_beta_)
  , is_installed_(is_installed_)
  , total_string_count_(total_string_count_)
  , translated_string_count_(translated_string_count_)
  , local_string_count_(local_string_count_)
  , translation_url_(translation_url_)
{}

const std::int32_t languagePackInfo::ID;

void languagePackInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackInfo");
    s.store_field("id", id_);
    s.store_field("base_language_pack_id", base_language_pack_id_);
    s.store_field("name", name_);
    s.store_field("native_name", native_name_);
    s.store_field("plural_code", plural_code_);
    s.store_field("is_official", is_official_);
    s.store_field("is_rtl", is_rtl_);
    s.store_field("is_beta", is_beta_);
    s.store_field("is_installed", is_installed_);
    s.store_field("total_string_count", total_string_count_);
    s.store_field("translated_string_count", translated_string_count_);
    s.store_field("local_string_count", local_string_count_);
    s.store_field("translation_url", translation_url_);
    s.store_class_end();
  }
}

languagePackString::languagePackString()
  : key_()
  , value_()
{}

languagePackString::languagePackString(string const &key_, object_ptr<LanguagePackStringValue> &&value_)
  : key_(key_)
  , value_(std::move(value_))
{}

const std::int32_t languagePackString::ID;

void languagePackString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackString");
    s.store_field("key", key_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

languagePackStringValueOrdinary::languagePackStringValueOrdinary()
  : value_()
{}

languagePackStringValueOrdinary::languagePackStringValueOrdinary(string const &value_)
  : value_(value_)
{}

const std::int32_t languagePackStringValueOrdinary::ID;

void languagePackStringValueOrdinary::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStringValueOrdinary");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

languagePackStringValuePluralized::languagePackStringValuePluralized()
  : zero_value_()
  , one_value_()
  , two_value_()
  , few_value_()
  , many_value_()
  , other_value_()
{}

languagePackStringValuePluralized::languagePackStringValuePluralized(string const &zero_value_, string const &one_value_, string const &two_value_, string const &few_value_, string const &many_value_, string const &other_value_)
  : zero_value_(zero_value_)
  , one_value_(one_value_)
  , two_value_(two_value_)
  , few_value_(few_value_)
  , many_value_(many_value_)
  , other_value_(other_value_)
{}

const std::int32_t languagePackStringValuePluralized::ID;

void languagePackStringValuePluralized::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStringValuePluralized");
    s.store_field("zero_value", zero_value_);
    s.store_field("one_value", one_value_);
    s.store_field("two_value", two_value_);
    s.store_field("few_value", few_value_);
    s.store_field("many_value", many_value_);
    s.store_field("other_value", other_value_);
    s.store_class_end();
  }
}

languagePackStringValueDeleted::languagePackStringValueDeleted() {
}

const std::int32_t languagePackStringValueDeleted::ID;

void languagePackStringValueDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStringValueDeleted");
    s.store_class_end();
  }
}

languagePackStrings::languagePackStrings()
  : strings_()
{}

languagePackStrings::languagePackStrings(array<object_ptr<languagePackString>> &&strings_)
  : strings_(std::move(strings_))
{}

const std::int32_t languagePackStrings::ID;

void languagePackStrings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStrings");
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

localFile::localFile()
  : path_()
  , can_be_downloaded_()
  , can_be_deleted_()
  , is_downloading_active_()
  , is_downloading_completed_()
  , download_offset_()
  , downloaded_prefix_size_()
  , downloaded_size_()
{}

localFile::localFile(string const &path_, bool can_be_downloaded_, bool can_be_deleted_, bool is_downloading_active_, bool is_downloading_completed_, int32 download_offset_, int32 downloaded_prefix_size_, int32 downloaded_size_)
  : path_(path_)
  , can_be_downloaded_(can_be_downloaded_)
  , can_be_deleted_(can_be_deleted_)
  , is_downloading_active_(is_downloading_active_)
  , is_downloading_completed_(is_downloading_completed_)
  , download_offset_(download_offset_)
  , downloaded_prefix_size_(downloaded_prefix_size_)
  , downloaded_size_(downloaded_size_)
{}

const std::int32_t localFile::ID;

void localFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "localFile");
    s.store_field("path", path_);
    s.store_field("can_be_downloaded", can_be_downloaded_);
    s.store_field("can_be_deleted", can_be_deleted_);
    s.store_field("is_downloading_active", is_downloading_active_);
    s.store_field("is_downloading_completed", is_downloading_completed_);
    s.store_field("download_offset", download_offset_);
    s.store_field("downloaded_prefix_size", downloaded_prefix_size_);
    s.store_field("downloaded_size", downloaded_size_);
    s.store_class_end();
  }
}

localizationTargetInfo::localizationTargetInfo()
  : language_packs_()
{}

localizationTargetInfo::localizationTargetInfo(array<object_ptr<languagePackInfo>> &&language_packs_)
  : language_packs_(std::move(language_packs_))
{}

const std::int32_t localizationTargetInfo::ID;

void localizationTargetInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "localizationTargetInfo");
    { s.store_vector_begin("language_packs", language_packs_.size()); for (const auto &_value : language_packs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

location::location()
  : latitude_()
  , longitude_()
  , horizontal_accuracy_()
{}

location::location(double latitude_, double longitude_, double horizontal_accuracy_)
  : latitude_(latitude_)
  , longitude_(longitude_)
  , horizontal_accuracy_(horizontal_accuracy_)
{}

const std::int32_t location::ID;

void location::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "location");
    s.store_field("latitude", latitude_);
    s.store_field("longitude", longitude_);
    s.store_field("horizontal_accuracy", horizontal_accuracy_);
    s.store_class_end();
  }
}

logStreamDefault::logStreamDefault() {
}

const std::int32_t logStreamDefault::ID;

void logStreamDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logStreamDefault");
    s.store_class_end();
  }
}

logStreamFile::logStreamFile()
  : path_()
  , max_file_size_()
  , redirect_stderr_()
{}

logStreamFile::logStreamFile(string const &path_, int53 max_file_size_, bool redirect_stderr_)
  : path_(path_)
  , max_file_size_(max_file_size_)
  , redirect_stderr_(redirect_stderr_)
{}

const std::int32_t logStreamFile::ID;

void logStreamFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logStreamFile");
    s.store_field("path", path_);
    s.store_field("max_file_size", max_file_size_);
    s.store_field("redirect_stderr", redirect_stderr_);
    s.store_class_end();
  }
}

logStreamEmpty::logStreamEmpty() {
}

const std::int32_t logStreamEmpty::ID;

void logStreamEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logStreamEmpty");
    s.store_class_end();
  }
}

logTags::logTags()
  : tags_()
{}

logTags::logTags(array<string> &&tags_)
  : tags_(std::move(tags_))
{}

const std::int32_t logTags::ID;

void logTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logTags");
    { s.store_vector_begin("tags", tags_.size()); for (const auto &_value : tags_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

logVerbosityLevel::logVerbosityLevel()
  : verbosity_level_()
{}

logVerbosityLevel::logVerbosityLevel(int32 verbosity_level_)
  : verbosity_level_(verbosity_level_)
{}

const std::int32_t logVerbosityLevel::ID;

void logVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logVerbosityLevel");
    s.store_field("verbosity_level", verbosity_level_);
    s.store_class_end();
  }
}

loginUrlInfoOpen::loginUrlInfoOpen()
  : url_()
  , skip_confirm_()
{}

loginUrlInfoOpen::loginUrlInfoOpen(string const &url_, bool skip_confirm_)
  : url_(url_)
  , skip_confirm_(skip_confirm_)
{}

const std::int32_t loginUrlInfoOpen::ID;

void loginUrlInfoOpen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loginUrlInfoOpen");
    s.store_field("url", url_);
    s.store_field("skip_confirm", skip_confirm_);
    s.store_class_end();
  }
}

loginUrlInfoRequestConfirmation::loginUrlInfoRequestConfirmation()
  : url_()
  , domain_()
  , bot_user_id_()
  , request_write_access_()
{}

loginUrlInfoRequestConfirmation::loginUrlInfoRequestConfirmation(string const &url_, string const &domain_, int53 bot_user_id_, bool request_write_access_)
  : url_(url_)
  , domain_(domain_)
  , bot_user_id_(bot_user_id_)
  , request_write_access_(request_write_access_)
{}

const std::int32_t loginUrlInfoRequestConfirmation::ID;

void loginUrlInfoRequestConfirmation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loginUrlInfoRequestConfirmation");
    s.store_field("url", url_);
    s.store_field("domain", domain_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("request_write_access", request_write_access_);
    s.store_class_end();
  }
}

maskPointForehead::maskPointForehead() {
}

const std::int32_t maskPointForehead::ID;

void maskPointForehead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointForehead");
    s.store_class_end();
  }
}

maskPointEyes::maskPointEyes() {
}

const std::int32_t maskPointEyes::ID;

void maskPointEyes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointEyes");
    s.store_class_end();
  }
}

maskPointMouth::maskPointMouth() {
}

const std::int32_t maskPointMouth::ID;

void maskPointMouth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointMouth");
    s.store_class_end();
  }
}

maskPointChin::maskPointChin() {
}

const std::int32_t maskPointChin::ID;

void maskPointChin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPointChin");
    s.store_class_end();
  }
}

maskPosition::maskPosition()
  : point_()
  , x_shift_()
  , y_shift_()
  , scale_()
{}

maskPosition::maskPosition(object_ptr<MaskPoint> &&point_, double x_shift_, double y_shift_, double scale_)
  : point_(std::move(point_))
  , x_shift_(x_shift_)
  , y_shift_(y_shift_)
  , scale_(scale_)
{}

const std::int32_t maskPosition::ID;

void maskPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPosition");
    s.store_object_field("point", static_cast<const BaseObject *>(point_.get()));
    s.store_field("x_shift", x_shift_);
    s.store_field("y_shift", y_shift_);
    s.store_field("scale", scale_);
    s.store_class_end();
  }
}

message::message()
  : id_()
  , sender_id_()
  , chat_id_()
  , sending_state_()
  , scheduling_state_()
  , is_outgoing_()
  , is_pinned_()
  , can_be_edited_()
  , can_be_forwarded_()
  , can_be_saved_()
  , can_be_deleted_only_for_self_()
  , can_be_deleted_for_all_users_()
  , can_get_added_reactions_()
  , can_get_statistics_()
  , can_get_message_thread_()
  , can_get_viewers_()
  , can_get_media_timestamp_links_()
  , has_timestamped_media_()
  , is_channel_post_()
  , contains_unread_mention_()
  , date_()
  , edit_date_()
  , forward_info_()
  , interaction_info_()
  , unread_reactions_()
  , reply_in_chat_id_()
  , reply_to_message_id_()
  , message_thread_id_()
  , ttl_()
  , ttl_expires_in_()
  , via_bot_user_id_()
  , author_signature_()
  , media_album_id_()
  , restriction_reason_()
  , content_()
  , reply_markup_()
{}

message::message(int53 id_, object_ptr<MessageSender> &&sender_id_, int53 chat_id_, object_ptr<MessageSendingState> &&sending_state_, object_ptr<MessageSchedulingState> &&scheduling_state_, bool is_outgoing_, bool is_pinned_, bool can_be_edited_, bool can_be_forwarded_, bool can_be_saved_, bool can_be_deleted_only_for_self_, bool can_be_deleted_for_all_users_, bool can_get_added_reactions_, bool can_get_statistics_, bool can_get_message_thread_, bool can_get_viewers_, bool can_get_media_timestamp_links_, bool has_timestamped_media_, bool is_channel_post_, bool contains_unread_mention_, int32 date_, int32 edit_date_, object_ptr<messageForwardInfo> &&forward_info_, object_ptr<messageInteractionInfo> &&interaction_info_, array<object_ptr<unreadReaction>> &&unread_reactions_, int53 reply_in_chat_id_, int53 reply_to_message_id_, int53 message_thread_id_, int32 ttl_, double ttl_expires_in_, int53 via_bot_user_id_, string const &author_signature_, int64 media_album_id_, string const &restriction_reason_, object_ptr<MessageContent> &&content_, object_ptr<ReplyMarkup> &&reply_markup_)
  : id_(id_)
  , sender_id_(std::move(sender_id_))
  , chat_id_(chat_id_)
  , sending_state_(std::move(sending_state_))
  , scheduling_state_(std::move(scheduling_state_))
  , is_outgoing_(is_outgoing_)
  , is_pinned_(is_pinned_)
  , can_be_edited_(can_be_edited_)
  , can_be_forwarded_(can_be_forwarded_)
  , can_be_saved_(can_be_saved_)
  , can_be_deleted_only_for_self_(can_be_deleted_only_for_self_)
  , can_be_deleted_for_all_users_(can_be_deleted_for_all_users_)
  , can_get_added_reactions_(can_get_added_reactions_)
  , can_get_statistics_(can_get_statistics_)
  , can_get_message_thread_(can_get_message_thread_)
  , can_get_viewers_(can_get_viewers_)
  , can_get_media_timestamp_links_(can_get_media_timestamp_links_)
  , has_timestamped_media_(has_timestamped_media_)
  , is_channel_post_(is_channel_post_)
  , contains_unread_mention_(contains_unread_mention_)
  , date_(date_)
  , edit_date_(edit_date_)
  , forward_info_(std::move(forward_info_))
  , interaction_info_(std::move(interaction_info_))
  , unread_reactions_(std::move(unread_reactions_))
  , reply_in_chat_id_(reply_in_chat_id_)
  , reply_to_message_id_(reply_to_message_id_)
  , message_thread_id_(message_thread_id_)
  , ttl_(ttl_)
  , ttl_expires_in_(ttl_expires_in_)
  , via_bot_user_id_(via_bot_user_id_)
  , author_signature_(author_signature_)
  , media_album_id_(media_album_id_)
  , restriction_reason_(restriction_reason_)
  , content_(std::move(content_))
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t message::ID;

void message::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "message");
    s.store_field("id", id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_object_field("sending_state", static_cast<const BaseObject *>(sending_state_.get()));
    s.store_object_field("scheduling_state", static_cast<const BaseObject *>(scheduling_state_.get()));
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("is_pinned", is_pinned_);
    s.store_field("can_be_edited", can_be_edited_);
    s.store_field("can_be_forwarded", can_be_forwarded_);
    s.store_field("can_be_saved", can_be_saved_);
    s.store_field("can_be_deleted_only_for_self", can_be_deleted_only_for_self_);
    s.store_field("can_be_deleted_for_all_users", can_be_deleted_for_all_users_);
    s.store_field("can_get_added_reactions", can_get_added_reactions_);
    s.store_field("can_get_statistics", can_get_statistics_);
    s.store_field("can_get_message_thread", can_get_message_thread_);
    s.store_field("can_get_viewers", can_get_viewers_);
    s.store_field("can_get_media_timestamp_links", can_get_media_timestamp_links_);
    s.store_field("has_timestamped_media", has_timestamped_media_);
    s.store_field("is_channel_post", is_channel_post_);
    s.store_field("contains_unread_mention", contains_unread_mention_);
    s.store_field("date", date_);
    s.store_field("edit_date", edit_date_);
    s.store_object_field("forward_info", static_cast<const BaseObject *>(forward_info_.get()));
    s.store_object_field("interaction_info", static_cast<const BaseObject *>(interaction_info_.get()));
    { s.store_vector_begin("unread_reactions", unread_reactions_.size()); for (const auto &_value : unread_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("reply_in_chat_id", reply_in_chat_id_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_field("message_thread_id", message_thread_id_);
    s.store_field("ttl", ttl_);
    s.store_field("ttl_expires_in", ttl_expires_in_);
    s.store_field("via_bot_user_id", via_bot_user_id_);
    s.store_field("author_signature", author_signature_);
    s.store_field("media_album_id", media_album_id_);
    s.store_field("restriction_reason", restriction_reason_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

messageCalendar::messageCalendar()
  : total_count_()
  , days_()
{}

messageCalendar::messageCalendar(int32 total_count_, array<object_ptr<messageCalendarDay>> &&days_)
  : total_count_(total_count_)
  , days_(std::move(days_))
{}

const std::int32_t messageCalendar::ID;

void messageCalendar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCalendar");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("days", days_.size()); for (const auto &_value : days_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageCalendarDay::messageCalendarDay()
  : total_count_()
  , message_()
{}

messageCalendarDay::messageCalendarDay(int32 total_count_, object_ptr<message> &&message_)
  : total_count_(total_count_)
  , message_(std::move(message_))
{}

const std::int32_t messageCalendarDay::ID;

void messageCalendarDay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCalendarDay");
    s.store_field("total_count", total_count_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

messageText::messageText()
  : text_()
  , web_page_()
{}

messageText::messageText(object_ptr<formattedText> &&text_, object_ptr<webPage> &&web_page_)
  : text_(std::move(text_))
  , web_page_(std::move(web_page_))
{}

const std::int32_t messageText::ID;

void messageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("web_page", static_cast<const BaseObject *>(web_page_.get()));
    s.store_class_end();
  }
}

messageAnimation::messageAnimation()
  : animation_()
  , caption_()
  , is_secret_()
{}

messageAnimation::messageAnimation(object_ptr<animation> &&animation_, object_ptr<formattedText> &&caption_, bool is_secret_)
  : animation_(std::move(animation_))
  , caption_(std::move(caption_))
  , is_secret_(is_secret_)
{}

const std::int32_t messageAnimation::ID;

void messageAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageAudio::messageAudio()
  : audio_()
  , caption_()
{}

messageAudio::messageAudio(object_ptr<audio> &&audio_, object_ptr<formattedText> &&caption_)
  : audio_(std::move(audio_))
  , caption_(std::move(caption_))
{}

const std::int32_t messageAudio::ID;

void messageAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

messageDocument::messageDocument()
  : document_()
  , caption_()
{}

messageDocument::messageDocument(object_ptr<document> &&document_, object_ptr<formattedText> &&caption_)
  : document_(std::move(document_))
  , caption_(std::move(caption_))
{}

const std::int32_t messageDocument::ID;

void messageDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

messagePhoto::messagePhoto()
  : photo_()
  , caption_()
  , is_secret_()
{}

messagePhoto::messagePhoto(object_ptr<photo> &&photo_, object_ptr<formattedText> &&caption_, bool is_secret_)
  : photo_(std::move(photo_))
  , caption_(std::move(caption_))
  , is_secret_(is_secret_)
{}

const std::int32_t messagePhoto::ID;

void messagePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageExpiredPhoto::messageExpiredPhoto() {
}

const std::int32_t messageExpiredPhoto::ID;

void messageExpiredPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExpiredPhoto");
    s.store_class_end();
  }
}

messageSticker::messageSticker()
  : sticker_()
{}

messageSticker::messageSticker(object_ptr<sticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t messageSticker::ID;

void messageSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messageVideo::messageVideo()
  : video_()
  , caption_()
  , is_secret_()
{}

messageVideo::messageVideo(object_ptr<video> &&video_, object_ptr<formattedText> &&caption_, bool is_secret_)
  : video_(std::move(video_))
  , caption_(std::move(caption_))
  , is_secret_(is_secret_)
{}

const std::int32_t messageVideo::ID;

void messageVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageExpiredVideo::messageExpiredVideo() {
}

const std::int32_t messageExpiredVideo::ID;

void messageExpiredVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExpiredVideo");
    s.store_class_end();
  }
}

messageVideoNote::messageVideoNote()
  : video_note_()
  , is_viewed_()
  , is_secret_()
{}

messageVideoNote::messageVideoNote(object_ptr<videoNote> &&video_note_, bool is_viewed_, bool is_secret_)
  : video_note_(std::move(video_note_))
  , is_viewed_(is_viewed_)
  , is_secret_(is_secret_)
{}

const std::int32_t messageVideoNote::ID;

void messageVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_field("is_viewed", is_viewed_);
    s.store_field("is_secret", is_secret_);
    s.store_class_end();
  }
}

messageVoiceNote::messageVoiceNote()
  : voice_note_()
  , caption_()
  , is_listened_()
{}

messageVoiceNote::messageVoiceNote(object_ptr<voiceNote> &&voice_note_, object_ptr<formattedText> &&caption_, bool is_listened_)
  : voice_note_(std::move(voice_note_))
  , caption_(std::move(caption_))
  , is_listened_(is_listened_)
{}

const std::int32_t messageVoiceNote::ID;

void messageVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("is_listened", is_listened_);
    s.store_class_end();
  }
}

messageLocation::messageLocation()
  : location_()
  , live_period_()
  , expires_in_()
  , heading_()
  , proximity_alert_radius_()
{}

messageLocation::messageLocation(object_ptr<location> &&location_, int32 live_period_, int32 expires_in_, int32 heading_, int32 proximity_alert_radius_)
  : location_(std::move(location_))
  , live_period_(live_period_)
  , expires_in_(expires_in_)
  , heading_(heading_)
  , proximity_alert_radius_(proximity_alert_radius_)
{}

const std::int32_t messageLocation::ID;

void messageLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("live_period", live_period_);
    s.store_field("expires_in", expires_in_);
    s.store_field("heading", heading_);
    s.store_field("proximity_alert_radius", proximity_alert_radius_);
    s.store_class_end();
  }
}

messageVenue::messageVenue()
  : venue_()
{}

messageVenue::messageVenue(object_ptr<venue> &&venue_)
  : venue_(std::move(venue_))
{}

const std::int32_t messageVenue::ID;

void messageVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVenue");
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_class_end();
  }
}

messageContact::messageContact()
  : contact_()
{}

messageContact::messageContact(object_ptr<contact> &&contact_)
  : contact_(std::move(contact_))
{}

const std::int32_t messageContact::ID;

void messageContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageContact");
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_class_end();
  }
}

messageAnimatedEmoji::messageAnimatedEmoji()
  : animated_emoji_()
  , emoji_()
{}

messageAnimatedEmoji::messageAnimatedEmoji(object_ptr<animatedEmoji> &&animated_emoji_, string const &emoji_)
  : animated_emoji_(std::move(animated_emoji_))
  , emoji_(emoji_)
{}

const std::int32_t messageAnimatedEmoji::ID;

void messageAnimatedEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageAnimatedEmoji");
    s.store_object_field("animated_emoji", static_cast<const BaseObject *>(animated_emoji_.get()));
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

messageDice::messageDice()
  : initial_state_()
  , final_state_()
  , emoji_()
  , value_()
  , success_animation_frame_number_()
{}

messageDice::messageDice(object_ptr<DiceStickers> &&initial_state_, object_ptr<DiceStickers> &&final_state_, string const &emoji_, int32 value_, int32 success_animation_frame_number_)
  : initial_state_(std::move(initial_state_))
  , final_state_(std::move(final_state_))
  , emoji_(emoji_)
  , value_(value_)
  , success_animation_frame_number_(success_animation_frame_number_)
{}

const std::int32_t messageDice::ID;

void messageDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageDice");
    s.store_object_field("initial_state", static_cast<const BaseObject *>(initial_state_.get()));
    s.store_object_field("final_state", static_cast<const BaseObject *>(final_state_.get()));
    s.store_field("emoji", emoji_);
    s.store_field("value", value_);
    s.store_field("success_animation_frame_number", success_animation_frame_number_);
    s.store_class_end();
  }
}

messageGame::messageGame()
  : game_()
{}

messageGame::messageGame(object_ptr<game> &&game_)
  : game_(std::move(game_))
{}

const std::int32_t messageGame::ID;

void messageGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGame");
    s.store_object_field("game", static_cast<const BaseObject *>(game_.get()));
    s.store_class_end();
  }
}

messagePoll::messagePoll()
  : poll_()
{}

messagePoll::messagePoll(object_ptr<poll> &&poll_)
  : poll_(std::move(poll_))
{}

const std::int32_t messagePoll::ID;

void messagePoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePoll");
    s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get()));
    s.store_class_end();
  }
}

messageInvoice::messageInvoice()
  : title_()
  , description_()
  , photo_()
  , currency_()
  , total_amount_()
  , start_parameter_()
  , is_test_()
  , need_shipping_address_()
  , receipt_message_id_()
{}

messageInvoice::messageInvoice(string const &title_, string const &description_, object_ptr<photo> &&photo_, string const &currency_, int53 total_amount_, string const &start_parameter_, bool is_test_, bool need_shipping_address_, int53 receipt_message_id_)
  : title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , currency_(currency_)
  , total_amount_(total_amount_)
  , start_parameter_(start_parameter_)
  , is_test_(is_test_)
  , need_shipping_address_(need_shipping_address_)
  , receipt_message_id_(receipt_message_id_)
{}

const std::int32_t messageInvoice::ID;

void messageInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageInvoice");
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("start_parameter", start_parameter_);
    s.store_field("is_test", is_test_);
    s.store_field("need_shipping_address", need_shipping_address_);
    s.store_field("receipt_message_id", receipt_message_id_);
    s.store_class_end();
  }
}

messageCall::messageCall()
  : is_video_()
  , discard_reason_()
  , duration_()
{}

messageCall::messageCall(bool is_video_, object_ptr<CallDiscardReason> &&discard_reason_, int32 duration_)
  : is_video_(is_video_)
  , discard_reason_(std::move(discard_reason_))
  , duration_(duration_)
{}

const std::int32_t messageCall::ID;

void messageCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCall");
    s.store_field("is_video", is_video_);
    s.store_object_field("discard_reason", static_cast<const BaseObject *>(discard_reason_.get()));
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

messageVideoChatScheduled::messageVideoChatScheduled()
  : group_call_id_()
  , start_date_()
{}

messageVideoChatScheduled::messageVideoChatScheduled(int32 group_call_id_, int32 start_date_)
  : group_call_id_(group_call_id_)
  , start_date_(start_date_)
{}

const std::int32_t messageVideoChatScheduled::ID;

void messageVideoChatScheduled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoChatScheduled");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("start_date", start_date_);
    s.store_class_end();
  }
}

messageVideoChatStarted::messageVideoChatStarted()
  : group_call_id_()
{}

messageVideoChatStarted::messageVideoChatStarted(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t messageVideoChatStarted::ID;

void messageVideoChatStarted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoChatStarted");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

messageVideoChatEnded::messageVideoChatEnded()
  : duration_()
{}

messageVideoChatEnded::messageVideoChatEnded(int32 duration_)
  : duration_(duration_)
{}

const std::int32_t messageVideoChatEnded::ID;

void messageVideoChatEnded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageVideoChatEnded");
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

messageInviteVideoChatParticipants::messageInviteVideoChatParticipants()
  : group_call_id_()
  , user_ids_()
{}

messageInviteVideoChatParticipants::messageInviteVideoChatParticipants(int32 group_call_id_, array<int53> &&user_ids_)
  : group_call_id_(group_call_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t messageInviteVideoChatParticipants::ID;

void messageInviteVideoChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageInviteVideoChatParticipants");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageBasicGroupChatCreate::messageBasicGroupChatCreate()
  : title_()
  , member_user_ids_()
{}

messageBasicGroupChatCreate::messageBasicGroupChatCreate(string const &title_, array<int53> &&member_user_ids_)
  : title_(title_)
  , member_user_ids_(std::move(member_user_ids_))
{}

const std::int32_t messageBasicGroupChatCreate::ID;

void messageBasicGroupChatCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageBasicGroupChatCreate");
    s.store_field("title", title_);
    { s.store_vector_begin("member_user_ids", member_user_ids_.size()); for (const auto &_value : member_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageSupergroupChatCreate::messageSupergroupChatCreate()
  : title_()
{}

messageSupergroupChatCreate::messageSupergroupChatCreate(string const &title_)
  : title_(title_)
{}

const std::int32_t messageSupergroupChatCreate::ID;

void messageSupergroupChatCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSupergroupChatCreate");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

messageChatChangeTitle::messageChatChangeTitle()
  : title_()
{}

messageChatChangeTitle::messageChatChangeTitle(string const &title_)
  : title_(title_)
{}

const std::int32_t messageChatChangeTitle::ID;

void messageChatChangeTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatChangeTitle");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

messageChatChangePhoto::messageChatChangePhoto()
  : photo_()
{}

messageChatChangePhoto::messageChatChangePhoto(object_ptr<chatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t messageChatChangePhoto::ID;

void messageChatChangePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatChangePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

messageChatDeletePhoto::messageChatDeletePhoto() {
}

const std::int32_t messageChatDeletePhoto::ID;

void messageChatDeletePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatDeletePhoto");
    s.store_class_end();
  }
}

messageChatAddMembers::messageChatAddMembers()
  : member_user_ids_()
{}

messageChatAddMembers::messageChatAddMembers(array<int53> &&member_user_ids_)
  : member_user_ids_(std::move(member_user_ids_))
{}

const std::int32_t messageChatAddMembers::ID;

void messageChatAddMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatAddMembers");
    { s.store_vector_begin("member_user_ids", member_user_ids_.size()); for (const auto &_value : member_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageChatJoinByLink::messageChatJoinByLink() {
}

const std::int32_t messageChatJoinByLink::ID;

void messageChatJoinByLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatJoinByLink");
    s.store_class_end();
  }
}

messageChatJoinByRequest::messageChatJoinByRequest() {
}

const std::int32_t messageChatJoinByRequest::ID;

void messageChatJoinByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatJoinByRequest");
    s.store_class_end();
  }
}

messageChatDeleteMember::messageChatDeleteMember()
  : user_id_()
{}

messageChatDeleteMember::messageChatDeleteMember(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t messageChatDeleteMember::ID;

void messageChatDeleteMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatDeleteMember");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

messageChatUpgradeTo::messageChatUpgradeTo()
  : supergroup_id_()
{}

messageChatUpgradeTo::messageChatUpgradeTo(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t messageChatUpgradeTo::ID;

void messageChatUpgradeTo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatUpgradeTo");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

messageChatUpgradeFrom::messageChatUpgradeFrom()
  : title_()
  , basic_group_id_()
{}

messageChatUpgradeFrom::messageChatUpgradeFrom(string const &title_, int53 basic_group_id_)
  : title_(title_)
  , basic_group_id_(basic_group_id_)
{}

const std::int32_t messageChatUpgradeFrom::ID;

void messageChatUpgradeFrom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatUpgradeFrom");
    s.store_field("title", title_);
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

messagePinMessage::messagePinMessage()
  : message_id_()
{}

messagePinMessage::messagePinMessage(int53 message_id_)
  : message_id_(message_id_)
{}

const std::int32_t messagePinMessage::ID;

void messagePinMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePinMessage");
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

messageScreenshotTaken::messageScreenshotTaken() {
}

const std::int32_t messageScreenshotTaken::ID;

void messageScreenshotTaken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageScreenshotTaken");
    s.store_class_end();
  }
}

messageChatSetTheme::messageChatSetTheme()
  : theme_name_()
{}

messageChatSetTheme::messageChatSetTheme(string const &theme_name_)
  : theme_name_(theme_name_)
{}

const std::int32_t messageChatSetTheme::ID;

void messageChatSetTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatSetTheme");
    s.store_field("theme_name", theme_name_);
    s.store_class_end();
  }
}

messageChatSetTtl::messageChatSetTtl()
  : ttl_()
{}

messageChatSetTtl::messageChatSetTtl(int32 ttl_)
  : ttl_(ttl_)
{}

const std::int32_t messageChatSetTtl::ID;

void messageChatSetTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageChatSetTtl");
    s.store_field("ttl", ttl_);
    s.store_class_end();
  }
}

messageCustomServiceAction::messageCustomServiceAction()
  : text_()
{}

messageCustomServiceAction::messageCustomServiceAction(string const &text_)
  : text_(text_)
{}

const std::int32_t messageCustomServiceAction::ID;

void messageCustomServiceAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCustomServiceAction");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

messageGameScore::messageGameScore()
  : game_message_id_()
  , game_id_()
  , score_()
{}

messageGameScore::messageGameScore(int53 game_message_id_, int64 game_id_, int32 score_)
  : game_message_id_(game_message_id_)
  , game_id_(game_id_)
  , score_(score_)
{}

const std::int32_t messageGameScore::ID;

void messageGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageGameScore");
    s.store_field("game_message_id", game_message_id_);
    s.store_field("game_id", game_id_);
    s.store_field("score", score_);
    s.store_class_end();
  }
}

messagePaymentSuccessful::messagePaymentSuccessful()
  : invoice_chat_id_()
  , invoice_message_id_()
  , currency_()
  , total_amount_()
{}

messagePaymentSuccessful::messagePaymentSuccessful(int53 invoice_chat_id_, int53 invoice_message_id_, string const &currency_, int53 total_amount_)
  : invoice_chat_id_(invoice_chat_id_)
  , invoice_message_id_(invoice_message_id_)
  , currency_(currency_)
  , total_amount_(total_amount_)
{}

const std::int32_t messagePaymentSuccessful::ID;

void messagePaymentSuccessful::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaymentSuccessful");
    s.store_field("invoice_chat_id", invoice_chat_id_);
    s.store_field("invoice_message_id", invoice_message_id_);
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_class_end();
  }
}

messagePaymentSuccessfulBot::messagePaymentSuccessfulBot()
  : currency_()
  , total_amount_()
  , invoice_payload_()
  , shipping_option_id_()
  , order_info_()
  , telegram_payment_charge_id_()
  , provider_payment_charge_id_()
{}

messagePaymentSuccessfulBot::messagePaymentSuccessfulBot(string const &currency_, int53 total_amount_, bytes const &invoice_payload_, string const &shipping_option_id_, object_ptr<orderInfo> &&order_info_, string const &telegram_payment_charge_id_, string const &provider_payment_charge_id_)
  : currency_(currency_)
  , total_amount_(total_amount_)
  , invoice_payload_(std::move(invoice_payload_))
  , shipping_option_id_(shipping_option_id_)
  , order_info_(std::move(order_info_))
  , telegram_payment_charge_id_(telegram_payment_charge_id_)
  , provider_payment_charge_id_(provider_payment_charge_id_)
{}

const std::int32_t messagePaymentSuccessfulBot::ID;

void messagePaymentSuccessfulBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePaymentSuccessfulBot");
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_field("shipping_option_id", shipping_option_id_);
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_field("telegram_payment_charge_id", telegram_payment_charge_id_);
    s.store_field("provider_payment_charge_id", provider_payment_charge_id_);
    s.store_class_end();
  }
}

messageContactRegistered::messageContactRegistered() {
}

const std::int32_t messageContactRegistered::ID;

void messageContactRegistered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageContactRegistered");
    s.store_class_end();
  }
}

messageWebsiteConnected::messageWebsiteConnected()
  : domain_name_()
{}

messageWebsiteConnected::messageWebsiteConnected(string const &domain_name_)
  : domain_name_(domain_name_)
{}

const std::int32_t messageWebsiteConnected::ID;

void messageWebsiteConnected::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageWebsiteConnected");
    s.store_field("domain_name", domain_name_);
    s.store_class_end();
  }
}

messageWebAppDataSent::messageWebAppDataSent()
  : button_text_()
{}

messageWebAppDataSent::messageWebAppDataSent(string const &button_text_)
  : button_text_(button_text_)
{}

const std::int32_t messageWebAppDataSent::ID;

void messageWebAppDataSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageWebAppDataSent");
    s.store_field("button_text", button_text_);
    s.store_class_end();
  }
}

messageWebAppDataReceived::messageWebAppDataReceived()
  : button_text_()
  , data_()
{}

messageWebAppDataReceived::messageWebAppDataReceived(string const &button_text_, string const &data_)
  : button_text_(button_text_)
  , data_(data_)
{}

const std::int32_t messageWebAppDataReceived::ID;

void messageWebAppDataReceived::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageWebAppDataReceived");
    s.store_field("button_text", button_text_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

messagePassportDataSent::messagePassportDataSent()
  : types_()
{}

messagePassportDataSent::messagePassportDataSent(array<object_ptr<PassportElementType>> &&types_)
  : types_(std::move(types_))
{}

const std::int32_t messagePassportDataSent::ID;

void messagePassportDataSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePassportDataSent");
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messagePassportDataReceived::messagePassportDataReceived()
  : elements_()
  , credentials_()
{}

messagePassportDataReceived::messagePassportDataReceived(array<object_ptr<encryptedPassportElement>> &&elements_, object_ptr<encryptedCredentials> &&credentials_)
  : elements_(std::move(elements_))
  , credentials_(std::move(credentials_))
{}

const std::int32_t messagePassportDataReceived::ID;

void messagePassportDataReceived::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePassportDataReceived");
    { s.store_vector_begin("elements", elements_.size()); for (const auto &_value : elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    s.store_class_end();
  }
}

messageProximityAlertTriggered::messageProximityAlertTriggered()
  : traveler_id_()
  , watcher_id_()
  , distance_()
{}

messageProximityAlertTriggered::messageProximityAlertTriggered(object_ptr<MessageSender> &&traveler_id_, object_ptr<MessageSender> &&watcher_id_, int32 distance_)
  : traveler_id_(std::move(traveler_id_))
  , watcher_id_(std::move(watcher_id_))
  , distance_(distance_)
{}

const std::int32_t messageProximityAlertTriggered::ID;

void messageProximityAlertTriggered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageProximityAlertTriggered");
    s.store_object_field("traveler_id", static_cast<const BaseObject *>(traveler_id_.get()));
    s.store_object_field("watcher_id", static_cast<const BaseObject *>(watcher_id_.get()));
    s.store_field("distance", distance_);
    s.store_class_end();
  }
}

messageUnsupported::messageUnsupported() {
}

const std::int32_t messageUnsupported::ID;

void messageUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageUnsupported");
    s.store_class_end();
  }
}

messageCopyOptions::messageCopyOptions()
  : send_copy_()
  , replace_caption_()
  , new_caption_()
{}

messageCopyOptions::messageCopyOptions(bool send_copy_, bool replace_caption_, object_ptr<formattedText> &&new_caption_)
  : send_copy_(send_copy_)
  , replace_caption_(replace_caption_)
  , new_caption_(std::move(new_caption_))
{}

const std::int32_t messageCopyOptions::ID;

void messageCopyOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCopyOptions");
    s.store_field("send_copy", send_copy_);
    s.store_field("replace_caption", replace_caption_);
    s.store_object_field("new_caption", static_cast<const BaseObject *>(new_caption_.get()));
    s.store_class_end();
  }
}

messageFileTypePrivate::messageFileTypePrivate()
  : name_()
{}

messageFileTypePrivate::messageFileTypePrivate(string const &name_)
  : name_(name_)
{}

const std::int32_t messageFileTypePrivate::ID;

void messageFileTypePrivate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageFileTypePrivate");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

messageFileTypeGroup::messageFileTypeGroup()
  : title_()
{}

messageFileTypeGroup::messageFileTypeGroup(string const &title_)
  : title_(title_)
{}

const std::int32_t messageFileTypeGroup::ID;

void messageFileTypeGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageFileTypeGroup");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

messageFileTypeUnknown::messageFileTypeUnknown() {
}

const std::int32_t messageFileTypeUnknown::ID;

void messageFileTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageFileTypeUnknown");
    s.store_class_end();
  }
}

messageForwardInfo::messageForwardInfo()
  : origin_()
  , date_()
  , public_service_announcement_type_()
  , from_chat_id_()
  , from_message_id_()
{}

messageForwardInfo::messageForwardInfo(object_ptr<MessageForwardOrigin> &&origin_, int32 date_, string const &public_service_announcement_type_, int53 from_chat_id_, int53 from_message_id_)
  : origin_(std::move(origin_))
  , date_(date_)
  , public_service_announcement_type_(public_service_announcement_type_)
  , from_chat_id_(from_chat_id_)
  , from_message_id_(from_message_id_)
{}

const std::int32_t messageForwardInfo::ID;

void messageForwardInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForwardInfo");
    s.store_object_field("origin", static_cast<const BaseObject *>(origin_.get()));
    s.store_field("date", date_);
    s.store_field("public_service_announcement_type", public_service_announcement_type_);
    s.store_field("from_chat_id", from_chat_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_class_end();
  }
}

messageForwardOriginUser::messageForwardOriginUser()
  : sender_user_id_()
{}

messageForwardOriginUser::messageForwardOriginUser(int53 sender_user_id_)
  : sender_user_id_(sender_user_id_)
{}

const std::int32_t messageForwardOriginUser::ID;

void messageForwardOriginUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForwardOriginUser");
    s.store_field("sender_user_id", sender_user_id_);
    s.store_class_end();
  }
}

messageForwardOriginChat::messageForwardOriginChat()
  : sender_chat_id_()
  , author_signature_()
{}

messageForwardOriginChat::messageForwardOriginChat(int53 sender_chat_id_, string const &author_signature_)
  : sender_chat_id_(sender_chat_id_)
  , author_signature_(author_signature_)
{}

const std::int32_t messageForwardOriginChat::ID;

void messageForwardOriginChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForwardOriginChat");
    s.store_field("sender_chat_id", sender_chat_id_);
    s.store_field("author_signature", author_signature_);
    s.store_class_end();
  }
}

messageForwardOriginHiddenUser::messageForwardOriginHiddenUser()
  : sender_name_()
{}

messageForwardOriginHiddenUser::messageForwardOriginHiddenUser(string const &sender_name_)
  : sender_name_(sender_name_)
{}

const std::int32_t messageForwardOriginHiddenUser::ID;

void messageForwardOriginHiddenUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForwardOriginHiddenUser");
    s.store_field("sender_name", sender_name_);
    s.store_class_end();
  }
}

messageForwardOriginChannel::messageForwardOriginChannel()
  : chat_id_()
  , message_id_()
  , author_signature_()
{}

messageForwardOriginChannel::messageForwardOriginChannel(int53 chat_id_, int53 message_id_, string const &author_signature_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , author_signature_(author_signature_)
{}

const std::int32_t messageForwardOriginChannel::ID;

void messageForwardOriginChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForwardOriginChannel");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("author_signature", author_signature_);
    s.store_class_end();
  }
}

messageForwardOriginMessageImport::messageForwardOriginMessageImport()
  : sender_name_()
{}

messageForwardOriginMessageImport::messageForwardOriginMessageImport(string const &sender_name_)
  : sender_name_(sender_name_)
{}

const std::int32_t messageForwardOriginMessageImport::ID;

void messageForwardOriginMessageImport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageForwardOriginMessageImport");
    s.store_field("sender_name", sender_name_);
    s.store_class_end();
  }
}

messageInteractionInfo::messageInteractionInfo()
  : view_count_()
  , forward_count_()
  , reply_info_()
  , reactions_()
{}

messageInteractionInfo::messageInteractionInfo(int32 view_count_, int32 forward_count_, object_ptr<messageReplyInfo> &&reply_info_, array<object_ptr<messageReaction>> &&reactions_)
  : view_count_(view_count_)
  , forward_count_(forward_count_)
  , reply_info_(std::move(reply_info_))
  , reactions_(std::move(reactions_))
{}

const std::int32_t messageInteractionInfo::ID;

void messageInteractionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageInteractionInfo");
    s.store_field("view_count", view_count_);
    s.store_field("forward_count", forward_count_);
    s.store_object_field("reply_info", static_cast<const BaseObject *>(reply_info_.get()));
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageLink::messageLink()
  : link_()
  , is_public_()
{}

messageLink::messageLink(string const &link_, bool is_public_)
  : link_(link_)
  , is_public_(is_public_)
{}

const std::int32_t messageLink::ID;

void messageLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageLink");
    s.store_field("link", link_);
    s.store_field("is_public", is_public_);
    s.store_class_end();
  }
}

messageLinkInfo::messageLinkInfo()
  : is_public_()
  , chat_id_()
  , message_()
  , media_timestamp_()
  , for_album_()
  , for_comment_()
{}

messageLinkInfo::messageLinkInfo(bool is_public_, int53 chat_id_, object_ptr<message> &&message_, int32 media_timestamp_, bool for_album_, bool for_comment_)
  : is_public_(is_public_)
  , chat_id_(chat_id_)
  , message_(std::move(message_))
  , media_timestamp_(media_timestamp_)
  , for_album_(for_album_)
  , for_comment_(for_comment_)
{}

const std::int32_t messageLinkInfo::ID;

void messageLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageLinkInfo");
    s.store_field("is_public", is_public_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("media_timestamp", media_timestamp_);
    s.store_field("for_album", for_album_);
    s.store_field("for_comment", for_comment_);
    s.store_class_end();
  }
}

messagePosition::messagePosition()
  : position_()
  , message_id_()
  , date_()
{}

messagePosition::messagePosition(int32 position_, int53 message_id_, int32 date_)
  : position_(position_)
  , message_id_(message_id_)
  , date_(date_)
{}

const std::int32_t messagePosition::ID;

void messagePosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePosition");
    s.store_field("position", position_);
    s.store_field("message_id", message_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

messagePositions::messagePositions()
  : total_count_()
  , positions_()
{}

messagePositions::messagePositions(int32 total_count_, array<object_ptr<messagePosition>> &&positions_)
  : total_count_(total_count_)
  , positions_(std::move(positions_))
{}

const std::int32_t messagePositions::ID;

void messagePositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePositions");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageReaction::messageReaction()
  : reaction_()
  , total_count_()
  , is_chosen_()
  , recent_sender_ids_()
{}

messageReaction::messageReaction(string const &reaction_, int32 total_count_, bool is_chosen_, array<object_ptr<MessageSender>> &&recent_sender_ids_)
  : reaction_(reaction_)
  , total_count_(total_count_)
  , is_chosen_(is_chosen_)
  , recent_sender_ids_(std::move(recent_sender_ids_))
{}

const std::int32_t messageReaction::ID;

void messageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReaction");
    s.store_field("reaction", reaction_);
    s.store_field("total_count", total_count_);
    s.store_field("is_chosen", is_chosen_);
    { s.store_vector_begin("recent_sender_ids", recent_sender_ids_.size()); for (const auto &_value : recent_sender_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageReplyInfo::messageReplyInfo()
  : reply_count_()
  , recent_replier_ids_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , last_message_id_()
{}

messageReplyInfo::messageReplyInfo(int32 reply_count_, array<object_ptr<MessageSender>> &&recent_replier_ids_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int53 last_message_id_)
  : reply_count_(reply_count_)
  , recent_replier_ids_(std::move(recent_replier_ids_))
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , last_message_id_(last_message_id_)
{}

const std::int32_t messageReplyInfo::ID;

void messageReplyInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplyInfo");
    s.store_field("reply_count", reply_count_);
    { s.store_vector_begin("recent_replier_ids", recent_replier_ids_.size()); for (const auto &_value : recent_replier_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_field("last_message_id", last_message_id_);
    s.store_class_end();
  }
}

messageSchedulingStateSendAtDate::messageSchedulingStateSendAtDate()
  : send_date_()
{}

messageSchedulingStateSendAtDate::messageSchedulingStateSendAtDate(int32 send_date_)
  : send_date_(send_date_)
{}

const std::int32_t messageSchedulingStateSendAtDate::ID;

void messageSchedulingStateSendAtDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSchedulingStateSendAtDate");
    s.store_field("send_date", send_date_);
    s.store_class_end();
  }
}

messageSchedulingStateSendWhenOnline::messageSchedulingStateSendWhenOnline() {
}

const std::int32_t messageSchedulingStateSendWhenOnline::ID;

void messageSchedulingStateSendWhenOnline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSchedulingStateSendWhenOnline");
    s.store_class_end();
  }
}

messageSendOptions::messageSendOptions()
  : disable_notification_()
  , from_background_()
  , protect_content_()
  , scheduling_state_()
{}

messageSendOptions::messageSendOptions(bool disable_notification_, bool from_background_, bool protect_content_, object_ptr<MessageSchedulingState> &&scheduling_state_)
  : disable_notification_(disable_notification_)
  , from_background_(from_background_)
  , protect_content_(protect_content_)
  , scheduling_state_(std::move(scheduling_state_))
{}

const std::int32_t messageSendOptions::ID;

void messageSendOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSendOptions");
    s.store_field("disable_notification", disable_notification_);
    s.store_field("from_background", from_background_);
    s.store_field("protect_content", protect_content_);
    s.store_object_field("scheduling_state", static_cast<const BaseObject *>(scheduling_state_.get()));
    s.store_class_end();
  }
}

messageSenderUser::messageSenderUser()
  : user_id_()
{}

messageSenderUser::messageSenderUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t messageSenderUser::ID;

void messageSenderUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSenderUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

messageSenderChat::messageSenderChat()
  : chat_id_()
{}

messageSenderChat::messageSenderChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t messageSenderChat::ID;

void messageSenderChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSenderChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

messageSenders::messageSenders()
  : total_count_()
  , senders_()
{}

messageSenders::messageSenders(int32 total_count_, array<object_ptr<MessageSender>> &&senders_)
  : total_count_(total_count_)
  , senders_(std::move(senders_))
{}

const std::int32_t messageSenders::ID;

void messageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSenders");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("senders", senders_.size()); for (const auto &_value : senders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageSendingStatePending::messageSendingStatePending() {
}

const std::int32_t messageSendingStatePending::ID;

void messageSendingStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSendingStatePending");
    s.store_class_end();
  }
}

messageSendingStateFailed::messageSendingStateFailed()
  : error_code_()
  , error_message_()
  , can_retry_()
  , need_another_sender_()
  , retry_after_()
{}

messageSendingStateFailed::messageSendingStateFailed(int32 error_code_, string const &error_message_, bool can_retry_, bool need_another_sender_, double retry_after_)
  : error_code_(error_code_)
  , error_message_(error_message_)
  , can_retry_(can_retry_)
  , need_another_sender_(need_another_sender_)
  , retry_after_(retry_after_)
{}

const std::int32_t messageSendingStateFailed::ID;

void messageSendingStateFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSendingStateFailed");
    s.store_field("error_code", error_code_);
    s.store_field("error_message", error_message_);
    s.store_field("can_retry", can_retry_);
    s.store_field("need_another_sender", need_another_sender_);
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

messageStatistics::messageStatistics()
  : message_interaction_graph_()
{}

messageStatistics::messageStatistics(object_ptr<StatisticalGraph> &&message_interaction_graph_)
  : message_interaction_graph_(std::move(message_interaction_graph_))
{}

const std::int32_t messageStatistics::ID;

void messageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageStatistics");
    s.store_object_field("message_interaction_graph", static_cast<const BaseObject *>(message_interaction_graph_.get()));
    s.store_class_end();
  }
}

messageThreadInfo::messageThreadInfo()
  : chat_id_()
  , message_thread_id_()
  , reply_info_()
  , unread_message_count_()
  , messages_()
  , draft_message_()
{}

messageThreadInfo::messageThreadInfo(int53 chat_id_, int53 message_thread_id_, object_ptr<messageReplyInfo> &&reply_info_, int32 unread_message_count_, array<object_ptr<message>> &&messages_, object_ptr<draftMessage> &&draft_message_)
  : chat_id_(chat_id_)
  , message_thread_id_(message_thread_id_)
  , reply_info_(std::move(reply_info_))
  , unread_message_count_(unread_message_count_)
  , messages_(std::move(messages_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t messageThreadInfo::ID;

void messageThreadInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageThreadInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_thread_id", message_thread_id_);
    s.store_object_field("reply_info", static_cast<const BaseObject *>(reply_info_.get()));
    s.store_field("unread_message_count", unread_message_count_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

messages::messages()
  : total_count_()
  , messages_()
{}

messages::messages(int32 total_count_, array<object_ptr<message>> &&messages_)
  : total_count_(total_count_)
  , messages_(std::move(messages_))
{}

const std::int32_t messages::ID;

void messages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

minithumbnail::minithumbnail()
  : width_()
  , height_()
  , data_()
{}

minithumbnail::minithumbnail(int32 width_, int32 height_, bytes const &data_)
  : width_(width_)
  , height_(height_)
  , data_(std::move(data_))
{}

const std::int32_t minithumbnail::ID;

void minithumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "minithumbnail");
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

networkStatistics::networkStatistics()
  : since_date_()
  , entries_()
{}

networkStatistics::networkStatistics(int32 since_date_, array<object_ptr<NetworkStatisticsEntry>> &&entries_)
  : since_date_(since_date_)
  , entries_(std::move(entries_))
{}

const std::int32_t networkStatistics::ID;

void networkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkStatistics");
    s.store_field("since_date", since_date_);
    { s.store_vector_begin("entries", entries_.size()); for (const auto &_value : entries_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

networkStatisticsEntryFile::networkStatisticsEntryFile()
  : file_type_()
  , network_type_()
  , sent_bytes_()
  , received_bytes_()
{}

networkStatisticsEntryFile::networkStatisticsEntryFile(object_ptr<FileType> &&file_type_, object_ptr<NetworkType> &&network_type_, int53 sent_bytes_, int53 received_bytes_)
  : file_type_(std::move(file_type_))
  , network_type_(std::move(network_type_))
  , sent_bytes_(sent_bytes_)
  , received_bytes_(received_bytes_)
{}

const std::int32_t networkStatisticsEntryFile::ID;

void networkStatisticsEntryFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkStatisticsEntryFile");
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_object_field("network_type", static_cast<const BaseObject *>(network_type_.get()));
    s.store_field("sent_bytes", sent_bytes_);
    s.store_field("received_bytes", received_bytes_);
    s.store_class_end();
  }
}

networkStatisticsEntryCall::networkStatisticsEntryCall()
  : network_type_()
  , sent_bytes_()
  , received_bytes_()
  , duration_()
{}

networkStatisticsEntryCall::networkStatisticsEntryCall(object_ptr<NetworkType> &&network_type_, int53 sent_bytes_, int53 received_bytes_, double duration_)
  : network_type_(std::move(network_type_))
  , sent_bytes_(sent_bytes_)
  , received_bytes_(received_bytes_)
  , duration_(duration_)
{}

const std::int32_t networkStatisticsEntryCall::ID;

void networkStatisticsEntryCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkStatisticsEntryCall");
    s.store_object_field("network_type", static_cast<const BaseObject *>(network_type_.get()));
    s.store_field("sent_bytes", sent_bytes_);
    s.store_field("received_bytes", received_bytes_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

networkTypeNone::networkTypeNone() {
}

const std::int32_t networkTypeNone::ID;

void networkTypeNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeNone");
    s.store_class_end();
  }
}

networkTypeMobile::networkTypeMobile() {
}

const std::int32_t networkTypeMobile::ID;

void networkTypeMobile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeMobile");
    s.store_class_end();
  }
}

networkTypeMobileRoaming::networkTypeMobileRoaming() {
}

const std::int32_t networkTypeMobileRoaming::ID;

void networkTypeMobileRoaming::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeMobileRoaming");
    s.store_class_end();
  }
}

networkTypeWiFi::networkTypeWiFi() {
}

const std::int32_t networkTypeWiFi::ID;

void networkTypeWiFi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeWiFi");
    s.store_class_end();
  }
}

networkTypeOther::networkTypeOther() {
}

const std::int32_t networkTypeOther::ID;

void networkTypeOther::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeOther");
    s.store_class_end();
  }
}

notification::notification()
  : id_()
  , date_()
  , is_silent_()
  , type_()
{}

notification::notification(int32 id_, int32 date_, bool is_silent_, object_ptr<NotificationType> &&type_)
  : id_(id_)
  , date_(date_)
  , is_silent_(is_silent_)
  , type_(std::move(type_))
{}

const std::int32_t notification::ID;

void notification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notification");
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_field("is_silent", is_silent_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

notificationGroup::notificationGroup()
  : id_()
  , type_()
  , chat_id_()
  , total_count_()
  , notifications_()
{}

notificationGroup::notificationGroup(int32 id_, object_ptr<NotificationGroupType> &&type_, int53 chat_id_, int32 total_count_, array<object_ptr<notification>> &&notifications_)
  : id_(id_)
  , type_(std::move(type_))
  , chat_id_(chat_id_)
  , total_count_(total_count_)
  , notifications_(std::move(notifications_))
{}

const std::int32_t notificationGroup::ID;

void notificationGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroup");
    s.store_field("id", id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("notifications", notifications_.size()); for (const auto &_value : notifications_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

notificationGroupTypeMessages::notificationGroupTypeMessages() {
}

const std::int32_t notificationGroupTypeMessages::ID;

void notificationGroupTypeMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeMessages");
    s.store_class_end();
  }
}

notificationGroupTypeMentions::notificationGroupTypeMentions() {
}

const std::int32_t notificationGroupTypeMentions::ID;

void notificationGroupTypeMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeMentions");
    s.store_class_end();
  }
}

notificationGroupTypeSecretChat::notificationGroupTypeSecretChat() {
}

const std::int32_t notificationGroupTypeSecretChat::ID;

void notificationGroupTypeSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeSecretChat");
    s.store_class_end();
  }
}

notificationGroupTypeCalls::notificationGroupTypeCalls() {
}

const std::int32_t notificationGroupTypeCalls::ID;

void notificationGroupTypeCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationGroupTypeCalls");
    s.store_class_end();
  }
}

notificationSettingsScopePrivateChats::notificationSettingsScopePrivateChats() {
}

const std::int32_t notificationSettingsScopePrivateChats::ID;

void notificationSettingsScopePrivateChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSettingsScopePrivateChats");
    s.store_class_end();
  }
}

notificationSettingsScopeGroupChats::notificationSettingsScopeGroupChats() {
}

const std::int32_t notificationSettingsScopeGroupChats::ID;

void notificationSettingsScopeGroupChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSettingsScopeGroupChats");
    s.store_class_end();
  }
}

notificationSettingsScopeChannelChats::notificationSettingsScopeChannelChats() {
}

const std::int32_t notificationSettingsScopeChannelChats::ID;

void notificationSettingsScopeChannelChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSettingsScopeChannelChats");
    s.store_class_end();
  }
}

notificationSound::notificationSound()
  : id_()
  , duration_()
  , date_()
  , title_()
  , data_()
  , sound_()
{}

notificationSound::notificationSound(int64 id_, int32 duration_, int32 date_, string const &title_, string const &data_, object_ptr<file> &&sound_)
  : id_(id_)
  , duration_(duration_)
  , date_(date_)
  , title_(title_)
  , data_(data_)
  , sound_(std::move(sound_))
{}

const std::int32_t notificationSound::ID;

void notificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSound");
    s.store_field("id", id_);
    s.store_field("duration", duration_);
    s.store_field("date", date_);
    s.store_field("title", title_);
    s.store_field("data", data_);
    s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get()));
    s.store_class_end();
  }
}

notificationSounds::notificationSounds()
  : notification_sounds_()
{}

notificationSounds::notificationSounds(array<object_ptr<notificationSound>> &&notification_sounds_)
  : notification_sounds_(std::move(notification_sounds_))
{}

const std::int32_t notificationSounds::ID;

void notificationSounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSounds");
    { s.store_vector_begin("notification_sounds", notification_sounds_.size()); for (const auto &_value : notification_sounds_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

notificationTypeNewMessage::notificationTypeNewMessage()
  : message_()
{}

notificationTypeNewMessage::notificationTypeNewMessage(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t notificationTypeNewMessage::ID;

void notificationTypeNewMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

notificationTypeNewSecretChat::notificationTypeNewSecretChat() {
}

const std::int32_t notificationTypeNewSecretChat::ID;

void notificationTypeNewSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewSecretChat");
    s.store_class_end();
  }
}

notificationTypeNewCall::notificationTypeNewCall()
  : call_id_()
{}

notificationTypeNewCall::notificationTypeNewCall(int32 call_id_)
  : call_id_(call_id_)
{}

const std::int32_t notificationTypeNewCall::ID;

void notificationTypeNewCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewCall");
    s.store_field("call_id", call_id_);
    s.store_class_end();
  }
}

notificationTypeNewPushMessage::notificationTypeNewPushMessage()
  : message_id_()
  , sender_id_()
  , sender_name_()
  , is_outgoing_()
  , content_()
{}

notificationTypeNewPushMessage::notificationTypeNewPushMessage(int53 message_id_, object_ptr<MessageSender> &&sender_id_, string const &sender_name_, bool is_outgoing_, object_ptr<PushMessageContent> &&content_)
  : message_id_(message_id_)
  , sender_id_(std::move(sender_id_))
  , sender_name_(sender_name_)
  , is_outgoing_(is_outgoing_)
  , content_(std::move(content_))
{}

const std::int32_t notificationTypeNewPushMessage::ID;

void notificationTypeNewPushMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationTypeNewPushMessage");
    s.store_field("message_id", message_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("sender_name", sender_name_);
    s.store_field("is_outgoing", is_outgoing_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

ok::ok() {
}

const std::int32_t ok::ID;

void ok::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ok");
    s.store_class_end();
  }
}

optionValueBoolean::optionValueBoolean()
  : value_()
{}

optionValueBoolean::optionValueBoolean(bool value_)
  : value_(value_)
{}

const std::int32_t optionValueBoolean::ID;

void optionValueBoolean::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueBoolean");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

optionValueEmpty::optionValueEmpty() {
}

const std::int32_t optionValueEmpty::ID;

void optionValueEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueEmpty");
    s.store_class_end();
  }
}

optionValueInteger::optionValueInteger()
  : value_()
{}

optionValueInteger::optionValueInteger(int64 value_)
  : value_(value_)
{}

const std::int32_t optionValueInteger::ID;

void optionValueInteger::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueInteger");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

optionValueString::optionValueString()
  : value_()
{}

optionValueString::optionValueString(string const &value_)
  : value_(value_)
{}

const std::int32_t optionValueString::ID;

void optionValueString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueString");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

orderInfo::orderInfo()
  : name_()
  , phone_number_()
  , email_address_()
  , shipping_address_()
{}

orderInfo::orderInfo(string const &name_, string const &phone_number_, string const &email_address_, object_ptr<address> &&shipping_address_)
  : name_(name_)
  , phone_number_(phone_number_)
  , email_address_(email_address_)
  , shipping_address_(std::move(shipping_address_))
{}

const std::int32_t orderInfo::ID;

void orderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "orderInfo");
    s.store_field("name", name_);
    s.store_field("phone_number", phone_number_);
    s.store_field("email_address", email_address_);
    s.store_object_field("shipping_address", static_cast<const BaseObject *>(shipping_address_.get()));
    s.store_class_end();
  }
}

pageBlockTitle::pageBlockTitle()
  : title_()
{}

pageBlockTitle::pageBlockTitle(object_ptr<RichText> &&title_)
  : title_(std::move(title_))
{}

const std::int32_t pageBlockTitle::ID;

void pageBlockTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTitle");
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    s.store_class_end();
  }
}

pageBlockSubtitle::pageBlockSubtitle()
  : subtitle_()
{}

pageBlockSubtitle::pageBlockSubtitle(object_ptr<RichText> &&subtitle_)
  : subtitle_(std::move(subtitle_))
{}

const std::int32_t pageBlockSubtitle::ID;

void pageBlockSubtitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSubtitle");
    s.store_object_field("subtitle", static_cast<const BaseObject *>(subtitle_.get()));
    s.store_class_end();
  }
}

pageBlockAuthorDate::pageBlockAuthorDate()
  : author_()
  , publish_date_()
{}

pageBlockAuthorDate::pageBlockAuthorDate(object_ptr<RichText> &&author_, int32 publish_date_)
  : author_(std::move(author_))
  , publish_date_(publish_date_)
{}

const std::int32_t pageBlockAuthorDate::ID;

void pageBlockAuthorDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAuthorDate");
    s.store_object_field("author", static_cast<const BaseObject *>(author_.get()));
    s.store_field("publish_date", publish_date_);
    s.store_class_end();
  }
}

pageBlockHeader::pageBlockHeader()
  : header_()
{}

pageBlockHeader::pageBlockHeader(object_ptr<RichText> &&header_)
  : header_(std::move(header_))
{}

const std::int32_t pageBlockHeader::ID;

void pageBlockHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHeader");
    s.store_object_field("header", static_cast<const BaseObject *>(header_.get()));
    s.store_class_end();
  }
}

pageBlockSubheader::pageBlockSubheader()
  : subheader_()
{}

pageBlockSubheader::pageBlockSubheader(object_ptr<RichText> &&subheader_)
  : subheader_(std::move(subheader_))
{}

const std::int32_t pageBlockSubheader::ID;

void pageBlockSubheader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSubheader");
    s.store_object_field("subheader", static_cast<const BaseObject *>(subheader_.get()));
    s.store_class_end();
  }
}

pageBlockKicker::pageBlockKicker()
  : kicker_()
{}

pageBlockKicker::pageBlockKicker(object_ptr<RichText> &&kicker_)
  : kicker_(std::move(kicker_))
{}

const std::int32_t pageBlockKicker::ID;

void pageBlockKicker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockKicker");
    s.store_object_field("kicker", static_cast<const BaseObject *>(kicker_.get()));
    s.store_class_end();
  }
}

pageBlockParagraph::pageBlockParagraph()
  : text_()
{}

pageBlockParagraph::pageBlockParagraph(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockParagraph::ID;

void pageBlockParagraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockParagraph");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockPreformatted::pageBlockPreformatted()
  : text_()
  , language_()
{}

pageBlockPreformatted::pageBlockPreformatted(object_ptr<RichText> &&text_, string const &language_)
  : text_(std::move(text_))
  , language_(language_)
{}

const std::int32_t pageBlockPreformatted::ID;

void pageBlockPreformatted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPreformatted");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("language", language_);
    s.store_class_end();
  }
}

pageBlockFooter::pageBlockFooter()
  : footer_()
{}

pageBlockFooter::pageBlockFooter(object_ptr<RichText> &&footer_)
  : footer_(std::move(footer_))
{}

const std::int32_t pageBlockFooter::ID;

void pageBlockFooter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockFooter");
    s.store_object_field("footer", static_cast<const BaseObject *>(footer_.get()));
    s.store_class_end();
  }
}

pageBlockDivider::pageBlockDivider() {
}

const std::int32_t pageBlockDivider::ID;

void pageBlockDivider::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDivider");
    s.store_class_end();
  }
}

pageBlockAnchor::pageBlockAnchor()
  : name_()
{}

pageBlockAnchor::pageBlockAnchor(string const &name_)
  : name_(name_)
{}

const std::int32_t pageBlockAnchor::ID;

void pageBlockAnchor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAnchor");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

pageBlockList::pageBlockList()
  : items_()
{}

pageBlockList::pageBlockList(array<object_ptr<pageBlockListItem>> &&items_)
  : items_(std::move(items_))
{}

const std::int32_t pageBlockList::ID;

void pageBlockList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockList");
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockBlockQuote::pageBlockBlockQuote()
  : text_()
  , credit_()
{}

pageBlockBlockQuote::pageBlockBlockQuote(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageBlockBlockQuote::ID;

void pageBlockBlockQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockBlockQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

pageBlockPullQuote::pageBlockPullQuote()
  : text_()
  , credit_()
{}

pageBlockPullQuote::pageBlockPullQuote(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageBlockPullQuote::ID;

void pageBlockPullQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPullQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

pageBlockAnimation::pageBlockAnimation()
  : animation_()
  , caption_()
  , need_autoplay_()
{}

pageBlockAnimation::pageBlockAnimation(object_ptr<animation> &&animation_, object_ptr<pageBlockCaption> &&caption_, bool need_autoplay_)
  : animation_(std::move(animation_))
  , caption_(std::move(caption_))
  , need_autoplay_(need_autoplay_)
{}

const std::int32_t pageBlockAnimation::ID;

void pageBlockAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("need_autoplay", need_autoplay_);
    s.store_class_end();
  }
}

pageBlockAudio::pageBlockAudio()
  : audio_()
  , caption_()
{}

pageBlockAudio::pageBlockAudio(object_ptr<audio> &&audio_, object_ptr<pageBlockCaption> &&caption_)
  : audio_(std::move(audio_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockAudio::ID;

void pageBlockAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockPhoto::pageBlockPhoto()
  : photo_()
  , caption_()
  , url_()
{}

pageBlockPhoto::pageBlockPhoto(object_ptr<photo> &&photo_, object_ptr<pageBlockCaption> &&caption_, string const &url_)
  : photo_(std::move(photo_))
  , caption_(std::move(caption_))
  , url_(url_)
{}

const std::int32_t pageBlockPhoto::ID;

void pageBlockPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("url", url_);
    s.store_class_end();
  }
}

pageBlockVideo::pageBlockVideo()
  : video_()
  , caption_()
  , need_autoplay_()
  , is_looped_()
{}

pageBlockVideo::pageBlockVideo(object_ptr<video> &&video_, object_ptr<pageBlockCaption> &&caption_, bool need_autoplay_, bool is_looped_)
  : video_(std::move(video_))
  , caption_(std::move(caption_))
  , need_autoplay_(need_autoplay_)
  , is_looped_(is_looped_)
{}

const std::int32_t pageBlockVideo::ID;

void pageBlockVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("need_autoplay", need_autoplay_);
    s.store_field("is_looped", is_looped_);
    s.store_class_end();
  }
}

pageBlockVoiceNote::pageBlockVoiceNote()
  : voice_note_()
  , caption_()
{}

pageBlockVoiceNote::pageBlockVoiceNote(object_ptr<voiceNote> &&voice_note_, object_ptr<pageBlockCaption> &&caption_)
  : voice_note_(std::move(voice_note_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockVoiceNote::ID;

void pageBlockVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockCover::pageBlockCover()
  : cover_()
{}

pageBlockCover::pageBlockCover(object_ptr<PageBlock> &&cover_)
  : cover_(std::move(cover_))
{}

const std::int32_t pageBlockCover::ID;

void pageBlockCover::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCover");
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_class_end();
  }
}

pageBlockEmbedded::pageBlockEmbedded()
  : url_()
  , html_()
  , poster_photo_()
  , width_()
  , height_()
  , caption_()
  , is_full_width_()
  , allow_scrolling_()
{}

pageBlockEmbedded::pageBlockEmbedded(string const &url_, string const &html_, object_ptr<photo> &&poster_photo_, int32 width_, int32 height_, object_ptr<pageBlockCaption> &&caption_, bool is_full_width_, bool allow_scrolling_)
  : url_(url_)
  , html_(html_)
  , poster_photo_(std::move(poster_photo_))
  , width_(width_)
  , height_(height_)
  , caption_(std::move(caption_))
  , is_full_width_(is_full_width_)
  , allow_scrolling_(allow_scrolling_)
{}

const std::int32_t pageBlockEmbedded::ID;

void pageBlockEmbedded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockEmbedded");
    s.store_field("url", url_);
    s.store_field("html", html_);
    s.store_object_field("poster_photo", static_cast<const BaseObject *>(poster_photo_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("is_full_width", is_full_width_);
    s.store_field("allow_scrolling", allow_scrolling_);
    s.store_class_end();
  }
}

pageBlockEmbeddedPost::pageBlockEmbeddedPost()
  : url_()
  , author_()
  , author_photo_()
  , date_()
  , page_blocks_()
  , caption_()
{}

pageBlockEmbeddedPost::pageBlockEmbeddedPost(string const &url_, string const &author_, object_ptr<photo> &&author_photo_, int32 date_, array<object_ptr<PageBlock>> &&page_blocks_, object_ptr<pageBlockCaption> &&caption_)
  : url_(url_)
  , author_(author_)
  , author_photo_(std::move(author_photo_))
  , date_(date_)
  , page_blocks_(std::move(page_blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockEmbeddedPost::ID;

void pageBlockEmbeddedPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockEmbeddedPost");
    s.store_field("url", url_);
    s.store_field("author", author_);
    s.store_object_field("author_photo", static_cast<const BaseObject *>(author_photo_.get()));
    s.store_field("date", date_);
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockCollage::pageBlockCollage()
  : page_blocks_()
  , caption_()
{}

pageBlockCollage::pageBlockCollage(array<object_ptr<PageBlock>> &&page_blocks_, object_ptr<pageBlockCaption> &&caption_)
  : page_blocks_(std::move(page_blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockCollage::ID;

void pageBlockCollage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCollage");
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockSlideshow::pageBlockSlideshow()
  : page_blocks_()
  , caption_()
{}

pageBlockSlideshow::pageBlockSlideshow(array<object_ptr<PageBlock>> &&page_blocks_, object_ptr<pageBlockCaption> &&caption_)
  : page_blocks_(std::move(page_blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockSlideshow::ID;

void pageBlockSlideshow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSlideshow");
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockChatLink::pageBlockChatLink()
  : title_()
  , photo_()
  , username_()
{}

pageBlockChatLink::pageBlockChatLink(string const &title_, object_ptr<chatPhotoInfo> &&photo_, string const &username_)
  : title_(title_)
  , photo_(std::move(photo_))
  , username_(username_)
{}

const std::int32_t pageBlockChatLink::ID;

void pageBlockChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockChatLink");
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("username", username_);
    s.store_class_end();
  }
}

pageBlockTable::pageBlockTable()
  : caption_()
  , cells_()
  , is_bordered_()
  , is_striped_()
{}

pageBlockTable::pageBlockTable(object_ptr<RichText> &&caption_, array<array<object_ptr<pageBlockTableCell>>> &&cells_, bool is_bordered_, bool is_striped_)
  : caption_(std::move(caption_))
  , cells_(std::move(cells_))
  , is_bordered_(is_bordered_)
  , is_striped_(is_striped_)
{}

const std::int32_t pageBlockTable::ID;

void pageBlockTable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTable");
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    { s.store_vector_begin("cells", cells_.size()); for (const auto &_value : cells_) { { s.store_vector_begin("", _value.size()); for (const auto &_value2 : _value) { s.store_object_field("", static_cast<const BaseObject *>(_value2.get())); } s.store_class_end(); } } s.store_class_end(); }
    s.store_field("is_bordered", is_bordered_);
    s.store_field("is_striped", is_striped_);
    s.store_class_end();
  }
}

pageBlockDetails::pageBlockDetails()
  : header_()
  , page_blocks_()
  , is_open_()
{}

pageBlockDetails::pageBlockDetails(object_ptr<RichText> &&header_, array<object_ptr<PageBlock>> &&page_blocks_, bool is_open_)
  : header_(std::move(header_))
  , page_blocks_(std::move(page_blocks_))
  , is_open_(is_open_)
{}

const std::int32_t pageBlockDetails::ID;

void pageBlockDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDetails");
    s.store_object_field("header", static_cast<const BaseObject *>(header_.get()));
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_open", is_open_);
    s.store_class_end();
  }
}

pageBlockRelatedArticles::pageBlockRelatedArticles()
  : header_()
  , articles_()
{}

pageBlockRelatedArticles::pageBlockRelatedArticles(object_ptr<RichText> &&header_, array<object_ptr<pageBlockRelatedArticle>> &&articles_)
  : header_(std::move(header_))
  , articles_(std::move(articles_))
{}

const std::int32_t pageBlockRelatedArticles::ID;

void pageBlockRelatedArticles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockRelatedArticles");
    s.store_object_field("header", static_cast<const BaseObject *>(header_.get()));
    { s.store_vector_begin("articles", articles_.size()); for (const auto &_value : articles_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockMap::pageBlockMap()
  : location_()
  , zoom_()
  , width_()
  , height_()
  , caption_()
{}

pageBlockMap::pageBlockMap(object_ptr<location> &&location_, int32 zoom_, int32 width_, int32 height_, object_ptr<pageBlockCaption> &&caption_)
  : location_(std::move(location_))
  , zoom_(zoom_)
  , width_(width_)
  , height_(height_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockMap::ID;

void pageBlockMap::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockMap");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("zoom", zoom_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockCaption::pageBlockCaption()
  : text_()
  , credit_()
{}

pageBlockCaption::pageBlockCaption(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageBlockCaption::ID;

void pageBlockCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCaption");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

pageBlockHorizontalAlignmentLeft::pageBlockHorizontalAlignmentLeft() {
}

const std::int32_t pageBlockHorizontalAlignmentLeft::ID;

void pageBlockHorizontalAlignmentLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHorizontalAlignmentLeft");
    s.store_class_end();
  }
}

pageBlockHorizontalAlignmentCenter::pageBlockHorizontalAlignmentCenter() {
}

const std::int32_t pageBlockHorizontalAlignmentCenter::ID;

void pageBlockHorizontalAlignmentCenter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHorizontalAlignmentCenter");
    s.store_class_end();
  }
}

pageBlockHorizontalAlignmentRight::pageBlockHorizontalAlignmentRight() {
}

const std::int32_t pageBlockHorizontalAlignmentRight::ID;

void pageBlockHorizontalAlignmentRight::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHorizontalAlignmentRight");
    s.store_class_end();
  }
}

pageBlockListItem::pageBlockListItem()
  : label_()
  , page_blocks_()
{}

pageBlockListItem::pageBlockListItem(string const &label_, array<object_ptr<PageBlock>> &&page_blocks_)
  : label_(label_)
  , page_blocks_(std::move(page_blocks_))
{}

const std::int32_t pageBlockListItem::ID;

void pageBlockListItem::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockListItem");
    s.store_field("label", label_);
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockRelatedArticle::pageBlockRelatedArticle()
  : url_()
  , title_()
  , description_()
  , photo_()
  , author_()
  , publish_date_()
{}

pageBlockRelatedArticle::pageBlockRelatedArticle(string const &url_, string const &title_, string const &description_, object_ptr<photo> &&photo_, string const &author_, int32 publish_date_)
  : url_(url_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , author_(author_)
  , publish_date_(publish_date_)
{}

const std::int32_t pageBlockRelatedArticle::ID;

void pageBlockRelatedArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockRelatedArticle");
    s.store_field("url", url_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("author", author_);
    s.store_field("publish_date", publish_date_);
    s.store_class_end();
  }
}

pageBlockTableCell::pageBlockTableCell()
  : text_()
  , is_header_()
  , colspan_()
  , rowspan_()
  , align_()
  , valign_()
{}

pageBlockTableCell::pageBlockTableCell(object_ptr<RichText> &&text_, bool is_header_, int32 colspan_, int32 rowspan_, object_ptr<PageBlockHorizontalAlignment> &&align_, object_ptr<PageBlockVerticalAlignment> &&valign_)
  : text_(std::move(text_))
  , is_header_(is_header_)
  , colspan_(colspan_)
  , rowspan_(rowspan_)
  , align_(std::move(align_))
  , valign_(std::move(valign_))
{}

const std::int32_t pageBlockTableCell::ID;

void pageBlockTableCell::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTableCell");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_header", is_header_);
    s.store_field("colspan", colspan_);
    s.store_field("rowspan", rowspan_);
    s.store_object_field("align", static_cast<const BaseObject *>(align_.get()));
    s.store_object_field("valign", static_cast<const BaseObject *>(valign_.get()));
    s.store_class_end();
  }
}

pageBlockVerticalAlignmentTop::pageBlockVerticalAlignmentTop() {
}

const std::int32_t pageBlockVerticalAlignmentTop::ID;

void pageBlockVerticalAlignmentTop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVerticalAlignmentTop");
    s.store_class_end();
  }
}

pageBlockVerticalAlignmentMiddle::pageBlockVerticalAlignmentMiddle() {
}

const std::int32_t pageBlockVerticalAlignmentMiddle::ID;

void pageBlockVerticalAlignmentMiddle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVerticalAlignmentMiddle");
    s.store_class_end();
  }
}

pageBlockVerticalAlignmentBottom::pageBlockVerticalAlignmentBottom() {
}

const std::int32_t pageBlockVerticalAlignmentBottom::ID;

void pageBlockVerticalAlignmentBottom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVerticalAlignmentBottom");
    s.store_class_end();
  }
}

passportAuthorizationForm::passportAuthorizationForm()
  : id_()
  , required_elements_()
  , privacy_policy_url_()
{}

passportAuthorizationForm::passportAuthorizationForm(int32 id_, array<object_ptr<passportRequiredElement>> &&required_elements_, string const &privacy_policy_url_)
  : id_(id_)
  , required_elements_(std::move(required_elements_))
  , privacy_policy_url_(privacy_policy_url_)
{}

const std::int32_t passportAuthorizationForm::ID;

void passportAuthorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportAuthorizationForm");
    s.store_field("id", id_);
    { s.store_vector_begin("required_elements", required_elements_.size()); for (const auto &_value : required_elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("privacy_policy_url", privacy_policy_url_);
    s.store_class_end();
  }
}

passportElementPersonalDetails::passportElementPersonalDetails()
  : personal_details_()
{}

passportElementPersonalDetails::passportElementPersonalDetails(object_ptr<personalDetails> &&personal_details_)
  : personal_details_(std::move(personal_details_))
{}

const std::int32_t passportElementPersonalDetails::ID;

void passportElementPersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPersonalDetails");
    s.store_object_field("personal_details", static_cast<const BaseObject *>(personal_details_.get()));
    s.store_class_end();
  }
}

passportElementPassport::passportElementPassport()
  : passport_()
{}

passportElementPassport::passportElementPassport(object_ptr<identityDocument> &&passport_)
  : passport_(std::move(passport_))
{}

const std::int32_t passportElementPassport::ID;

void passportElementPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPassport");
    s.store_object_field("passport", static_cast<const BaseObject *>(passport_.get()));
    s.store_class_end();
  }
}

passportElementDriverLicense::passportElementDriverLicense()
  : driver_license_()
{}

passportElementDriverLicense::passportElementDriverLicense(object_ptr<identityDocument> &&driver_license_)
  : driver_license_(std::move(driver_license_))
{}

const std::int32_t passportElementDriverLicense::ID;

void passportElementDriverLicense::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementDriverLicense");
    s.store_object_field("driver_license", static_cast<const BaseObject *>(driver_license_.get()));
    s.store_class_end();
  }
}

passportElementIdentityCard::passportElementIdentityCard()
  : identity_card_()
{}

passportElementIdentityCard::passportElementIdentityCard(object_ptr<identityDocument> &&identity_card_)
  : identity_card_(std::move(identity_card_))
{}

const std::int32_t passportElementIdentityCard::ID;

void passportElementIdentityCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementIdentityCard");
    s.store_object_field("identity_card", static_cast<const BaseObject *>(identity_card_.get()));
    s.store_class_end();
  }
}

passportElementInternalPassport::passportElementInternalPassport()
  : internal_passport_()
{}

passportElementInternalPassport::passportElementInternalPassport(object_ptr<identityDocument> &&internal_passport_)
  : internal_passport_(std::move(internal_passport_))
{}

const std::int32_t passportElementInternalPassport::ID;

void passportElementInternalPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementInternalPassport");
    s.store_object_field("internal_passport", static_cast<const BaseObject *>(internal_passport_.get()));
    s.store_class_end();
  }
}

passportElementAddress::passportElementAddress()
  : address_()
{}

passportElementAddress::passportElementAddress(object_ptr<address> &&address_)
  : address_(std::move(address_))
{}

const std::int32_t passportElementAddress::ID;

void passportElementAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementAddress");
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_class_end();
  }
}

passportElementUtilityBill::passportElementUtilityBill()
  : utility_bill_()
{}

passportElementUtilityBill::passportElementUtilityBill(object_ptr<personalDocument> &&utility_bill_)
  : utility_bill_(std::move(utility_bill_))
{}

const std::int32_t passportElementUtilityBill::ID;

void passportElementUtilityBill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementUtilityBill");
    s.store_object_field("utility_bill", static_cast<const BaseObject *>(utility_bill_.get()));
    s.store_class_end();
  }
}

passportElementBankStatement::passportElementBankStatement()
  : bank_statement_()
{}

passportElementBankStatement::passportElementBankStatement(object_ptr<personalDocument> &&bank_statement_)
  : bank_statement_(std::move(bank_statement_))
{}

const std::int32_t passportElementBankStatement::ID;

void passportElementBankStatement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementBankStatement");
    s.store_object_field("bank_statement", static_cast<const BaseObject *>(bank_statement_.get()));
    s.store_class_end();
  }
}

passportElementRentalAgreement::passportElementRentalAgreement()
  : rental_agreement_()
{}

passportElementRentalAgreement::passportElementRentalAgreement(object_ptr<personalDocument> &&rental_agreement_)
  : rental_agreement_(std::move(rental_agreement_))
{}

const std::int32_t passportElementRentalAgreement::ID;

void passportElementRentalAgreement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementRentalAgreement");
    s.store_object_field("rental_agreement", static_cast<const BaseObject *>(rental_agreement_.get()));
    s.store_class_end();
  }
}

passportElementPassportRegistration::passportElementPassportRegistration()
  : passport_registration_()
{}

passportElementPassportRegistration::passportElementPassportRegistration(object_ptr<personalDocument> &&passport_registration_)
  : passport_registration_(std::move(passport_registration_))
{}

const std::int32_t passportElementPassportRegistration::ID;

void passportElementPassportRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPassportRegistration");
    s.store_object_field("passport_registration", static_cast<const BaseObject *>(passport_registration_.get()));
    s.store_class_end();
  }
}

passportElementTemporaryRegistration::passportElementTemporaryRegistration()
  : temporary_registration_()
{}

passportElementTemporaryRegistration::passportElementTemporaryRegistration(object_ptr<personalDocument> &&temporary_registration_)
  : temporary_registration_(std::move(temporary_registration_))
{}

const std::int32_t passportElementTemporaryRegistration::ID;

void passportElementTemporaryRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTemporaryRegistration");
    s.store_object_field("temporary_registration", static_cast<const BaseObject *>(temporary_registration_.get()));
    s.store_class_end();
  }
}

passportElementPhoneNumber::passportElementPhoneNumber()
  : phone_number_()
{}

passportElementPhoneNumber::passportElementPhoneNumber(string const &phone_number_)
  : phone_number_(phone_number_)
{}

const std::int32_t passportElementPhoneNumber::ID;

void passportElementPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

passportElementEmailAddress::passportElementEmailAddress()
  : email_address_()
{}

passportElementEmailAddress::passportElementEmailAddress(string const &email_address_)
  : email_address_(email_address_)
{}

const std::int32_t passportElementEmailAddress::ID;

void passportElementEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementEmailAddress");
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

passportElementError::passportElementError()
  : type_()
  , message_()
  , source_()
{}

passportElementError::passportElementError(object_ptr<PassportElementType> &&type_, string const &message_, object_ptr<PassportElementErrorSource> &&source_)
  : type_(std::move(type_))
  , message_(message_)
  , source_(std::move(source_))
{}

const std::int32_t passportElementError::ID;

void passportElementError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementError");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("message", message_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

passportElementErrorSourceUnspecified::passportElementErrorSourceUnspecified() {
}

const std::int32_t passportElementErrorSourceUnspecified::ID;

void passportElementErrorSourceUnspecified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceUnspecified");
    s.store_class_end();
  }
}

passportElementErrorSourceDataField::passportElementErrorSourceDataField()
  : field_name_()
{}

passportElementErrorSourceDataField::passportElementErrorSourceDataField(string const &field_name_)
  : field_name_(field_name_)
{}

const std::int32_t passportElementErrorSourceDataField::ID;

void passportElementErrorSourceDataField::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceDataField");
    s.store_field("field_name", field_name_);
    s.store_class_end();
  }
}

passportElementErrorSourceFrontSide::passportElementErrorSourceFrontSide() {
}

const std::int32_t passportElementErrorSourceFrontSide::ID;

void passportElementErrorSourceFrontSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceFrontSide");
    s.store_class_end();
  }
}

passportElementErrorSourceReverseSide::passportElementErrorSourceReverseSide() {
}

const std::int32_t passportElementErrorSourceReverseSide::ID;

void passportElementErrorSourceReverseSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceReverseSide");
    s.store_class_end();
  }
}

passportElementErrorSourceSelfie::passportElementErrorSourceSelfie() {
}

const std::int32_t passportElementErrorSourceSelfie::ID;

void passportElementErrorSourceSelfie::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceSelfie");
    s.store_class_end();
  }
}

passportElementErrorSourceTranslationFile::passportElementErrorSourceTranslationFile()
  : file_index_()
{}

passportElementErrorSourceTranslationFile::passportElementErrorSourceTranslationFile(int32 file_index_)
  : file_index_(file_index_)
{}

const std::int32_t passportElementErrorSourceTranslationFile::ID;

void passportElementErrorSourceTranslationFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceTranslationFile");
    s.store_field("file_index", file_index_);
    s.store_class_end();
  }
}

passportElementErrorSourceTranslationFiles::passportElementErrorSourceTranslationFiles() {
}

const std::int32_t passportElementErrorSourceTranslationFiles::ID;

void passportElementErrorSourceTranslationFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceTranslationFiles");
    s.store_class_end();
  }
}

passportElementErrorSourceFile::passportElementErrorSourceFile()
  : file_index_()
{}

passportElementErrorSourceFile::passportElementErrorSourceFile(int32 file_index_)
  : file_index_(file_index_)
{}

const std::int32_t passportElementErrorSourceFile::ID;

void passportElementErrorSourceFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceFile");
    s.store_field("file_index", file_index_);
    s.store_class_end();
  }
}

passportElementErrorSourceFiles::passportElementErrorSourceFiles() {
}

const std::int32_t passportElementErrorSourceFiles::ID;

void passportElementErrorSourceFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementErrorSourceFiles");
    s.store_class_end();
  }
}

passportElementTypePersonalDetails::passportElementTypePersonalDetails() {
}

const std::int32_t passportElementTypePersonalDetails::ID;

void passportElementTypePersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePersonalDetails");
    s.store_class_end();
  }
}

passportElementTypePassport::passportElementTypePassport() {
}

const std::int32_t passportElementTypePassport::ID;

void passportElementTypePassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePassport");
    s.store_class_end();
  }
}

passportElementTypeDriverLicense::passportElementTypeDriverLicense() {
}

const std::int32_t passportElementTypeDriverLicense::ID;

void passportElementTypeDriverLicense::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeDriverLicense");
    s.store_class_end();
  }
}

passportElementTypeIdentityCard::passportElementTypeIdentityCard() {
}

const std::int32_t passportElementTypeIdentityCard::ID;

void passportElementTypeIdentityCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeIdentityCard");
    s.store_class_end();
  }
}

passportElementTypeInternalPassport::passportElementTypeInternalPassport() {
}

const std::int32_t passportElementTypeInternalPassport::ID;

void passportElementTypeInternalPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeInternalPassport");
    s.store_class_end();
  }
}

passportElementTypeAddress::passportElementTypeAddress() {
}

const std::int32_t passportElementTypeAddress::ID;

void passportElementTypeAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeAddress");
    s.store_class_end();
  }
}

passportElementTypeUtilityBill::passportElementTypeUtilityBill() {
}

const std::int32_t passportElementTypeUtilityBill::ID;

void passportElementTypeUtilityBill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeUtilityBill");
    s.store_class_end();
  }
}

passportElementTypeBankStatement::passportElementTypeBankStatement() {
}

const std::int32_t passportElementTypeBankStatement::ID;

void passportElementTypeBankStatement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeBankStatement");
    s.store_class_end();
  }
}

passportElementTypeRentalAgreement::passportElementTypeRentalAgreement() {
}

const std::int32_t passportElementTypeRentalAgreement::ID;

void passportElementTypeRentalAgreement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeRentalAgreement");
    s.store_class_end();
  }
}

passportElementTypePassportRegistration::passportElementTypePassportRegistration() {
}

const std::int32_t passportElementTypePassportRegistration::ID;

void passportElementTypePassportRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePassportRegistration");
    s.store_class_end();
  }
}

passportElementTypeTemporaryRegistration::passportElementTypeTemporaryRegistration() {
}

const std::int32_t passportElementTypeTemporaryRegistration::ID;

void passportElementTypeTemporaryRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeTemporaryRegistration");
    s.store_class_end();
  }
}

passportElementTypePhoneNumber::passportElementTypePhoneNumber() {
}

const std::int32_t passportElementTypePhoneNumber::ID;

void passportElementTypePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePhoneNumber");
    s.store_class_end();
  }
}

passportElementTypeEmailAddress::passportElementTypeEmailAddress() {
}

const std::int32_t passportElementTypeEmailAddress::ID;

void passportElementTypeEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeEmailAddress");
    s.store_class_end();
  }
}

passportElements::passportElements()
  : elements_()
{}

passportElements::passportElements(array<object_ptr<PassportElement>> &&elements_)
  : elements_(std::move(elements_))
{}

const std::int32_t passportElements::ID;

void passportElements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElements");
    { s.store_vector_begin("elements", elements_.size()); for (const auto &_value : elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

passportElementsWithErrors::passportElementsWithErrors()
  : elements_()
  , errors_()
{}

passportElementsWithErrors::passportElementsWithErrors(array<object_ptr<PassportElement>> &&elements_, array<object_ptr<passportElementError>> &&errors_)
  : elements_(std::move(elements_))
  , errors_(std::move(errors_))
{}

const std::int32_t passportElementsWithErrors::ID;

void passportElementsWithErrors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementsWithErrors");
    { s.store_vector_begin("elements", elements_.size()); for (const auto &_value : elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("errors", errors_.size()); for (const auto &_value : errors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

passportRequiredElement::passportRequiredElement()
  : suitable_elements_()
{}

passportRequiredElement::passportRequiredElement(array<object_ptr<passportSuitableElement>> &&suitable_elements_)
  : suitable_elements_(std::move(suitable_elements_))
{}

const std::int32_t passportRequiredElement::ID;

void passportRequiredElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportRequiredElement");
    { s.store_vector_begin("suitable_elements", suitable_elements_.size()); for (const auto &_value : suitable_elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

passportSuitableElement::passportSuitableElement()
  : type_()
  , is_selfie_required_()
  , is_translation_required_()
  , is_native_name_required_()
{}

passportSuitableElement::passportSuitableElement(object_ptr<PassportElementType> &&type_, bool is_selfie_required_, bool is_translation_required_, bool is_native_name_required_)
  : type_(std::move(type_))
  , is_selfie_required_(is_selfie_required_)
  , is_translation_required_(is_translation_required_)
  , is_native_name_required_(is_native_name_required_)
{}

const std::int32_t passportSuitableElement::ID;

void passportSuitableElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportSuitableElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("is_selfie_required", is_selfie_required_);
    s.store_field("is_translation_required", is_translation_required_);
    s.store_field("is_native_name_required", is_native_name_required_);
    s.store_class_end();
  }
}

passwordState::passwordState()
  : has_password_()
  , password_hint_()
  , has_recovery_email_address_()
  , has_passport_data_()
  , recovery_email_address_code_info_()
  , pending_reset_date_()
{}

passwordState::passwordState(bool has_password_, string const &password_hint_, bool has_recovery_email_address_, bool has_passport_data_, object_ptr<emailAddressAuthenticationCodeInfo> &&recovery_email_address_code_info_, int32 pending_reset_date_)
  : has_password_(has_password_)
  , password_hint_(password_hint_)
  , has_recovery_email_address_(has_recovery_email_address_)
  , has_passport_data_(has_passport_data_)
  , recovery_email_address_code_info_(std::move(recovery_email_address_code_info_))
  , pending_reset_date_(pending_reset_date_)
{}

const std::int32_t passwordState::ID;

void passwordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passwordState");
    s.store_field("has_password", has_password_);
    s.store_field("password_hint", password_hint_);
    s.store_field("has_recovery_email_address", has_recovery_email_address_);
    s.store_field("has_passport_data", has_passport_data_);
    s.store_object_field("recovery_email_address_code_info", static_cast<const BaseObject *>(recovery_email_address_code_info_.get()));
    s.store_field("pending_reset_date", pending_reset_date_);
    s.store_class_end();
  }
}

paymentForm::paymentForm()
  : id_()
  , invoice_()
  , url_()
  , seller_bot_user_id_()
  , payments_provider_user_id_()
  , payments_provider_()
  , saved_order_info_()
  , saved_credentials_()
  , can_save_credentials_()
  , need_password_()
{}

paymentForm::paymentForm(int64 id_, object_ptr<invoice> &&invoice_, string const &url_, int53 seller_bot_user_id_, int53 payments_provider_user_id_, object_ptr<paymentsProviderStripe> &&payments_provider_, object_ptr<orderInfo> &&saved_order_info_, object_ptr<savedCredentials> &&saved_credentials_, bool can_save_credentials_, bool need_password_)
  : id_(id_)
  , invoice_(std::move(invoice_))
  , url_(url_)
  , seller_bot_user_id_(seller_bot_user_id_)
  , payments_provider_user_id_(payments_provider_user_id_)
  , payments_provider_(std::move(payments_provider_))
  , saved_order_info_(std::move(saved_order_info_))
  , saved_credentials_(std::move(saved_credentials_))
  , can_save_credentials_(can_save_credentials_)
  , need_password_(need_password_)
{}

const std::int32_t paymentForm::ID;

void paymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentForm");
    s.store_field("id", id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_field("url", url_);
    s.store_field("seller_bot_user_id", seller_bot_user_id_);
    s.store_field("payments_provider_user_id", payments_provider_user_id_);
    s.store_object_field("payments_provider", static_cast<const BaseObject *>(payments_provider_.get()));
    s.store_object_field("saved_order_info", static_cast<const BaseObject *>(saved_order_info_.get()));
    s.store_object_field("saved_credentials", static_cast<const BaseObject *>(saved_credentials_.get()));
    s.store_field("can_save_credentials", can_save_credentials_);
    s.store_field("need_password", need_password_);
    s.store_class_end();
  }
}

paymentReceipt::paymentReceipt()
  : title_()
  , description_()
  , photo_()
  , date_()
  , seller_bot_user_id_()
  , payments_provider_user_id_()
  , invoice_()
  , order_info_()
  , shipping_option_()
  , credentials_title_()
  , tip_amount_()
{}

paymentReceipt::paymentReceipt(string const &title_, string const &description_, object_ptr<photo> &&photo_, int32 date_, int53 seller_bot_user_id_, int53 payments_provider_user_id_, object_ptr<invoice> &&invoice_, object_ptr<orderInfo> &&order_info_, object_ptr<shippingOption> &&shipping_option_, string const &credentials_title_, int53 tip_amount_)
  : title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , date_(date_)
  , seller_bot_user_id_(seller_bot_user_id_)
  , payments_provider_user_id_(payments_provider_user_id_)
  , invoice_(std::move(invoice_))
  , order_info_(std::move(order_info_))
  , shipping_option_(std::move(shipping_option_))
  , credentials_title_(credentials_title_)
  , tip_amount_(tip_amount_)
{}

const std::int32_t paymentReceipt::ID;

void paymentReceipt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentReceipt");
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("date", date_);
    s.store_field("seller_bot_user_id", seller_bot_user_id_);
    s.store_field("payments_provider_user_id", payments_provider_user_id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_object_field("shipping_option", static_cast<const BaseObject *>(shipping_option_.get()));
    s.store_field("credentials_title", credentials_title_);
    s.store_field("tip_amount", tip_amount_);
    s.store_class_end();
  }
}

paymentResult::paymentResult()
  : success_()
  , verification_url_()
{}

paymentResult::paymentResult(bool success_, string const &verification_url_)
  : success_(success_)
  , verification_url_(verification_url_)
{}

const std::int32_t paymentResult::ID;

void paymentResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentResult");
    s.store_field("success", success_);
    s.store_field("verification_url", verification_url_);
    s.store_class_end();
  }
}

paymentsProviderStripe::paymentsProviderStripe()
  : publishable_key_()
  , need_country_()
  , need_postal_code_()
  , need_cardholder_name_()
{}

paymentsProviderStripe::paymentsProviderStripe(string const &publishable_key_, bool need_country_, bool need_postal_code_, bool need_cardholder_name_)
  : publishable_key_(publishable_key_)
  , need_country_(need_country_)
  , need_postal_code_(need_postal_code_)
  , need_cardholder_name_(need_cardholder_name_)
{}

const std::int32_t paymentsProviderStripe::ID;

void paymentsProviderStripe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentsProviderStripe");
    s.store_field("publishable_key", publishable_key_);
    s.store_field("need_country", need_country_);
    s.store_field("need_postal_code", need_postal_code_);
    s.store_field("need_cardholder_name", need_cardholder_name_);
    s.store_class_end();
  }
}

personalDetails::personalDetails()
  : first_name_()
  , middle_name_()
  , last_name_()
  , native_first_name_()
  , native_middle_name_()
  , native_last_name_()
  , birthdate_()
  , gender_()
  , country_code_()
  , residence_country_code_()
{}

personalDetails::personalDetails(string const &first_name_, string const &middle_name_, string const &last_name_, string const &native_first_name_, string const &native_middle_name_, string const &native_last_name_, object_ptr<date> &&birthdate_, string const &gender_, string const &country_code_, string const &residence_country_code_)
  : first_name_(first_name_)
  , middle_name_(middle_name_)
  , last_name_(last_name_)
  , native_first_name_(native_first_name_)
  , native_middle_name_(native_middle_name_)
  , native_last_name_(native_last_name_)
  , birthdate_(std::move(birthdate_))
  , gender_(gender_)
  , country_code_(country_code_)
  , residence_country_code_(residence_country_code_)
{}

const std::int32_t personalDetails::ID;

void personalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "personalDetails");
    s.store_field("first_name", first_name_);
    s.store_field("middle_name", middle_name_);
    s.store_field("last_name", last_name_);
    s.store_field("native_first_name", native_first_name_);
    s.store_field("native_middle_name", native_middle_name_);
    s.store_field("native_last_name", native_last_name_);
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_field("gender", gender_);
    s.store_field("country_code", country_code_);
    s.store_field("residence_country_code", residence_country_code_);
    s.store_class_end();
  }
}

personalDocument::personalDocument()
  : files_()
  , translation_()
{}

personalDocument::personalDocument(array<object_ptr<datedFile>> &&files_, array<object_ptr<datedFile>> &&translation_)
  : files_(std::move(files_))
  , translation_(std::move(translation_))
{}

const std::int32_t personalDocument::ID;

void personalDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "personalDocument");
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

phoneNumberAuthenticationSettings::phoneNumberAuthenticationSettings()
  : allow_flash_call_()
  , allow_missed_call_()
  , is_current_phone_number_()
  , allow_sms_retriever_api_()
  , authentication_tokens_()
{}

phoneNumberAuthenticationSettings::phoneNumberAuthenticationSettings(bool allow_flash_call_, bool allow_missed_call_, bool is_current_phone_number_, bool allow_sms_retriever_api_, array<string> &&authentication_tokens_)
  : allow_flash_call_(allow_flash_call_)
  , allow_missed_call_(allow_missed_call_)
  , is_current_phone_number_(is_current_phone_number_)
  , allow_sms_retriever_api_(allow_sms_retriever_api_)
  , authentication_tokens_(std::move(authentication_tokens_))
{}

const std::int32_t phoneNumberAuthenticationSettings::ID;

void phoneNumberAuthenticationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberAuthenticationSettings");
    s.store_field("allow_flash_call", allow_flash_call_);
    s.store_field("allow_missed_call", allow_missed_call_);
    s.store_field("is_current_phone_number", is_current_phone_number_);
    s.store_field("allow_sms_retriever_api", allow_sms_retriever_api_);
    { s.store_vector_begin("authentication_tokens", authentication_tokens_.size()); for (const auto &_value : authentication_tokens_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

phoneNumberInfo::phoneNumberInfo()
  : country_()
  , country_calling_code_()
  , formatted_phone_number_()
{}

phoneNumberInfo::phoneNumberInfo(object_ptr<countryInfo> &&country_, string const &country_calling_code_, string const &formatted_phone_number_)
  : country_(std::move(country_))
  , country_calling_code_(country_calling_code_)
  , formatted_phone_number_(formatted_phone_number_)
{}

const std::int32_t phoneNumberInfo::ID;

void phoneNumberInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberInfo");
    s.store_object_field("country", static_cast<const BaseObject *>(country_.get()));
    s.store_field("country_calling_code", country_calling_code_);
    s.store_field("formatted_phone_number", formatted_phone_number_);
    s.store_class_end();
  }
}

photo::photo()
  : has_stickers_()
  , minithumbnail_()
  , sizes_()
{}

photo::photo(bool has_stickers_, object_ptr<minithumbnail> &&minithumbnail_, array<object_ptr<photoSize>> &&sizes_)
  : has_stickers_(has_stickers_)
  , minithumbnail_(std::move(minithumbnail_))
  , sizes_(std::move(sizes_))
{}

const std::int32_t photo::ID;

void photo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photo");
    s.store_field("has_stickers", has_stickers_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    { s.store_vector_begin("sizes", sizes_.size()); for (const auto &_value : sizes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

photoSize::photoSize()
  : type_()
  , photo_()
  , width_()
  , height_()
  , progressive_sizes_()
{}

photoSize::photoSize(string const &type_, object_ptr<file> &&photo_, int32 width_, int32 height_, array<int32> &&progressive_sizes_)
  : type_(type_)
  , photo_(std::move(photo_))
  , width_(width_)
  , height_(height_)
  , progressive_sizes_(std::move(progressive_sizes_))
{}

const std::int32_t photoSize::ID;

void photoSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoSize");
    s.store_field("type", type_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    { s.store_vector_begin("progressive_sizes", progressive_sizes_.size()); for (const auto &_value : progressive_sizes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

point::point()
  : x_()
  , y_()
{}

point::point(double x_, double y_)
  : x_(x_)
  , y_(y_)
{}

const std::int32_t point::ID;

void point::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "point");
    s.store_field("x", x_);
    s.store_field("y", y_);
    s.store_class_end();
  }
}

poll::poll()
  : id_()
  , question_()
  , options_()
  , total_voter_count_()
  , recent_voter_user_ids_()
  , is_anonymous_()
  , type_()
  , open_period_()
  , close_date_()
  , is_closed_()
{}

poll::poll(int64 id_, string const &question_, array<object_ptr<pollOption>> &&options_, int32 total_voter_count_, array<int53> &&recent_voter_user_ids_, bool is_anonymous_, object_ptr<PollType> &&type_, int32 open_period_, int32 close_date_, bool is_closed_)
  : id_(id_)
  , question_(question_)
  , options_(std::move(options_))
  , total_voter_count_(total_voter_count_)
  , recent_voter_user_ids_(std::move(recent_voter_user_ids_))
  , is_anonymous_(is_anonymous_)
  , type_(std::move(type_))
  , open_period_(open_period_)
  , close_date_(close_date_)
  , is_closed_(is_closed_)
{}

const std::int32_t poll::ID;

void poll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "poll");
    s.store_field("id", id_);
    s.store_field("question", question_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("total_voter_count", total_voter_count_);
    { s.store_vector_begin("recent_voter_user_ids", recent_voter_user_ids_.size()); for (const auto &_value : recent_voter_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("is_anonymous", is_anonymous_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("open_period", open_period_);
    s.store_field("close_date", close_date_);
    s.store_field("is_closed", is_closed_);
    s.store_class_end();
  }
}

pollOption::pollOption()
  : text_()
  , voter_count_()
  , vote_percentage_()
  , is_chosen_()
  , is_being_chosen_()
{}

pollOption::pollOption(string const &text_, int32 voter_count_, int32 vote_percentage_, bool is_chosen_, bool is_being_chosen_)
  : text_(text_)
  , voter_count_(voter_count_)
  , vote_percentage_(vote_percentage_)
  , is_chosen_(is_chosen_)
  , is_being_chosen_(is_being_chosen_)
{}

const std::int32_t pollOption::ID;

void pollOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollOption");
    s.store_field("text", text_);
    s.store_field("voter_count", voter_count_);
    s.store_field("vote_percentage", vote_percentage_);
    s.store_field("is_chosen", is_chosen_);
    s.store_field("is_being_chosen", is_being_chosen_);
    s.store_class_end();
  }
}

pollTypeRegular::pollTypeRegular()
  : allow_multiple_answers_()
{}

pollTypeRegular::pollTypeRegular(bool allow_multiple_answers_)
  : allow_multiple_answers_(allow_multiple_answers_)
{}

const std::int32_t pollTypeRegular::ID;

void pollTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollTypeRegular");
    s.store_field("allow_multiple_answers", allow_multiple_answers_);
    s.store_class_end();
  }
}

pollTypeQuiz::pollTypeQuiz()
  : correct_option_id_()
  , explanation_()
{}

pollTypeQuiz::pollTypeQuiz(int32 correct_option_id_, object_ptr<formattedText> &&explanation_)
  : correct_option_id_(correct_option_id_)
  , explanation_(std::move(explanation_))
{}

const std::int32_t pollTypeQuiz::ID;

void pollTypeQuiz::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollTypeQuiz");
    s.store_field("correct_option_id", correct_option_id_);
    s.store_object_field("explanation", static_cast<const BaseObject *>(explanation_.get()));
    s.store_class_end();
  }
}

profilePhoto::profilePhoto()
  : id_()
  , small_()
  , big_()
  , minithumbnail_()
  , has_animation_()
{}

profilePhoto::profilePhoto(int64 id_, object_ptr<file> &&small_, object_ptr<file> &&big_, object_ptr<minithumbnail> &&minithumbnail_, bool has_animation_)
  : id_(id_)
  , small_(std::move(small_))
  , big_(std::move(big_))
  , minithumbnail_(std::move(minithumbnail_))
  , has_animation_(has_animation_)
{}

const std::int32_t profilePhoto::ID;

void profilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profilePhoto");
    s.store_field("id", id_);
    s.store_object_field("small", static_cast<const BaseObject *>(small_.get()));
    s.store_object_field("big", static_cast<const BaseObject *>(big_.get()));
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_field("has_animation", has_animation_);
    s.store_class_end();
  }
}

proxies::proxies()
  : proxies_()
{}

proxies::proxies(array<object_ptr<proxy>> &&proxies_)
  : proxies_(std::move(proxies_))
{}

const std::int32_t proxies::ID;

void proxies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxies");
    { s.store_vector_begin("proxies", proxies_.size()); for (const auto &_value : proxies_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

proxy::proxy()
  : id_()
  , server_()
  , port_()
  , last_used_date_()
  , is_enabled_()
  , type_()
{}

proxy::proxy(int32 id_, string const &server_, int32 port_, int32 last_used_date_, bool is_enabled_, object_ptr<ProxyType> &&type_)
  : id_(id_)
  , server_(server_)
  , port_(port_)
  , last_used_date_(last_used_date_)
  , is_enabled_(is_enabled_)
  , type_(std::move(type_))
{}

const std::int32_t proxy::ID;

void proxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxy");
    s.store_field("id", id_);
    s.store_field("server", server_);
    s.store_field("port", port_);
    s.store_field("last_used_date", last_used_date_);
    s.store_field("is_enabled", is_enabled_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

proxyTypeSocks5::proxyTypeSocks5()
  : username_()
  , password_()
{}

proxyTypeSocks5::proxyTypeSocks5(string const &username_, string const &password_)
  : username_(username_)
  , password_(password_)
{}

const std::int32_t proxyTypeSocks5::ID;

void proxyTypeSocks5::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxyTypeSocks5");
    s.store_field("username", username_);
    s.store_field("password", password_);
    s.store_class_end();
  }
}

proxyTypeHttp::proxyTypeHttp()
  : username_()
  , password_()
  , http_only_()
{}

proxyTypeHttp::proxyTypeHttp(string const &username_, string const &password_, bool http_only_)
  : username_(username_)
  , password_(password_)
  , http_only_(http_only_)
{}

const std::int32_t proxyTypeHttp::ID;

void proxyTypeHttp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxyTypeHttp");
    s.store_field("username", username_);
    s.store_field("password", password_);
    s.store_field("http_only", http_only_);
    s.store_class_end();
  }
}

proxyTypeMtproto::proxyTypeMtproto()
  : secret_()
{}

proxyTypeMtproto::proxyTypeMtproto(string const &secret_)
  : secret_(secret_)
{}

const std::int32_t proxyTypeMtproto::ID;

void proxyTypeMtproto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxyTypeMtproto");
    s.store_field("secret", secret_);
    s.store_class_end();
  }
}

publicChatTypeHasUsername::publicChatTypeHasUsername() {
}

const std::int32_t publicChatTypeHasUsername::ID;

void publicChatTypeHasUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicChatTypeHasUsername");
    s.store_class_end();
  }
}

publicChatTypeIsLocationBased::publicChatTypeIsLocationBased() {
}

const std::int32_t publicChatTypeIsLocationBased::ID;

void publicChatTypeIsLocationBased::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicChatTypeIsLocationBased");
    s.store_class_end();
  }
}

pushMessageContentHidden::pushMessageContentHidden()
  : is_pinned_()
{}

pushMessageContentHidden::pushMessageContentHidden(bool is_pinned_)
  : is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentHidden::ID;

void pushMessageContentHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentHidden");
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentAnimation::pushMessageContentAnimation()
  : animation_()
  , caption_()
  , is_pinned_()
{}

pushMessageContentAnimation::pushMessageContentAnimation(object_ptr<animation> &&animation_, string const &caption_, bool is_pinned_)
  : animation_(std::move(animation_))
  , caption_(caption_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentAnimation::ID;

void pushMessageContentAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_field("caption", caption_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentAudio::pushMessageContentAudio()
  : audio_()
  , is_pinned_()
{}

pushMessageContentAudio::pushMessageContentAudio(object_ptr<audio> &&audio_, bool is_pinned_)
  : audio_(std::move(audio_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentAudio::ID;

void pushMessageContentAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentContact::pushMessageContentContact()
  : name_()
  , is_pinned_()
{}

pushMessageContentContact::pushMessageContentContact(string const &name_, bool is_pinned_)
  : name_(name_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentContact::ID;

void pushMessageContentContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentContact");
    s.store_field("name", name_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentContactRegistered::pushMessageContentContactRegistered() {
}

const std::int32_t pushMessageContentContactRegistered::ID;

void pushMessageContentContactRegistered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentContactRegistered");
    s.store_class_end();
  }
}

pushMessageContentDocument::pushMessageContentDocument()
  : document_()
  , is_pinned_()
{}

pushMessageContentDocument::pushMessageContentDocument(object_ptr<document> &&document_, bool is_pinned_)
  : document_(std::move(document_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentDocument::ID;

void pushMessageContentDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentGame::pushMessageContentGame()
  : title_()
  , is_pinned_()
{}

pushMessageContentGame::pushMessageContentGame(string const &title_, bool is_pinned_)
  : title_(title_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentGame::ID;

void pushMessageContentGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentGame");
    s.store_field("title", title_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentGameScore::pushMessageContentGameScore()
  : title_()
  , score_()
  , is_pinned_()
{}

pushMessageContentGameScore::pushMessageContentGameScore(string const &title_, int32 score_, bool is_pinned_)
  : title_(title_)
  , score_(score_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentGameScore::ID;

void pushMessageContentGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentGameScore");
    s.store_field("title", title_);
    s.store_field("score", score_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentInvoice::pushMessageContentInvoice()
  : price_()
  , is_pinned_()
{}

pushMessageContentInvoice::pushMessageContentInvoice(string const &price_, bool is_pinned_)
  : price_(price_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentInvoice::ID;

void pushMessageContentInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentInvoice");
    s.store_field("price", price_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentLocation::pushMessageContentLocation()
  : is_live_()
  , is_pinned_()
{}

pushMessageContentLocation::pushMessageContentLocation(bool is_live_, bool is_pinned_)
  : is_live_(is_live_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentLocation::ID;

void pushMessageContentLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentLocation");
    s.store_field("is_live", is_live_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentPhoto::pushMessageContentPhoto()
  : photo_()
  , caption_()
  , is_secret_()
  , is_pinned_()
{}

pushMessageContentPhoto::pushMessageContentPhoto(object_ptr<photo> &&photo_, string const &caption_, bool is_secret_, bool is_pinned_)
  : photo_(std::move(photo_))
  , caption_(caption_)
  , is_secret_(is_secret_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentPhoto::ID;

void pushMessageContentPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("caption", caption_);
    s.store_field("is_secret", is_secret_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentPoll::pushMessageContentPoll()
  : question_()
  , is_regular_()
  , is_pinned_()
{}

pushMessageContentPoll::pushMessageContentPoll(string const &question_, bool is_regular_, bool is_pinned_)
  : question_(question_)
  , is_regular_(is_regular_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentPoll::ID;

void pushMessageContentPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPoll");
    s.store_field("question", question_);
    s.store_field("is_regular", is_regular_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentScreenshotTaken::pushMessageContentScreenshotTaken() {
}

const std::int32_t pushMessageContentScreenshotTaken::ID;

void pushMessageContentScreenshotTaken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentScreenshotTaken");
    s.store_class_end();
  }
}

pushMessageContentSticker::pushMessageContentSticker()
  : sticker_()
  , emoji_()
  , is_pinned_()
{}

pushMessageContentSticker::pushMessageContentSticker(object_ptr<sticker> &&sticker_, string const &emoji_, bool is_pinned_)
  : sticker_(std::move(sticker_))
  , emoji_(emoji_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentSticker::ID;

void pushMessageContentSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("emoji", emoji_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentText::pushMessageContentText()
  : text_()
  , is_pinned_()
{}

pushMessageContentText::pushMessageContentText(string const &text_, bool is_pinned_)
  : text_(text_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentText::ID;

void pushMessageContentText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentText");
    s.store_field("text", text_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentVideo::pushMessageContentVideo()
  : video_()
  , caption_()
  , is_secret_()
  , is_pinned_()
{}

pushMessageContentVideo::pushMessageContentVideo(object_ptr<video> &&video_, string const &caption_, bool is_secret_, bool is_pinned_)
  : video_(std::move(video_))
  , caption_(caption_)
  , is_secret_(is_secret_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentVideo::ID;

void pushMessageContentVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_field("caption", caption_);
    s.store_field("is_secret", is_secret_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentVideoNote::pushMessageContentVideoNote()
  : video_note_()
  , is_pinned_()
{}

pushMessageContentVideoNote::pushMessageContentVideoNote(object_ptr<videoNote> &&video_note_, bool is_pinned_)
  : video_note_(std::move(video_note_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentVideoNote::ID;

void pushMessageContentVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentVoiceNote::pushMessageContentVoiceNote()
  : voice_note_()
  , is_pinned_()
{}

pushMessageContentVoiceNote::pushMessageContentVoiceNote(object_ptr<voiceNote> &&voice_note_, bool is_pinned_)
  : voice_note_(std::move(voice_note_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentVoiceNote::ID;

void pushMessageContentVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentBasicGroupChatCreate::pushMessageContentBasicGroupChatCreate() {
}

const std::int32_t pushMessageContentBasicGroupChatCreate::ID;

void pushMessageContentBasicGroupChatCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentBasicGroupChatCreate");
    s.store_class_end();
  }
}

pushMessageContentChatAddMembers::pushMessageContentChatAddMembers()
  : member_name_()
  , is_current_user_()
  , is_returned_()
{}

pushMessageContentChatAddMembers::pushMessageContentChatAddMembers(string const &member_name_, bool is_current_user_, bool is_returned_)
  : member_name_(member_name_)
  , is_current_user_(is_current_user_)
  , is_returned_(is_returned_)
{}

const std::int32_t pushMessageContentChatAddMembers::ID;

void pushMessageContentChatAddMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatAddMembers");
    s.store_field("member_name", member_name_);
    s.store_field("is_current_user", is_current_user_);
    s.store_field("is_returned", is_returned_);
    s.store_class_end();
  }
}

pushMessageContentChatChangePhoto::pushMessageContentChatChangePhoto() {
}

const std::int32_t pushMessageContentChatChangePhoto::ID;

void pushMessageContentChatChangePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatChangePhoto");
    s.store_class_end();
  }
}

pushMessageContentChatChangeTitle::pushMessageContentChatChangeTitle()
  : title_()
{}

pushMessageContentChatChangeTitle::pushMessageContentChatChangeTitle(string const &title_)
  : title_(title_)
{}

const std::int32_t pushMessageContentChatChangeTitle::ID;

void pushMessageContentChatChangeTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatChangeTitle");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

pushMessageContentChatSetTheme::pushMessageContentChatSetTheme()
  : theme_name_()
{}

pushMessageContentChatSetTheme::pushMessageContentChatSetTheme(string const &theme_name_)
  : theme_name_(theme_name_)
{}

const std::int32_t pushMessageContentChatSetTheme::ID;

void pushMessageContentChatSetTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatSetTheme");
    s.store_field("theme_name", theme_name_);
    s.store_class_end();
  }
}

pushMessageContentChatDeleteMember::pushMessageContentChatDeleteMember()
  : member_name_()
  , is_current_user_()
  , is_left_()
{}

pushMessageContentChatDeleteMember::pushMessageContentChatDeleteMember(string const &member_name_, bool is_current_user_, bool is_left_)
  : member_name_(member_name_)
  , is_current_user_(is_current_user_)
  , is_left_(is_left_)
{}

const std::int32_t pushMessageContentChatDeleteMember::ID;

void pushMessageContentChatDeleteMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatDeleteMember");
    s.store_field("member_name", member_name_);
    s.store_field("is_current_user", is_current_user_);
    s.store_field("is_left", is_left_);
    s.store_class_end();
  }
}

pushMessageContentChatJoinByLink::pushMessageContentChatJoinByLink() {
}

const std::int32_t pushMessageContentChatJoinByLink::ID;

void pushMessageContentChatJoinByLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatJoinByLink");
    s.store_class_end();
  }
}

pushMessageContentChatJoinByRequest::pushMessageContentChatJoinByRequest() {
}

const std::int32_t pushMessageContentChatJoinByRequest::ID;

void pushMessageContentChatJoinByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatJoinByRequest");
    s.store_class_end();
  }
}

pushMessageContentMessageForwards::pushMessageContentMessageForwards()
  : total_count_()
{}

pushMessageContentMessageForwards::pushMessageContentMessageForwards(int32 total_count_)
  : total_count_(total_count_)
{}

const std::int32_t pushMessageContentMessageForwards::ID;

void pushMessageContentMessageForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentMessageForwards");
    s.store_field("total_count", total_count_);
    s.store_class_end();
  }
}

pushMessageContentMediaAlbum::pushMessageContentMediaAlbum()
  : total_count_()
  , has_photos_()
  , has_videos_()
  , has_audios_()
  , has_documents_()
{}

pushMessageContentMediaAlbum::pushMessageContentMediaAlbum(int32 total_count_, bool has_photos_, bool has_videos_, bool has_audios_, bool has_documents_)
  : total_count_(total_count_)
  , has_photos_(has_photos_)
  , has_videos_(has_videos_)
  , has_audios_(has_audios_)
  , has_documents_(has_documents_)
{}

const std::int32_t pushMessageContentMediaAlbum::ID;

void pushMessageContentMediaAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentMediaAlbum");
    s.store_field("total_count", total_count_);
    s.store_field("has_photos", has_photos_);
    s.store_field("has_videos", has_videos_);
    s.store_field("has_audios", has_audios_);
    s.store_field("has_documents", has_documents_);
    s.store_class_end();
  }
}

pushReceiverId::pushReceiverId()
  : id_()
{}

pushReceiverId::pushReceiverId(int64 id_)
  : id_(id_)
{}

const std::int32_t pushReceiverId::ID;

void pushReceiverId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushReceiverId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

reaction::reaction()
  : reaction_()
  , title_()
  , is_active_()
  , static_icon_()
  , appear_animation_()
  , select_animation_()
  , activate_animation_()
  , effect_animation_()
  , around_animation_()
  , center_animation_()
{}

reaction::reaction(string const &reaction_, string const &title_, bool is_active_, object_ptr<sticker> &&static_icon_, object_ptr<sticker> &&appear_animation_, object_ptr<sticker> &&select_animation_, object_ptr<sticker> &&activate_animation_, object_ptr<sticker> &&effect_animation_, object_ptr<sticker> &&around_animation_, object_ptr<sticker> &&center_animation_)
  : reaction_(reaction_)
  , title_(title_)
  , is_active_(is_active_)
  , static_icon_(std::move(static_icon_))
  , appear_animation_(std::move(appear_animation_))
  , select_animation_(std::move(select_animation_))
  , activate_animation_(std::move(activate_animation_))
  , effect_animation_(std::move(effect_animation_))
  , around_animation_(std::move(around_animation_))
  , center_animation_(std::move(center_animation_))
{}

const std::int32_t reaction::ID;

void reaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reaction");
    s.store_field("reaction", reaction_);
    s.store_field("title", title_);
    s.store_field("is_active", is_active_);
    s.store_object_field("static_icon", static_cast<const BaseObject *>(static_icon_.get()));
    s.store_object_field("appear_animation", static_cast<const BaseObject *>(appear_animation_.get()));
    s.store_object_field("select_animation", static_cast<const BaseObject *>(select_animation_.get()));
    s.store_object_field("activate_animation", static_cast<const BaseObject *>(activate_animation_.get()));
    s.store_object_field("effect_animation", static_cast<const BaseObject *>(effect_animation_.get()));
    s.store_object_field("around_animation", static_cast<const BaseObject *>(around_animation_.get()));
    s.store_object_field("center_animation", static_cast<const BaseObject *>(center_animation_.get()));
    s.store_class_end();
  }
}

recommendedChatFilter::recommendedChatFilter()
  : filter_()
  , description_()
{}

recommendedChatFilter::recommendedChatFilter(object_ptr<chatFilter> &&filter_, string const &description_)
  : filter_(std::move(filter_))
  , description_(description_)
{}

const std::int32_t recommendedChatFilter::ID;

void recommendedChatFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recommendedChatFilter");
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("description", description_);
    s.store_class_end();
  }
}

recommendedChatFilters::recommendedChatFilters()
  : chat_filters_()
{}

recommendedChatFilters::recommendedChatFilters(array<object_ptr<recommendedChatFilter>> &&chat_filters_)
  : chat_filters_(std::move(chat_filters_))
{}

const std::int32_t recommendedChatFilters::ID;

void recommendedChatFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recommendedChatFilters");
    { s.store_vector_begin("chat_filters", chat_filters_.size()); for (const auto &_value : chat_filters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

recoveryEmailAddress::recoveryEmailAddress()
  : recovery_email_address_()
{}

recoveryEmailAddress::recoveryEmailAddress(string const &recovery_email_address_)
  : recovery_email_address_(recovery_email_address_)
{}

const std::int32_t recoveryEmailAddress::ID;

void recoveryEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recoveryEmailAddress");
    s.store_field("recovery_email_address", recovery_email_address_);
    s.store_class_end();
  }
}

remoteFile::remoteFile()
  : id_()
  , unique_id_()
  , is_uploading_active_()
  , is_uploading_completed_()
  , uploaded_size_()
{}

remoteFile::remoteFile(string const &id_, string const &unique_id_, bool is_uploading_active_, bool is_uploading_completed_, int32 uploaded_size_)
  : id_(id_)
  , unique_id_(unique_id_)
  , is_uploading_active_(is_uploading_active_)
  , is_uploading_completed_(is_uploading_completed_)
  , uploaded_size_(uploaded_size_)
{}

const std::int32_t remoteFile::ID;

void remoteFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "remoteFile");
    s.store_field("id", id_);
    s.store_field("unique_id", unique_id_);
    s.store_field("is_uploading_active", is_uploading_active_);
    s.store_field("is_uploading_completed", is_uploading_completed_);
    s.store_field("uploaded_size", uploaded_size_);
    s.store_class_end();
  }
}

replyMarkupRemoveKeyboard::replyMarkupRemoveKeyboard()
  : is_personal_()
{}

replyMarkupRemoveKeyboard::replyMarkupRemoveKeyboard(bool is_personal_)
  : is_personal_(is_personal_)
{}

const std::int32_t replyMarkupRemoveKeyboard::ID;

void replyMarkupRemoveKeyboard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupRemoveKeyboard");
    s.store_field("is_personal", is_personal_);
    s.store_class_end();
  }
}

replyMarkupForceReply::replyMarkupForceReply()
  : is_personal_()
  , input_field_placeholder_()
{}

replyMarkupForceReply::replyMarkupForceReply(bool is_personal_, string const &input_field_placeholder_)
  : is_personal_(is_personal_)
  , input_field_placeholder_(input_field_placeholder_)
{}

const std::int32_t replyMarkupForceReply::ID;

void replyMarkupForceReply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupForceReply");
    s.store_field("is_personal", is_personal_);
    s.store_field("input_field_placeholder", input_field_placeholder_);
    s.store_class_end();
  }
}

replyMarkupShowKeyboard::replyMarkupShowKeyboard()
  : rows_()
  , resize_keyboard_()
  , one_time_()
  , is_personal_()
  , input_field_placeholder_()
{}

replyMarkupShowKeyboard::replyMarkupShowKeyboard(array<array<object_ptr<keyboardButton>>> &&rows_, bool resize_keyboard_, bool one_time_, bool is_personal_, string const &input_field_placeholder_)
  : rows_(std::move(rows_))
  , resize_keyboard_(resize_keyboard_)
  , one_time_(one_time_)
  , is_personal_(is_personal_)
  , input_field_placeholder_(input_field_placeholder_)
{}

const std::int32_t replyMarkupShowKeyboard::ID;

void replyMarkupShowKeyboard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupShowKeyboard");
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { { s.store_vector_begin("", _value.size()); for (const auto &_value2 : _value) { s.store_object_field("", static_cast<const BaseObject *>(_value2.get())); } s.store_class_end(); } } s.store_class_end(); }
    s.store_field("resize_keyboard", resize_keyboard_);
    s.store_field("one_time", one_time_);
    s.store_field("is_personal", is_personal_);
    s.store_field("input_field_placeholder", input_field_placeholder_);
    s.store_class_end();
  }
}

replyMarkupInlineKeyboard::replyMarkupInlineKeyboard()
  : rows_()
{}

replyMarkupInlineKeyboard::replyMarkupInlineKeyboard(array<array<object_ptr<inlineKeyboardButton>>> &&rows_)
  : rows_(std::move(rows_))
{}

const std::int32_t replyMarkupInlineKeyboard::ID;

void replyMarkupInlineKeyboard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyMarkupInlineKeyboard");
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { { s.store_vector_begin("", _value.size()); for (const auto &_value2 : _value) { s.store_object_field("", static_cast<const BaseObject *>(_value2.get())); } s.store_class_end(); } } s.store_class_end(); }
    s.store_class_end();
  }
}

resetPasswordResultOk::resetPasswordResultOk() {
}

const std::int32_t resetPasswordResultOk::ID;

void resetPasswordResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPasswordResultOk");
    s.store_class_end();
  }
}

resetPasswordResultPending::resetPasswordResultPending()
  : pending_reset_date_()
{}

resetPasswordResultPending::resetPasswordResultPending(int32 pending_reset_date_)
  : pending_reset_date_(pending_reset_date_)
{}

const std::int32_t resetPasswordResultPending::ID;

void resetPasswordResultPending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPasswordResultPending");
    s.store_field("pending_reset_date", pending_reset_date_);
    s.store_class_end();
  }
}

resetPasswordResultDeclined::resetPasswordResultDeclined()
  : retry_date_()
{}

resetPasswordResultDeclined::resetPasswordResultDeclined(int32 retry_date_)
  : retry_date_(retry_date_)
{}

const std::int32_t resetPasswordResultDeclined::ID;

void resetPasswordResultDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPasswordResultDeclined");
    s.store_field("retry_date", retry_date_);
    s.store_class_end();
  }
}

richTextPlain::richTextPlain()
  : text_()
{}

richTextPlain::richTextPlain(string const &text_)
  : text_(text_)
{}

const std::int32_t richTextPlain::ID;

void richTextPlain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextPlain");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

richTextBold::richTextBold()
  : text_()
{}

richTextBold::richTextBold(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextBold::ID;

void richTextBold::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextBold");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextItalic::richTextItalic()
  : text_()
{}

richTextItalic::richTextItalic(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextItalic::ID;

void richTextItalic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextItalic");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextUnderline::richTextUnderline()
  : text_()
{}

richTextUnderline::richTextUnderline(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextUnderline::ID;

void richTextUnderline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextUnderline");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextStrikethrough::richTextStrikethrough()
  : text_()
{}

richTextStrikethrough::richTextStrikethrough(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextStrikethrough::ID;

void richTextStrikethrough::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextStrikethrough");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextFixed::richTextFixed()
  : text_()
{}

richTextFixed::richTextFixed(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextFixed::ID;

void richTextFixed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextFixed");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextUrl::richTextUrl()
  : text_()
  , url_()
  , is_cached_()
{}

richTextUrl::richTextUrl(object_ptr<RichText> &&text_, string const &url_, bool is_cached_)
  : text_(std::move(text_))
  , url_(url_)
  , is_cached_(is_cached_)
{}

const std::int32_t richTextUrl::ID;

void richTextUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextUrl");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("url", url_);
    s.store_field("is_cached", is_cached_);
    s.store_class_end();
  }
}

richTextEmailAddress::richTextEmailAddress()
  : text_()
  , email_address_()
{}

richTextEmailAddress::richTextEmailAddress(object_ptr<RichText> &&text_, string const &email_address_)
  : text_(std::move(text_))
  , email_address_(email_address_)
{}

const std::int32_t richTextEmailAddress::ID;

void richTextEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextEmailAddress");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

richTextSubscript::richTextSubscript()
  : text_()
{}

richTextSubscript::richTextSubscript(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextSubscript::ID;

void richTextSubscript::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextSubscript");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextSuperscript::richTextSuperscript()
  : text_()
{}

richTextSuperscript::richTextSuperscript(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextSuperscript::ID;

void richTextSuperscript::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextSuperscript");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextMarked::richTextMarked()
  : text_()
{}

richTextMarked::richTextMarked(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextMarked::ID;

void richTextMarked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextMarked");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextPhoneNumber::richTextPhoneNumber()
  : text_()
  , phone_number_()
{}

richTextPhoneNumber::richTextPhoneNumber(object_ptr<RichText> &&text_, string const &phone_number_)
  : text_(std::move(text_))
  , phone_number_(phone_number_)
{}

const std::int32_t richTextPhoneNumber::ID;

void richTextPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextPhoneNumber");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

richTextIcon::richTextIcon()
  : document_()
  , width_()
  , height_()
{}

richTextIcon::richTextIcon(object_ptr<document> &&document_, int32 width_, int32 height_)
  : document_(std::move(document_))
  , width_(width_)
  , height_(height_)
{}

const std::int32_t richTextIcon::ID;

void richTextIcon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextIcon");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

richTextReference::richTextReference()
  : text_()
  , anchor_name_()
  , url_()
{}

richTextReference::richTextReference(object_ptr<RichText> &&text_, string const &anchor_name_, string const &url_)
  : text_(std::move(text_))
  , anchor_name_(anchor_name_)
  , url_(url_)
{}

const std::int32_t richTextReference::ID;

void richTextReference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextReference");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("anchor_name", anchor_name_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

richTextAnchor::richTextAnchor()
  : name_()
{}

richTextAnchor::richTextAnchor(string const &name_)
  : name_(name_)
{}

const std::int32_t richTextAnchor::ID;

void richTextAnchor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextAnchor");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

richTextAnchorLink::richTextAnchorLink()
  : text_()
  , anchor_name_()
  , url_()
{}

richTextAnchorLink::richTextAnchorLink(object_ptr<RichText> &&text_, string const &anchor_name_, string const &url_)
  : text_(std::move(text_))
  , anchor_name_(anchor_name_)
  , url_(url_)
{}

const std::int32_t richTextAnchorLink::ID;

void richTextAnchorLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextAnchorLink");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("anchor_name", anchor_name_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

richTexts::richTexts()
  : texts_()
{}

richTexts::richTexts(array<object_ptr<RichText>> &&texts_)
  : texts_(std::move(texts_))
{}

const std::int32_t richTexts::ID;

void richTexts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTexts");
    { s.store_vector_begin("texts", texts_.size()); for (const auto &_value : texts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

rtmpUrl::rtmpUrl()
  : url_()
  , stream_key_()
{}

rtmpUrl::rtmpUrl(string const &url_, string const &stream_key_)
  : url_(url_)
  , stream_key_(stream_key_)
{}

const std::int32_t rtmpUrl::ID;

void rtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "rtmpUrl");
    s.store_field("url", url_);
    s.store_field("stream_key", stream_key_);
    s.store_class_end();
  }
}

savedCredentials::savedCredentials()
  : id_()
  , title_()
{}

savedCredentials::savedCredentials(string const &id_, string const &title_)
  : id_(id_)
  , title_(title_)
{}

const std::int32_t savedCredentials::ID;

void savedCredentials::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedCredentials");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

scopeNotificationSettings::scopeNotificationSettings()
  : mute_for_()
  , sound_id_()
  , show_preview_()
  , disable_pinned_message_notifications_()
  , disable_mention_notifications_()
{}

scopeNotificationSettings::scopeNotificationSettings(int32 mute_for_, int64 sound_id_, bool show_preview_, bool disable_pinned_message_notifications_, bool disable_mention_notifications_)
  : mute_for_(mute_for_)
  , sound_id_(sound_id_)
  , show_preview_(show_preview_)
  , disable_pinned_message_notifications_(disable_pinned_message_notifications_)
  , disable_mention_notifications_(disable_mention_notifications_)
{}

const std::int32_t scopeNotificationSettings::ID;

void scopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "scopeNotificationSettings");
    s.store_field("mute_for", mute_for_);
    s.store_field("sound_id", sound_id_);
    s.store_field("show_preview", show_preview_);
    s.store_field("disable_pinned_message_notifications", disable_pinned_message_notifications_);
    s.store_field("disable_mention_notifications", disable_mention_notifications_);
    s.store_class_end();
  }
}

searchMessagesFilterEmpty::searchMessagesFilterEmpty() {
}

const std::int32_t searchMessagesFilterEmpty::ID;

void searchMessagesFilterEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterEmpty");
    s.store_class_end();
  }
}

searchMessagesFilterAnimation::searchMessagesFilterAnimation() {
}

const std::int32_t searchMessagesFilterAnimation::ID;

void searchMessagesFilterAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterAnimation");
    s.store_class_end();
  }
}

searchMessagesFilterAudio::searchMessagesFilterAudio() {
}

const std::int32_t searchMessagesFilterAudio::ID;

void searchMessagesFilterAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterAudio");
    s.store_class_end();
  }
}

searchMessagesFilterDocument::searchMessagesFilterDocument() {
}

const std::int32_t searchMessagesFilterDocument::ID;

void searchMessagesFilterDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterDocument");
    s.store_class_end();
  }
}

searchMessagesFilterPhoto::searchMessagesFilterPhoto() {
}

const std::int32_t searchMessagesFilterPhoto::ID;

void searchMessagesFilterPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterPhoto");
    s.store_class_end();
  }
}

searchMessagesFilterVideo::searchMessagesFilterVideo() {
}

const std::int32_t searchMessagesFilterVideo::ID;

void searchMessagesFilterVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVideo");
    s.store_class_end();
  }
}

searchMessagesFilterVoiceNote::searchMessagesFilterVoiceNote() {
}

const std::int32_t searchMessagesFilterVoiceNote::ID;

void searchMessagesFilterVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVoiceNote");
    s.store_class_end();
  }
}

searchMessagesFilterPhotoAndVideo::searchMessagesFilterPhotoAndVideo() {
}

const std::int32_t searchMessagesFilterPhotoAndVideo::ID;

void searchMessagesFilterPhotoAndVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterPhotoAndVideo");
    s.store_class_end();
  }
}

searchMessagesFilterUrl::searchMessagesFilterUrl() {
}

const std::int32_t searchMessagesFilterUrl::ID;

void searchMessagesFilterUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterUrl");
    s.store_class_end();
  }
}

searchMessagesFilterChatPhoto::searchMessagesFilterChatPhoto() {
}

const std::int32_t searchMessagesFilterChatPhoto::ID;

void searchMessagesFilterChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterChatPhoto");
    s.store_class_end();
  }
}

searchMessagesFilterVideoNote::searchMessagesFilterVideoNote() {
}

const std::int32_t searchMessagesFilterVideoNote::ID;

void searchMessagesFilterVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVideoNote");
    s.store_class_end();
  }
}

searchMessagesFilterVoiceAndVideoNote::searchMessagesFilterVoiceAndVideoNote() {
}

const std::int32_t searchMessagesFilterVoiceAndVideoNote::ID;

void searchMessagesFilterVoiceAndVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterVoiceAndVideoNote");
    s.store_class_end();
  }
}

searchMessagesFilterMention::searchMessagesFilterMention() {
}

const std::int32_t searchMessagesFilterMention::ID;

void searchMessagesFilterMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterMention");
    s.store_class_end();
  }
}

searchMessagesFilterUnreadMention::searchMessagesFilterUnreadMention() {
}

const std::int32_t searchMessagesFilterUnreadMention::ID;

void searchMessagesFilterUnreadMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterUnreadMention");
    s.store_class_end();
  }
}

searchMessagesFilterUnreadReaction::searchMessagesFilterUnreadReaction() {
}

const std::int32_t searchMessagesFilterUnreadReaction::ID;

void searchMessagesFilterUnreadReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterUnreadReaction");
    s.store_class_end();
  }
}

searchMessagesFilterFailedToSend::searchMessagesFilterFailedToSend() {
}

const std::int32_t searchMessagesFilterFailedToSend::ID;

void searchMessagesFilterFailedToSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterFailedToSend");
    s.store_class_end();
  }
}

searchMessagesFilterPinned::searchMessagesFilterPinned() {
}

const std::int32_t searchMessagesFilterPinned::ID;

void searchMessagesFilterPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessagesFilterPinned");
    s.store_class_end();
  }
}

seconds::seconds()
  : seconds_()
{}

seconds::seconds(double seconds_)
  : seconds_(seconds_)
{}

const std::int32_t seconds::ID;

void seconds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "seconds");
    s.store_field("seconds", seconds_);
    s.store_class_end();
  }
}

secretChat::secretChat()
  : id_()
  , user_id_()
  , state_()
  , is_outbound_()
  , key_hash_()
  , layer_()
{}

secretChat::secretChat(int32 id_, int53 user_id_, object_ptr<SecretChatState> &&state_, bool is_outbound_, bytes const &key_hash_, int32 layer_)
  : id_(id_)
  , user_id_(user_id_)
  , state_(std::move(state_))
  , is_outbound_(is_outbound_)
  , key_hash_(std::move(key_hash_))
  , layer_(layer_)
{}

const std::int32_t secretChat::ID;

void secretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChat");
    s.store_field("id", id_);
    s.store_field("user_id", user_id_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_field("is_outbound", is_outbound_);
    s.store_bytes_field("key_hash", key_hash_);
    s.store_field("layer", layer_);
    s.store_class_end();
  }
}

secretChatStatePending::secretChatStatePending() {
}

const std::int32_t secretChatStatePending::ID;

void secretChatStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChatStatePending");
    s.store_class_end();
  }
}

secretChatStateReady::secretChatStateReady() {
}

const std::int32_t secretChatStateReady::ID;

void secretChatStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChatStateReady");
    s.store_class_end();
  }
}

secretChatStateClosed::secretChatStateClosed() {
}

const std::int32_t secretChatStateClosed::ID;

void secretChatStateClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChatStateClosed");
    s.store_class_end();
  }
}

sentWebAppMessage::sentWebAppMessage()
  : inline_message_id_()
{}

sentWebAppMessage::sentWebAppMessage(string const &inline_message_id_)
  : inline_message_id_(inline_message_id_)
{}

const std::int32_t sentWebAppMessage::ID;

void sentWebAppMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sentWebAppMessage");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_class_end();
  }
}

session::session()
  : id_()
  , is_current_()
  , is_password_pending_()
  , can_accept_secret_chats_()
  , can_accept_calls_()
  , type_()
  , api_id_()
  , application_name_()
  , application_version_()
  , is_official_application_()
  , device_model_()
  , platform_()
  , system_version_()
  , log_in_date_()
  , last_active_date_()
  , ip_()
  , country_()
  , region_()
{}

session::session(int64 id_, bool is_current_, bool is_password_pending_, bool can_accept_secret_chats_, bool can_accept_calls_, object_ptr<SessionType> &&type_, int32 api_id_, string const &application_name_, string const &application_version_, bool is_official_application_, string const &device_model_, string const &platform_, string const &system_version_, int32 log_in_date_, int32 last_active_date_, string const &ip_, string const &country_, string const &region_)
  : id_(id_)
  , is_current_(is_current_)
  , is_password_pending_(is_password_pending_)
  , can_accept_secret_chats_(can_accept_secret_chats_)
  , can_accept_calls_(can_accept_calls_)
  , type_(std::move(type_))
  , api_id_(api_id_)
  , application_name_(application_name_)
  , application_version_(application_version_)
  , is_official_application_(is_official_application_)
  , device_model_(device_model_)
  , platform_(platform_)
  , system_version_(system_version_)
  , log_in_date_(log_in_date_)
  , last_active_date_(last_active_date_)
  , ip_(ip_)
  , country_(country_)
  , region_(region_)
{}

const std::int32_t session::ID;

void session::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "session");
    s.store_field("id", id_);
    s.store_field("is_current", is_current_);
    s.store_field("is_password_pending", is_password_pending_);
    s.store_field("can_accept_secret_chats", can_accept_secret_chats_);
    s.store_field("can_accept_calls", can_accept_calls_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("api_id", api_id_);
    s.store_field("application_name", application_name_);
    s.store_field("application_version", application_version_);
    s.store_field("is_official_application", is_official_application_);
    s.store_field("device_model", device_model_);
    s.store_field("platform", platform_);
    s.store_field("system_version", system_version_);
    s.store_field("log_in_date", log_in_date_);
    s.store_field("last_active_date", last_active_date_);
    s.store_field("ip", ip_);
    s.store_field("country", country_);
    s.store_field("region", region_);
    s.store_class_end();
  }
}

sessionTypeAndroid::sessionTypeAndroid() {
}

const std::int32_t sessionTypeAndroid::ID;

void sessionTypeAndroid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeAndroid");
    s.store_class_end();
  }
}

sessionTypeApple::sessionTypeApple() {
}

const std::int32_t sessionTypeApple::ID;

void sessionTypeApple::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeApple");
    s.store_class_end();
  }
}

sessionTypeBrave::sessionTypeBrave() {
}

const std::int32_t sessionTypeBrave::ID;

void sessionTypeBrave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeBrave");
    s.store_class_end();
  }
}

sessionTypeChrome::sessionTypeChrome() {
}

const std::int32_t sessionTypeChrome::ID;

void sessionTypeChrome::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeChrome");
    s.store_class_end();
  }
}

sessionTypeEdge::sessionTypeEdge() {
}

const std::int32_t sessionTypeEdge::ID;

void sessionTypeEdge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeEdge");
    s.store_class_end();
  }
}

sessionTypeFirefox::sessionTypeFirefox() {
}

const std::int32_t sessionTypeFirefox::ID;

void sessionTypeFirefox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeFirefox");
    s.store_class_end();
  }
}

sessionTypeIpad::sessionTypeIpad() {
}

const std::int32_t sessionTypeIpad::ID;

void sessionTypeIpad::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeIpad");
    s.store_class_end();
  }
}

sessionTypeIphone::sessionTypeIphone() {
}

const std::int32_t sessionTypeIphone::ID;

void sessionTypeIphone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeIphone");
    s.store_class_end();
  }
}

sessionTypeLinux::sessionTypeLinux() {
}

const std::int32_t sessionTypeLinux::ID;

void sessionTypeLinux::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeLinux");
    s.store_class_end();
  }
}

sessionTypeMac::sessionTypeMac() {
}

const std::int32_t sessionTypeMac::ID;

void sessionTypeMac::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeMac");
    s.store_class_end();
  }
}

sessionTypeOpera::sessionTypeOpera() {
}

const std::int32_t sessionTypeOpera::ID;

void sessionTypeOpera::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeOpera");
    s.store_class_end();
  }
}

sessionTypeSafari::sessionTypeSafari() {
}

const std::int32_t sessionTypeSafari::ID;

void sessionTypeSafari::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeSafari");
    s.store_class_end();
  }
}

sessionTypeUbuntu::sessionTypeUbuntu() {
}

const std::int32_t sessionTypeUbuntu::ID;

void sessionTypeUbuntu::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeUbuntu");
    s.store_class_end();
  }
}

sessionTypeUnknown::sessionTypeUnknown() {
}

const std::int32_t sessionTypeUnknown::ID;

void sessionTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeUnknown");
    s.store_class_end();
  }
}

sessionTypeVivaldi::sessionTypeVivaldi() {
}

const std::int32_t sessionTypeVivaldi::ID;

void sessionTypeVivaldi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeVivaldi");
    s.store_class_end();
  }
}

sessionTypeWindows::sessionTypeWindows() {
}

const std::int32_t sessionTypeWindows::ID;

void sessionTypeWindows::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeWindows");
    s.store_class_end();
  }
}

sessionTypeXbox::sessionTypeXbox() {
}

const std::int32_t sessionTypeXbox::ID;

void sessionTypeXbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeXbox");
    s.store_class_end();
  }
}

sessions::sessions()
  : sessions_()
  , inactive_session_ttl_days_()
{}

sessions::sessions(array<object_ptr<session>> &&sessions_, int32 inactive_session_ttl_days_)
  : sessions_(std::move(sessions_))
  , inactive_session_ttl_days_(inactive_session_ttl_days_)
{}

const std::int32_t sessions::ID;

void sessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessions");
    { s.store_vector_begin("sessions", sessions_.size()); for (const auto &_value : sessions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("inactive_session_ttl_days", inactive_session_ttl_days_);
    s.store_class_end();
  }
}

shippingOption::shippingOption()
  : id_()
  , title_()
  , price_parts_()
{}

shippingOption::shippingOption(string const &id_, string const &title_, array<object_ptr<labeledPricePart>> &&price_parts_)
  : id_(id_)
  , title_(title_)
  , price_parts_(std::move(price_parts_))
{}

const std::int32_t shippingOption::ID;

void shippingOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shippingOption");
    s.store_field("id", id_);
    s.store_field("title", title_);
    { s.store_vector_begin("price_parts", price_parts_.size()); for (const auto &_value : price_parts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sponsoredMessage::sponsoredMessage()
  : message_id_()
  , sponsor_chat_id_()
  , sponsor_chat_info_()
  , link_()
  , content_()
{}

sponsoredMessage::sponsoredMessage(int53 message_id_, int53 sponsor_chat_id_, object_ptr<chatInviteLinkInfo> &&sponsor_chat_info_, object_ptr<InternalLinkType> &&link_, object_ptr<MessageContent> &&content_)
  : message_id_(message_id_)
  , sponsor_chat_id_(sponsor_chat_id_)
  , sponsor_chat_info_(std::move(sponsor_chat_info_))
  , link_(std::move(link_))
  , content_(std::move(content_))
{}

const std::int32_t sponsoredMessage::ID;

void sponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredMessage");
    s.store_field("message_id", message_id_);
    s.store_field("sponsor_chat_id", sponsor_chat_id_);
    s.store_object_field("sponsor_chat_info", static_cast<const BaseObject *>(sponsor_chat_info_.get()));
    s.store_object_field("link", static_cast<const BaseObject *>(link_.get()));
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

statisticalGraphData::statisticalGraphData()
  : json_data_()
  , zoom_token_()
{}

statisticalGraphData::statisticalGraphData(string const &json_data_, string const &zoom_token_)
  : json_data_(json_data_)
  , zoom_token_(zoom_token_)
{}

const std::int32_t statisticalGraphData::ID;

void statisticalGraphData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalGraphData");
    s.store_field("json_data", json_data_);
    s.store_field("zoom_token", zoom_token_);
    s.store_class_end();
  }
}

statisticalGraphAsync::statisticalGraphAsync()
  : token_()
{}

statisticalGraphAsync::statisticalGraphAsync(string const &token_)
  : token_(token_)
{}

const std::int32_t statisticalGraphAsync::ID;

void statisticalGraphAsync::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalGraphAsync");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

statisticalGraphError::statisticalGraphError()
  : error_message_()
{}

statisticalGraphError::statisticalGraphError(string const &error_message_)
  : error_message_(error_message_)
{}

const std::int32_t statisticalGraphError::ID;

void statisticalGraphError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalGraphError");
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

statisticalValue::statisticalValue()
  : value_()
  , previous_value_()
  , growth_rate_percentage_()
{}

statisticalValue::statisticalValue(double value_, double previous_value_, double growth_rate_percentage_)
  : value_(value_)
  , previous_value_(previous_value_)
  , growth_rate_percentage_(growth_rate_percentage_)
{}

const std::int32_t statisticalValue::ID;

void statisticalValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalValue");
    s.store_field("value", value_);
    s.store_field("previous_value", previous_value_);
    s.store_field("growth_rate_percentage", growth_rate_percentage_);
    s.store_class_end();
  }
}

sticker::sticker()
  : set_id_()
  , width_()
  , height_()
  , emoji_()
  , type_()
  , outline_()
  , thumbnail_()
  , sticker_()
{}

sticker::sticker(int64 set_id_, int32 width_, int32 height_, string const &emoji_, object_ptr<StickerType> &&type_, array<object_ptr<closedVectorPath>> &&outline_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&sticker_)
  : set_id_(set_id_)
  , width_(width_)
  , height_(height_)
  , emoji_(emoji_)
  , type_(std::move(type_))
  , outline_(std::move(outline_))
  , thumbnail_(std::move(thumbnail_))
  , sticker_(std::move(sticker_))
{}

const std::int32_t sticker::ID;

void sticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sticker");
    s.store_field("set_id", set_id_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("emoji", emoji_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    { s.store_vector_begin("outline", outline_.size()); for (const auto &_value : outline_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

stickerSet::stickerSet()
  : id_()
  , title_()
  , name_()
  , thumbnail_()
  , thumbnail_outline_()
  , is_installed_()
  , is_archived_()
  , is_official_()
  , sticker_type_()
  , is_viewed_()
  , stickers_()
  , emojis_()
{}

stickerSet::stickerSet(int64 id_, string const &title_, string const &name_, object_ptr<thumbnail> &&thumbnail_, array<object_ptr<closedVectorPath>> &&thumbnail_outline_, bool is_installed_, bool is_archived_, bool is_official_, object_ptr<StickerType> &&sticker_type_, bool is_viewed_, array<object_ptr<sticker>> &&stickers_, array<object_ptr<emojis>> &&emojis_)
  : id_(id_)
  , title_(title_)
  , name_(name_)
  , thumbnail_(std::move(thumbnail_))
  , thumbnail_outline_(std::move(thumbnail_outline_))
  , is_installed_(is_installed_)
  , is_archived_(is_archived_)
  , is_official_(is_official_)
  , sticker_type_(std::move(sticker_type_))
  , is_viewed_(is_viewed_)
  , stickers_(std::move(stickers_))
  , emojis_(std::move(emojis_))
{}

const std::int32_t stickerSet::ID;

void stickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSet");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("name", name_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    { s.store_vector_begin("thumbnail_outline", thumbnail_outline_.size()); for (const auto &_value : thumbnail_outline_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_installed", is_installed_);
    s.store_field("is_archived", is_archived_);
    s.store_field("is_official", is_official_);
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("is_viewed", is_viewed_);
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stickerSetInfo::stickerSetInfo()
  : id_()
  , title_()
  , name_()
  , thumbnail_()
  , thumbnail_outline_()
  , is_installed_()
  , is_archived_()
  , is_official_()
  , sticker_type_()
  , is_viewed_()
  , size_()
  , covers_()
{}

stickerSetInfo::stickerSetInfo(int64 id_, string const &title_, string const &name_, object_ptr<thumbnail> &&thumbnail_, array<object_ptr<closedVectorPath>> &&thumbnail_outline_, bool is_installed_, bool is_archived_, bool is_official_, object_ptr<StickerType> &&sticker_type_, bool is_viewed_, int32 size_, array<object_ptr<sticker>> &&covers_)
  : id_(id_)
  , title_(title_)
  , name_(name_)
  , thumbnail_(std::move(thumbnail_))
  , thumbnail_outline_(std::move(thumbnail_outline_))
  , is_installed_(is_installed_)
  , is_archived_(is_archived_)
  , is_official_(is_official_)
  , sticker_type_(std::move(sticker_type_))
  , is_viewed_(is_viewed_)
  , size_(size_)
  , covers_(std::move(covers_))
{}

const std::int32_t stickerSetInfo::ID;

void stickerSetInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSetInfo");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("name", name_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    { s.store_vector_begin("thumbnail_outline", thumbnail_outline_.size()); for (const auto &_value : thumbnail_outline_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_installed", is_installed_);
    s.store_field("is_archived", is_archived_);
    s.store_field("is_official", is_official_);
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("is_viewed", is_viewed_);
    s.store_field("size", size_);
    { s.store_vector_begin("covers", covers_.size()); for (const auto &_value : covers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stickerSets::stickerSets()
  : total_count_()
  , sets_()
{}

stickerSets::stickerSets(int32 total_count_, array<object_ptr<stickerSetInfo>> &&sets_)
  : total_count_(total_count_)
  , sets_(std::move(sets_))
{}

const std::int32_t stickerSets::ID;

void stickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSets");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stickerTypeStatic::stickerTypeStatic() {
}

const std::int32_t stickerTypeStatic::ID;

void stickerTypeStatic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerTypeStatic");
    s.store_class_end();
  }
}

stickerTypeAnimated::stickerTypeAnimated() {
}

const std::int32_t stickerTypeAnimated::ID;

void stickerTypeAnimated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerTypeAnimated");
    s.store_class_end();
  }
}

stickerTypeVideo::stickerTypeVideo() {
}

const std::int32_t stickerTypeVideo::ID;

void stickerTypeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerTypeVideo");
    s.store_class_end();
  }
}

stickerTypeMask::stickerTypeMask()
  : mask_position_()
{}

stickerTypeMask::stickerTypeMask(object_ptr<maskPosition> &&mask_position_)
  : mask_position_(std::move(mask_position_))
{}

const std::int32_t stickerTypeMask::ID;

void stickerTypeMask::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerTypeMask");
    s.store_object_field("mask_position", static_cast<const BaseObject *>(mask_position_.get()));
    s.store_class_end();
  }
}

stickers::stickers()
  : stickers_()
{}

stickers::stickers(array<object_ptr<sticker>> &&stickers_)
  : stickers_(std::move(stickers_))
{}

const std::int32_t stickers::ID;

void stickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers");
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storageStatistics::storageStatistics()
  : size_()
  , count_()
  , by_chat_()
{}

storageStatistics::storageStatistics(int53 size_, int32 count_, array<object_ptr<storageStatisticsByChat>> &&by_chat_)
  : size_(size_)
  , count_(count_)
  , by_chat_(std::move(by_chat_))
{}

const std::int32_t storageStatistics::ID;

void storageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatistics");
    s.store_field("size", size_);
    s.store_field("count", count_);
    { s.store_vector_begin("by_chat", by_chat_.size()); for (const auto &_value : by_chat_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storageStatisticsByChat::storageStatisticsByChat()
  : chat_id_()
  , size_()
  , count_()
  , by_file_type_()
{}

storageStatisticsByChat::storageStatisticsByChat(int53 chat_id_, int53 size_, int32 count_, array<object_ptr<storageStatisticsByFileType>> &&by_file_type_)
  : chat_id_(chat_id_)
  , size_(size_)
  , count_(count_)
  , by_file_type_(std::move(by_file_type_))
{}

const std::int32_t storageStatisticsByChat::ID;

void storageStatisticsByChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatisticsByChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("size", size_);
    s.store_field("count", count_);
    { s.store_vector_begin("by_file_type", by_file_type_.size()); for (const auto &_value : by_file_type_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storageStatisticsByFileType::storageStatisticsByFileType()
  : file_type_()
  , size_()
  , count_()
{}

storageStatisticsByFileType::storageStatisticsByFileType(object_ptr<FileType> &&file_type_, int53 size_, int32 count_)
  : file_type_(std::move(file_type_))
  , size_(size_)
  , count_(count_)
{}

const std::int32_t storageStatisticsByFileType::ID;

void storageStatisticsByFileType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatisticsByFileType");
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_field("size", size_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

storageStatisticsFast::storageStatisticsFast()
  : files_size_()
  , file_count_()
  , database_size_()
  , language_pack_database_size_()
  , log_size_()
{}

storageStatisticsFast::storageStatisticsFast(int53 files_size_, int32 file_count_, int53 database_size_, int53 language_pack_database_size_, int53 log_size_)
  : files_size_(files_size_)
  , file_count_(file_count_)
  , database_size_(database_size_)
  , language_pack_database_size_(language_pack_database_size_)
  , log_size_(log_size_)
{}

const std::int32_t storageStatisticsFast::ID;

void storageStatisticsFast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatisticsFast");
    s.store_field("files_size", files_size_);
    s.store_field("file_count", file_count_);
    s.store_field("database_size", database_size_);
    s.store_field("language_pack_database_size", language_pack_database_size_);
    s.store_field("log_size", log_size_);
    s.store_class_end();
  }
}

suggestedActionEnableArchiveAndMuteNewChats::suggestedActionEnableArchiveAndMuteNewChats() {
}

const std::int32_t suggestedActionEnableArchiveAndMuteNewChats::ID;

void suggestedActionEnableArchiveAndMuteNewChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionEnableArchiveAndMuteNewChats");
    s.store_class_end();
  }
}

suggestedActionCheckPassword::suggestedActionCheckPassword() {
}

const std::int32_t suggestedActionCheckPassword::ID;

void suggestedActionCheckPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionCheckPassword");
    s.store_class_end();
  }
}

suggestedActionCheckPhoneNumber::suggestedActionCheckPhoneNumber() {
}

const std::int32_t suggestedActionCheckPhoneNumber::ID;

void suggestedActionCheckPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionCheckPhoneNumber");
    s.store_class_end();
  }
}

suggestedActionViewChecksHint::suggestedActionViewChecksHint() {
}

const std::int32_t suggestedActionViewChecksHint::ID;

void suggestedActionViewChecksHint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionViewChecksHint");
    s.store_class_end();
  }
}

suggestedActionConvertToBroadcastGroup::suggestedActionConvertToBroadcastGroup()
  : supergroup_id_()
{}

suggestedActionConvertToBroadcastGroup::suggestedActionConvertToBroadcastGroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t suggestedActionConvertToBroadcastGroup::ID;

void suggestedActionConvertToBroadcastGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionConvertToBroadcastGroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

suggestedActionSetPassword::suggestedActionSetPassword()
  : authorization_delay_()
{}

suggestedActionSetPassword::suggestedActionSetPassword(int32 authorization_delay_)
  : authorization_delay_(authorization_delay_)
{}

const std::int32_t suggestedActionSetPassword::ID;

void suggestedActionSetPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedActionSetPassword");
    s.store_field("authorization_delay", authorization_delay_);
    s.store_class_end();
  }
}

supergroup::supergroup()
  : id_()
  , username_()
  , date_()
  , status_()
  , member_count_()
  , has_linked_chat_()
  , has_location_()
  , sign_messages_()
  , is_slow_mode_enabled_()
  , is_channel_()
  , is_broadcast_group_()
  , is_verified_()
  , restriction_reason_()
  , is_scam_()
  , is_fake_()
{}

supergroup::supergroup(int53 id_, string const &username_, int32 date_, object_ptr<ChatMemberStatus> &&status_, int32 member_count_, bool has_linked_chat_, bool has_location_, bool sign_messages_, bool is_slow_mode_enabled_, bool is_channel_, bool is_broadcast_group_, bool is_verified_, string const &restriction_reason_, bool is_scam_, bool is_fake_)
  : id_(id_)
  , username_(username_)
  , date_(date_)
  , status_(std::move(status_))
  , member_count_(member_count_)
  , has_linked_chat_(has_linked_chat_)
  , has_location_(has_location_)
  , sign_messages_(sign_messages_)
  , is_slow_mode_enabled_(is_slow_mode_enabled_)
  , is_channel_(is_channel_)
  , is_broadcast_group_(is_broadcast_group_)
  , is_verified_(is_verified_)
  , restriction_reason_(restriction_reason_)
  , is_scam_(is_scam_)
  , is_fake_(is_fake_)
{}

const std::int32_t supergroup::ID;

void supergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroup");
    s.store_field("id", id_);
    s.store_field("username", username_);
    s.store_field("date", date_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("member_count", member_count_);
    s.store_field("has_linked_chat", has_linked_chat_);
    s.store_field("has_location", has_location_);
    s.store_field("sign_messages", sign_messages_);
    s.store_field("is_slow_mode_enabled", is_slow_mode_enabled_);
    s.store_field("is_channel", is_channel_);
    s.store_field("is_broadcast_group", is_broadcast_group_);
    s.store_field("is_verified", is_verified_);
    s.store_field("restriction_reason", restriction_reason_);
    s.store_field("is_scam", is_scam_);
    s.store_field("is_fake", is_fake_);
    s.store_class_end();
  }
}

supergroupFullInfo::supergroupFullInfo()
  : photo_()
  , description_()
  , member_count_()
  , administrator_count_()
  , restricted_count_()
  , banned_count_()
  , linked_chat_id_()
  , slow_mode_delay_()
  , slow_mode_delay_expires_in_()
  , can_get_members_()
  , can_set_username_()
  , can_set_sticker_set_()
  , can_set_location_()
  , can_get_statistics_()
  , is_all_history_available_()
  , sticker_set_id_()
  , location_()
  , invite_link_()
  , bot_commands_()
  , upgraded_from_basic_group_id_()
  , upgraded_from_max_message_id_()
{}

supergroupFullInfo::supergroupFullInfo(object_ptr<chatPhoto> &&photo_, string const &description_, int32 member_count_, int32 administrator_count_, int32 restricted_count_, int32 banned_count_, int53 linked_chat_id_, int32 slow_mode_delay_, double slow_mode_delay_expires_in_, bool can_get_members_, bool can_set_username_, bool can_set_sticker_set_, bool can_set_location_, bool can_get_statistics_, bool is_all_history_available_, int64 sticker_set_id_, object_ptr<chatLocation> &&location_, object_ptr<chatInviteLink> &&invite_link_, array<object_ptr<botCommands>> &&bot_commands_, int53 upgraded_from_basic_group_id_, int53 upgraded_from_max_message_id_)
  : photo_(std::move(photo_))
  , description_(description_)
  , member_count_(member_count_)
  , administrator_count_(administrator_count_)
  , restricted_count_(restricted_count_)
  , banned_count_(banned_count_)
  , linked_chat_id_(linked_chat_id_)
  , slow_mode_delay_(slow_mode_delay_)
  , slow_mode_delay_expires_in_(slow_mode_delay_expires_in_)
  , can_get_members_(can_get_members_)
  , can_set_username_(can_set_username_)
  , can_set_sticker_set_(can_set_sticker_set_)
  , can_set_location_(can_set_location_)
  , can_get_statistics_(can_get_statistics_)
  , is_all_history_available_(is_all_history_available_)
  , sticker_set_id_(sticker_set_id_)
  , location_(std::move(location_))
  , invite_link_(std::move(invite_link_))
  , bot_commands_(std::move(bot_commands_))
  , upgraded_from_basic_group_id_(upgraded_from_basic_group_id_)
  , upgraded_from_max_message_id_(upgraded_from_max_message_id_)
{}

const std::int32_t supergroupFullInfo::ID;

void supergroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupFullInfo");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("description", description_);
    s.store_field("member_count", member_count_);
    s.store_field("administrator_count", administrator_count_);
    s.store_field("restricted_count", restricted_count_);
    s.store_field("banned_count", banned_count_);
    s.store_field("linked_chat_id", linked_chat_id_);
    s.store_field("slow_mode_delay", slow_mode_delay_);
    s.store_field("slow_mode_delay_expires_in", slow_mode_delay_expires_in_);
    s.store_field("can_get_members", can_get_members_);
    s.store_field("can_set_username", can_set_username_);
    s.store_field("can_set_sticker_set", can_set_sticker_set_);
    s.store_field("can_set_location", can_set_location_);
    s.store_field("can_get_statistics", can_get_statistics_);
    s.store_field("is_all_history_available", is_all_history_available_);
    s.store_field("sticker_set_id", sticker_set_id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    { s.store_vector_begin("bot_commands", bot_commands_.size()); for (const auto &_value : bot_commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("upgraded_from_basic_group_id", upgraded_from_basic_group_id_);
    s.store_field("upgraded_from_max_message_id", upgraded_from_max_message_id_);
    s.store_class_end();
  }
}

supergroupMembersFilterRecent::supergroupMembersFilterRecent() {
}

const std::int32_t supergroupMembersFilterRecent::ID;

void supergroupMembersFilterRecent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterRecent");
    s.store_class_end();
  }
}

supergroupMembersFilterContacts::supergroupMembersFilterContacts()
  : query_()
{}

supergroupMembersFilterContacts::supergroupMembersFilterContacts(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterContacts::ID;

void supergroupMembersFilterContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterContacts");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterAdministrators::supergroupMembersFilterAdministrators() {
}

const std::int32_t supergroupMembersFilterAdministrators::ID;

void supergroupMembersFilterAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterAdministrators");
    s.store_class_end();
  }
}

supergroupMembersFilterSearch::supergroupMembersFilterSearch()
  : query_()
{}

supergroupMembersFilterSearch::supergroupMembersFilterSearch(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterSearch::ID;

void supergroupMembersFilterSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterSearch");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterRestricted::supergroupMembersFilterRestricted()
  : query_()
{}

supergroupMembersFilterRestricted::supergroupMembersFilterRestricted(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterRestricted::ID;

void supergroupMembersFilterRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterRestricted");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterBanned::supergroupMembersFilterBanned()
  : query_()
{}

supergroupMembersFilterBanned::supergroupMembersFilterBanned(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterBanned::ID;

void supergroupMembersFilterBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterBanned");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterMention::supergroupMembersFilterMention()
  : query_()
  , message_thread_id_()
{}

supergroupMembersFilterMention::supergroupMembersFilterMention(string const &query_, int53 message_thread_id_)
  : query_(query_)
  , message_thread_id_(message_thread_id_)
{}

const std::int32_t supergroupMembersFilterMention::ID;

void supergroupMembersFilterMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterMention");
    s.store_field("query", query_);
    s.store_field("message_thread_id", message_thread_id_);
    s.store_class_end();
  }
}

supergroupMembersFilterBots::supergroupMembersFilterBots() {
}

const std::int32_t supergroupMembersFilterBots::ID;

void supergroupMembersFilterBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterBots");
    s.store_class_end();
  }
}

tMeUrl::tMeUrl()
  : url_()
  , type_()
{}

tMeUrl::tMeUrl(string const &url_, object_ptr<TMeUrlType> &&type_)
  : url_(url_)
  , type_(std::move(type_))
{}

const std::int32_t tMeUrl::ID;

void tMeUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrl");
    s.store_field("url", url_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

tMeUrlTypeUser::tMeUrlTypeUser()
  : user_id_()
{}

tMeUrlTypeUser::tMeUrlTypeUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t tMeUrlTypeUser::ID;

void tMeUrlTypeUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

tMeUrlTypeSupergroup::tMeUrlTypeSupergroup()
  : supergroup_id_()
{}

tMeUrlTypeSupergroup::tMeUrlTypeSupergroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t tMeUrlTypeSupergroup::ID;

void tMeUrlTypeSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeSupergroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

tMeUrlTypeChatInvite::tMeUrlTypeChatInvite()
  : info_()
{}

tMeUrlTypeChatInvite::tMeUrlTypeChatInvite(object_ptr<chatInviteLinkInfo> &&info_)
  : info_(std::move(info_))
{}

const std::int32_t tMeUrlTypeChatInvite::ID;

void tMeUrlTypeChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeChatInvite");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

tMeUrlTypeStickerSet::tMeUrlTypeStickerSet()
  : sticker_set_id_()
{}

tMeUrlTypeStickerSet::tMeUrlTypeStickerSet(int64 sticker_set_id_)
  : sticker_set_id_(sticker_set_id_)
{}

const std::int32_t tMeUrlTypeStickerSet::ID;

void tMeUrlTypeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeStickerSet");
    s.store_field("sticker_set_id", sticker_set_id_);
    s.store_class_end();
  }
}

tMeUrls::tMeUrls()
  : urls_()
{}

tMeUrls::tMeUrls(array<object_ptr<tMeUrl>> &&urls_)
  : urls_(std::move(urls_))
{}

const std::int32_t tMeUrls::ID;

void tMeUrls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrls");
    { s.store_vector_begin("urls", urls_.size()); for (const auto &_value : urls_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

tdlibParameters::tdlibParameters()
  : use_test_dc_()
  , database_directory_()
  , files_directory_()
  , use_file_database_()
  , use_chat_info_database_()
  , use_message_database_()
  , use_secret_chats_()
  , api_id_()
  , api_hash_()
  , system_language_code_()
  , device_model_()
  , system_version_()
  , application_version_()
  , enable_storage_optimizer_()
  , ignore_file_names_()
{}

tdlibParameters::tdlibParameters(bool use_test_dc_, string const &database_directory_, string const &files_directory_, bool use_file_database_, bool use_chat_info_database_, bool use_message_database_, bool use_secret_chats_, int32 api_id_, string const &api_hash_, string const &system_language_code_, string const &device_model_, string const &system_version_, string const &application_version_, bool enable_storage_optimizer_, bool ignore_file_names_)
  : use_test_dc_(use_test_dc_)
  , database_directory_(database_directory_)
  , files_directory_(files_directory_)
  , use_file_database_(use_file_database_)
  , use_chat_info_database_(use_chat_info_database_)
  , use_message_database_(use_message_database_)
  , use_secret_chats_(use_secret_chats_)
  , api_id_(api_id_)
  , api_hash_(api_hash_)
  , system_language_code_(system_language_code_)
  , device_model_(device_model_)
  , system_version_(system_version_)
  , application_version_(application_version_)
  , enable_storage_optimizer_(enable_storage_optimizer_)
  , ignore_file_names_(ignore_file_names_)
{}

const std::int32_t tdlibParameters::ID;

void tdlibParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tdlibParameters");
    s.store_field("use_test_dc", use_test_dc_);
    s.store_field("database_directory", database_directory_);
    s.store_field("files_directory", files_directory_);
    s.store_field("use_file_database", use_file_database_);
    s.store_field("use_chat_info_database", use_chat_info_database_);
    s.store_field("use_message_database", use_message_database_);
    s.store_field("use_secret_chats", use_secret_chats_);
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", api_hash_);
    s.store_field("system_language_code", system_language_code_);
    s.store_field("device_model", device_model_);
    s.store_field("system_version", system_version_);
    s.store_field("application_version", application_version_);
    s.store_field("enable_storage_optimizer", enable_storage_optimizer_);
    s.store_field("ignore_file_names", ignore_file_names_);
    s.store_class_end();
  }
}

temporaryPasswordState::temporaryPasswordState()
  : has_password_()
  , valid_for_()
{}

temporaryPasswordState::temporaryPasswordState(bool has_password_, int32 valid_for_)
  : has_password_(has_password_)
  , valid_for_(valid_for_)
{}

const std::int32_t temporaryPasswordState::ID;

void temporaryPasswordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "temporaryPasswordState");
    s.store_field("has_password", has_password_);
    s.store_field("valid_for", valid_for_);
    s.store_class_end();
  }
}

termsOfService::termsOfService()
  : text_()
  , min_user_age_()
  , show_popup_()
{}

termsOfService::termsOfService(object_ptr<formattedText> &&text_, int32 min_user_age_, bool show_popup_)
  : text_(std::move(text_))
  , min_user_age_(min_user_age_)
  , show_popup_(show_popup_)
{}

const std::int32_t termsOfService::ID;

void termsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "termsOfService");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("min_user_age", min_user_age_);
    s.store_field("show_popup", show_popup_);
    s.store_class_end();
  }
}

testBytes::testBytes()
  : value_()
{}

testBytes::testBytes(bytes const &value_)
  : value_(std::move(value_))
{}

const std::int32_t testBytes::ID;

void testBytes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testBytes");
    s.store_bytes_field("value", value_);
    s.store_class_end();
  }
}

testInt::testInt()
  : value_()
{}

testInt::testInt(int32 value_)
  : value_(value_)
{}

const std::int32_t testInt::ID;

void testInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testInt");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

testString::testString()
  : value_()
{}

testString::testString(string const &value_)
  : value_(value_)
{}

const std::int32_t testString::ID;

void testString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testString");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

testVectorInt::testVectorInt()
  : value_()
{}

testVectorInt::testVectorInt(array<int32> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorInt::ID;

void testVectorInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorInt");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

testVectorIntObject::testVectorIntObject()
  : value_()
{}

testVectorIntObject::testVectorIntObject(array<object_ptr<testInt>> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorIntObject::ID;

void testVectorIntObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorIntObject");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

testVectorString::testVectorString()
  : value_()
{}

testVectorString::testVectorString(array<string> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorString::ID;

void testVectorString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorString");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

testVectorStringObject::testVectorStringObject()
  : value_()
{}

testVectorStringObject::testVectorStringObject(array<object_ptr<testString>> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorStringObject::ID;

void testVectorStringObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorStringObject");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

text::text()
  : text_()
{}

text::text(string const &text_)
  : text_(text_)
{}

const std::int32_t text::ID;

void text::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "text");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

textEntities::textEntities()
  : entities_()
{}

textEntities::textEntities(array<object_ptr<textEntity>> &&entities_)
  : entities_(std::move(entities_))
{}

const std::int32_t textEntities::ID;

void textEntities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntities");
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

textEntity::textEntity()
  : offset_()
  , length_()
  , type_()
{}

textEntity::textEntity(int32 offset_, int32 length_, object_ptr<TextEntityType> &&type_)
  : offset_(offset_)
  , length_(length_)
  , type_(std::move(type_))
{}

const std::int32_t textEntity::ID;

void textEntity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntity");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

textEntityTypeMention::textEntityTypeMention() {
}

const std::int32_t textEntityTypeMention::ID;

void textEntityTypeMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeMention");
    s.store_class_end();
  }
}

textEntityTypeHashtag::textEntityTypeHashtag() {
}

const std::int32_t textEntityTypeHashtag::ID;

void textEntityTypeHashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeHashtag");
    s.store_class_end();
  }
}

textEntityTypeCashtag::textEntityTypeCashtag() {
}

const std::int32_t textEntityTypeCashtag::ID;

void textEntityTypeCashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeCashtag");
    s.store_class_end();
  }
}

textEntityTypeBotCommand::textEntityTypeBotCommand() {
}

const std::int32_t textEntityTypeBotCommand::ID;

void textEntityTypeBotCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeBotCommand");
    s.store_class_end();
  }
}

textEntityTypeUrl::textEntityTypeUrl() {
}

const std::int32_t textEntityTypeUrl::ID;

void textEntityTypeUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeUrl");
    s.store_class_end();
  }
}

textEntityTypeEmailAddress::textEntityTypeEmailAddress() {
}

const std::int32_t textEntityTypeEmailAddress::ID;

void textEntityTypeEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeEmailAddress");
    s.store_class_end();
  }
}

textEntityTypePhoneNumber::textEntityTypePhoneNumber() {
}

const std::int32_t textEntityTypePhoneNumber::ID;

void textEntityTypePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypePhoneNumber");
    s.store_class_end();
  }
}

textEntityTypeBankCardNumber::textEntityTypeBankCardNumber() {
}

const std::int32_t textEntityTypeBankCardNumber::ID;

void textEntityTypeBankCardNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeBankCardNumber");
    s.store_class_end();
  }
}

textEntityTypeBold::textEntityTypeBold() {
}

const std::int32_t textEntityTypeBold::ID;

void textEntityTypeBold::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeBold");
    s.store_class_end();
  }
}

textEntityTypeItalic::textEntityTypeItalic() {
}

const std::int32_t textEntityTypeItalic::ID;

void textEntityTypeItalic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeItalic");
    s.store_class_end();
  }
}

textEntityTypeUnderline::textEntityTypeUnderline() {
}

const std::int32_t textEntityTypeUnderline::ID;

void textEntityTypeUnderline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeUnderline");
    s.store_class_end();
  }
}

textEntityTypeStrikethrough::textEntityTypeStrikethrough() {
}

const std::int32_t textEntityTypeStrikethrough::ID;

void textEntityTypeStrikethrough::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeStrikethrough");
    s.store_class_end();
  }
}

textEntityTypeSpoiler::textEntityTypeSpoiler() {
}

const std::int32_t textEntityTypeSpoiler::ID;

void textEntityTypeSpoiler::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeSpoiler");
    s.store_class_end();
  }
}

textEntityTypeCode::textEntityTypeCode() {
}

const std::int32_t textEntityTypeCode::ID;

void textEntityTypeCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeCode");
    s.store_class_end();
  }
}

textEntityTypePre::textEntityTypePre() {
}

const std::int32_t textEntityTypePre::ID;

void textEntityTypePre::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypePre");
    s.store_class_end();
  }
}

textEntityTypePreCode::textEntityTypePreCode()
  : language_()
{}

textEntityTypePreCode::textEntityTypePreCode(string const &language_)
  : language_(language_)
{}

const std::int32_t textEntityTypePreCode::ID;

void textEntityTypePreCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypePreCode");
    s.store_field("language", language_);
    s.store_class_end();
  }
}

textEntityTypeTextUrl::textEntityTypeTextUrl()
  : url_()
{}

textEntityTypeTextUrl::textEntityTypeTextUrl(string const &url_)
  : url_(url_)
{}

const std::int32_t textEntityTypeTextUrl::ID;

void textEntityTypeTextUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeTextUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

textEntityTypeMentionName::textEntityTypeMentionName()
  : user_id_()
{}

textEntityTypeMentionName::textEntityTypeMentionName(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t textEntityTypeMentionName::ID;

void textEntityTypeMentionName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeMentionName");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

textEntityTypeMediaTimestamp::textEntityTypeMediaTimestamp()
  : media_timestamp_()
{}

textEntityTypeMediaTimestamp::textEntityTypeMediaTimestamp(int32 media_timestamp_)
  : media_timestamp_(media_timestamp_)
{}

const std::int32_t textEntityTypeMediaTimestamp::ID;

void textEntityTypeMediaTimestamp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeMediaTimestamp");
    s.store_field("media_timestamp", media_timestamp_);
    s.store_class_end();
  }
}

textParseModeMarkdown::textParseModeMarkdown()
  : version_()
{}

textParseModeMarkdown::textParseModeMarkdown(int32 version_)
  : version_(version_)
{}

const std::int32_t textParseModeMarkdown::ID;

void textParseModeMarkdown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textParseModeMarkdown");
    s.store_field("version", version_);
    s.store_class_end();
  }
}

textParseModeHTML::textParseModeHTML() {
}

const std::int32_t textParseModeHTML::ID;

void textParseModeHTML::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textParseModeHTML");
    s.store_class_end();
  }
}

themeParameters::themeParameters()
  : background_color_()
  , text_color_()
  , hint_color_()
  , link_color_()
  , button_color_()
  , button_text_color_()
{}

themeParameters::themeParameters(int32 background_color_, int32 text_color_, int32 hint_color_, int32 link_color_, int32 button_color_, int32 button_text_color_)
  : background_color_(background_color_)
  , text_color_(text_color_)
  , hint_color_(hint_color_)
  , link_color_(link_color_)
  , button_color_(button_color_)
  , button_text_color_(button_text_color_)
{}

const std::int32_t themeParameters::ID;

void themeParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "themeParameters");
    s.store_field("background_color", background_color_);
    s.store_field("text_color", text_color_);
    s.store_field("hint_color", hint_color_);
    s.store_field("link_color", link_color_);
    s.store_field("button_color", button_color_);
    s.store_field("button_text_color", button_text_color_);
    s.store_class_end();
  }
}

themeSettings::themeSettings()
  : accent_color_()
  , background_()
  , outgoing_message_fill_()
  , animate_outgoing_message_fill_()
  , outgoing_message_accent_color_()
{}

themeSettings::themeSettings(int32 accent_color_, object_ptr<background> &&background_, object_ptr<BackgroundFill> &&outgoing_message_fill_, bool animate_outgoing_message_fill_, int32 outgoing_message_accent_color_)
  : accent_color_(accent_color_)
  , background_(std::move(background_))
  , outgoing_message_fill_(std::move(outgoing_message_fill_))
  , animate_outgoing_message_fill_(animate_outgoing_message_fill_)
  , outgoing_message_accent_color_(outgoing_message_accent_color_)
{}

const std::int32_t themeSettings::ID;

void themeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "themeSettings");
    s.store_field("accent_color", accent_color_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("outgoing_message_fill", static_cast<const BaseObject *>(outgoing_message_fill_.get()));
    s.store_field("animate_outgoing_message_fill", animate_outgoing_message_fill_);
    s.store_field("outgoing_message_accent_color", outgoing_message_accent_color_);
    s.store_class_end();
  }
}

thumbnail::thumbnail()
  : format_()
  , width_()
  , height_()
  , file_()
{}

thumbnail::thumbnail(object_ptr<ThumbnailFormat> &&format_, int32 width_, int32 height_, object_ptr<file> &&file_)
  : format_(std::move(format_))
  , width_(width_)
  , height_(height_)
  , file_(std::move(file_))
{}

const std::int32_t thumbnail::ID;

void thumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnail");
    s.store_object_field("format", static_cast<const BaseObject *>(format_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

thumbnailFormatJpeg::thumbnailFormatJpeg() {
}

const std::int32_t thumbnailFormatJpeg::ID;

void thumbnailFormatJpeg::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatJpeg");
    s.store_class_end();
  }
}

thumbnailFormatGif::thumbnailFormatGif() {
}

const std::int32_t thumbnailFormatGif::ID;

void thumbnailFormatGif::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatGif");
    s.store_class_end();
  }
}

thumbnailFormatMpeg4::thumbnailFormatMpeg4() {
}

const std::int32_t thumbnailFormatMpeg4::ID;

void thumbnailFormatMpeg4::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatMpeg4");
    s.store_class_end();
  }
}

thumbnailFormatPng::thumbnailFormatPng() {
}

const std::int32_t thumbnailFormatPng::ID;

void thumbnailFormatPng::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatPng");
    s.store_class_end();
  }
}

thumbnailFormatTgs::thumbnailFormatTgs() {
}

const std::int32_t thumbnailFormatTgs::ID;

void thumbnailFormatTgs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatTgs");
    s.store_class_end();
  }
}

thumbnailFormatWebm::thumbnailFormatWebm() {
}

const std::int32_t thumbnailFormatWebm::ID;

void thumbnailFormatWebm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatWebm");
    s.store_class_end();
  }
}

thumbnailFormatWebp::thumbnailFormatWebp() {
}

const std::int32_t thumbnailFormatWebp::ID;

void thumbnailFormatWebp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatWebp");
    s.store_class_end();
  }
}

topChatCategoryUsers::topChatCategoryUsers() {
}

const std::int32_t topChatCategoryUsers::ID;

void topChatCategoryUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryUsers");
    s.store_class_end();
  }
}

topChatCategoryBots::topChatCategoryBots() {
}

const std::int32_t topChatCategoryBots::ID;

void topChatCategoryBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryBots");
    s.store_class_end();
  }
}

topChatCategoryGroups::topChatCategoryGroups() {
}

const std::int32_t topChatCategoryGroups::ID;

void topChatCategoryGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryGroups");
    s.store_class_end();
  }
}

topChatCategoryChannels::topChatCategoryChannels() {
}

const std::int32_t topChatCategoryChannels::ID;

void topChatCategoryChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryChannels");
    s.store_class_end();
  }
}

topChatCategoryInlineBots::topChatCategoryInlineBots() {
}

const std::int32_t topChatCategoryInlineBots::ID;

void topChatCategoryInlineBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryInlineBots");
    s.store_class_end();
  }
}

topChatCategoryCalls::topChatCategoryCalls() {
}

const std::int32_t topChatCategoryCalls::ID;

void topChatCategoryCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryCalls");
    s.store_class_end();
  }
}

topChatCategoryForwardChats::topChatCategoryForwardChats() {
}

const std::int32_t topChatCategoryForwardChats::ID;

void topChatCategoryForwardChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryForwardChats");
    s.store_class_end();
  }
}

unreadReaction::unreadReaction()
  : reaction_()
  , sender_id_()
  , is_big_()
{}

unreadReaction::unreadReaction(string const &reaction_, object_ptr<MessageSender> &&sender_id_, bool is_big_)
  : reaction_(reaction_)
  , sender_id_(std::move(sender_id_))
  , is_big_(is_big_)
{}

const std::int32_t unreadReaction::ID;

void unreadReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unreadReaction");
    s.store_field("reaction", reaction_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("is_big", is_big_);
    s.store_class_end();
  }
}

updateAuthorizationState::updateAuthorizationState()
  : authorization_state_()
{}

updateAuthorizationState::updateAuthorizationState(object_ptr<AuthorizationState> &&authorization_state_)
  : authorization_state_(std::move(authorization_state_))
{}

const std::int32_t updateAuthorizationState::ID;

void updateAuthorizationState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAuthorizationState");
    s.store_object_field("authorization_state", static_cast<const BaseObject *>(authorization_state_.get()));
    s.store_class_end();
  }
}

updateNewMessage::updateNewMessage()
  : message_()
{}

updateNewMessage::updateNewMessage(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t updateNewMessage::ID;

void updateNewMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateMessageSendAcknowledged::updateMessageSendAcknowledged()
  : chat_id_()
  , message_id_()
{}

updateMessageSendAcknowledged::updateMessageSendAcknowledged(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t updateMessageSendAcknowledged::ID;

void updateMessageSendAcknowledged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageSendAcknowledged");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

updateMessageSendSucceeded::updateMessageSendSucceeded()
  : message_()
  , old_message_id_()
{}

updateMessageSendSucceeded::updateMessageSendSucceeded(object_ptr<message> &&message_, int53 old_message_id_)
  : message_(std::move(message_))
  , old_message_id_(old_message_id_)
{}

const std::int32_t updateMessageSendSucceeded::ID;

void updateMessageSendSucceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageSendSucceeded");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("old_message_id", old_message_id_);
    s.store_class_end();
  }
}

updateMessageSendFailed::updateMessageSendFailed()
  : message_()
  , old_message_id_()
  , error_code_()
  , error_message_()
{}

updateMessageSendFailed::updateMessageSendFailed(object_ptr<message> &&message_, int53 old_message_id_, int32 error_code_, string const &error_message_)
  : message_(std::move(message_))
  , old_message_id_(old_message_id_)
  , error_code_(error_code_)
  , error_message_(error_message_)
{}

const std::int32_t updateMessageSendFailed::ID;

void updateMessageSendFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageSendFailed");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("old_message_id", old_message_id_);
    s.store_field("error_code", error_code_);
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

updateMessageContent::updateMessageContent()
  : chat_id_()
  , message_id_()
  , new_content_()
{}

updateMessageContent::updateMessageContent(int53 chat_id_, int53 message_id_, object_ptr<MessageContent> &&new_content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , new_content_(std::move(new_content_))
{}

const std::int32_t updateMessageContent::ID;

void updateMessageContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("new_content", static_cast<const BaseObject *>(new_content_.get()));
    s.store_class_end();
  }
}

updateMessageEdited::updateMessageEdited()
  : chat_id_()
  , message_id_()
  , edit_date_()
  , reply_markup_()
{}

updateMessageEdited::updateMessageEdited(int53 chat_id_, int53 message_id_, int32 edit_date_, object_ptr<ReplyMarkup> &&reply_markup_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , edit_date_(edit_date_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t updateMessageEdited::ID;

void updateMessageEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageEdited");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("edit_date", edit_date_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

updateMessageIsPinned::updateMessageIsPinned()
  : chat_id_()
  , message_id_()
  , is_pinned_()
{}

updateMessageIsPinned::updateMessageIsPinned(int53 chat_id_, int53 message_id_, bool is_pinned_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t updateMessageIsPinned::ID;

void updateMessageIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageIsPinned");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

updateMessageInteractionInfo::updateMessageInteractionInfo()
  : chat_id_()
  , message_id_()
  , interaction_info_()
{}

updateMessageInteractionInfo::updateMessageInteractionInfo(int53 chat_id_, int53 message_id_, object_ptr<messageInteractionInfo> &&interaction_info_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , interaction_info_(std::move(interaction_info_))
{}

const std::int32_t updateMessageInteractionInfo::ID;

void updateMessageInteractionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageInteractionInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("interaction_info", static_cast<const BaseObject *>(interaction_info_.get()));
    s.store_class_end();
  }
}

updateMessageContentOpened::updateMessageContentOpened()
  : chat_id_()
  , message_id_()
{}

updateMessageContentOpened::updateMessageContentOpened(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t updateMessageContentOpened::ID;

void updateMessageContentOpened::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageContentOpened");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

updateMessageMentionRead::updateMessageMentionRead()
  : chat_id_()
  , message_id_()
  , unread_mention_count_()
{}

updateMessageMentionRead::updateMessageMentionRead(int53 chat_id_, int53 message_id_, int32 unread_mention_count_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , unread_mention_count_(unread_mention_count_)
{}

const std::int32_t updateMessageMentionRead::ID;

void updateMessageMentionRead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageMentionRead");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_class_end();
  }
}

updateMessageUnreadReactions::updateMessageUnreadReactions()
  : chat_id_()
  , message_id_()
  , unread_reactions_()
  , unread_reaction_count_()
{}

updateMessageUnreadReactions::updateMessageUnreadReactions(int53 chat_id_, int53 message_id_, array<object_ptr<unreadReaction>> &&unread_reactions_, int32 unread_reaction_count_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , unread_reactions_(std::move(unread_reactions_))
  , unread_reaction_count_(unread_reaction_count_)
{}

const std::int32_t updateMessageUnreadReactions::ID;

void updateMessageUnreadReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageUnreadReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("unread_reactions", unread_reactions_.size()); for (const auto &_value : unread_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_class_end();
  }
}

updateMessageLiveLocationViewed::updateMessageLiveLocationViewed()
  : chat_id_()
  , message_id_()
{}

updateMessageLiveLocationViewed::updateMessageLiveLocationViewed(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t updateMessageLiveLocationViewed::ID;

void updateMessageLiveLocationViewed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageLiveLocationViewed");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

updateNewChat::updateNewChat()
  : chat_()
{}

updateNewChat::updateNewChat(object_ptr<chat> &&chat_)
  : chat_(std::move(chat_))
{}

const std::int32_t updateNewChat::ID;

void updateNewChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewChat");
    s.store_object_field("chat", static_cast<const BaseObject *>(chat_.get()));
    s.store_class_end();
  }
}

updateChatTitle::updateChatTitle()
  : chat_id_()
  , title_()
{}

updateChatTitle::updateChatTitle(int53 chat_id_, string const &title_)
  : chat_id_(chat_id_)
  , title_(title_)
{}

const std::int32_t updateChatTitle::ID;

void updateChatTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatTitle");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

updateChatPhoto::updateChatPhoto()
  : chat_id_()
  , photo_()
{}

updateChatPhoto::updateChatPhoto(int53 chat_id_, object_ptr<chatPhotoInfo> &&photo_)
  : chat_id_(chat_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t updateChatPhoto::ID;

void updateChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPhoto");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

updateChatPermissions::updateChatPermissions()
  : chat_id_()
  , permissions_()
{}

updateChatPermissions::updateChatPermissions(int53 chat_id_, object_ptr<chatPermissions> &&permissions_)
  : chat_id_(chat_id_)
  , permissions_(std::move(permissions_))
{}

const std::int32_t updateChatPermissions::ID;

void updateChatPermissions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPermissions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_class_end();
  }
}

updateChatLastMessage::updateChatLastMessage()
  : chat_id_()
  , last_message_()
  , positions_()
{}

updateChatLastMessage::updateChatLastMessage(int53 chat_id_, object_ptr<message> &&last_message_, array<object_ptr<chatPosition>> &&positions_)
  : chat_id_(chat_id_)
  , last_message_(std::move(last_message_))
  , positions_(std::move(positions_))
{}

const std::int32_t updateChatLastMessage::ID;

void updateChatLastMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatLastMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateChatPosition::updateChatPosition()
  : chat_id_()
  , position_()
{}

updateChatPosition::updateChatPosition(int53 chat_id_, object_ptr<chatPosition> &&position_)
  : chat_id_(chat_id_)
  , position_(std::move(position_))
{}

const std::int32_t updateChatPosition::ID;

void updateChatPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPosition");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("position", static_cast<const BaseObject *>(position_.get()));
    s.store_class_end();
  }
}

updateChatReadInbox::updateChatReadInbox()
  : chat_id_()
  , last_read_inbox_message_id_()
  , unread_count_()
{}

updateChatReadInbox::updateChatReadInbox(int53 chat_id_, int53 last_read_inbox_message_id_, int32 unread_count_)
  : chat_id_(chat_id_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , unread_count_(unread_count_)
{}

const std::int32_t updateChatReadInbox::ID;

void updateChatReadInbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatReadInbox");
    s.store_field("chat_id", chat_id_);
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("unread_count", unread_count_);
    s.store_class_end();
  }
}

updateChatReadOutbox::updateChatReadOutbox()
  : chat_id_()
  , last_read_outbox_message_id_()
{}

updateChatReadOutbox::updateChatReadOutbox(int53 chat_id_, int53 last_read_outbox_message_id_)
  : chat_id_(chat_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
{}

const std::int32_t updateChatReadOutbox::ID;

void updateChatReadOutbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatReadOutbox");
    s.store_field("chat_id", chat_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_class_end();
  }
}

updateChatActionBar::updateChatActionBar()
  : chat_id_()
  , action_bar_()
{}

updateChatActionBar::updateChatActionBar(int53 chat_id_, object_ptr<ChatActionBar> &&action_bar_)
  : chat_id_(chat_id_)
  , action_bar_(std::move(action_bar_))
{}

const std::int32_t updateChatActionBar::ID;

void updateChatActionBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatActionBar");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("action_bar", static_cast<const BaseObject *>(action_bar_.get()));
    s.store_class_end();
  }
}

updateChatAvailableReactions::updateChatAvailableReactions()
  : chat_id_()
  , available_reactions_()
{}

updateChatAvailableReactions::updateChatAvailableReactions(int53 chat_id_, array<string> &&available_reactions_)
  : chat_id_(chat_id_)
  , available_reactions_(std::move(available_reactions_))
{}

const std::int32_t updateChatAvailableReactions::ID;

void updateChatAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatAvailableReactions");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("available_reactions", available_reactions_.size()); for (const auto &_value : available_reactions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateChatDraftMessage::updateChatDraftMessage()
  : chat_id_()
  , draft_message_()
  , positions_()
{}

updateChatDraftMessage::updateChatDraftMessage(int53 chat_id_, object_ptr<draftMessage> &&draft_message_, array<object_ptr<chatPosition>> &&positions_)
  : chat_id_(chat_id_)
  , draft_message_(std::move(draft_message_))
  , positions_(std::move(positions_))
{}

const std::int32_t updateChatDraftMessage::ID;

void updateChatDraftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatDraftMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateChatMessageSender::updateChatMessageSender()
  : chat_id_()
  , message_sender_id_()
{}

updateChatMessageSender::updateChatMessageSender(int53 chat_id_, object_ptr<MessageSender> &&message_sender_id_)
  : chat_id_(chat_id_)
  , message_sender_id_(std::move(message_sender_id_))
{}

const std::int32_t updateChatMessageSender::ID;

void updateChatMessageSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatMessageSender");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    s.store_class_end();
  }
}

updateChatMessageTtl::updateChatMessageTtl()
  : chat_id_()
  , message_ttl_()
{}

updateChatMessageTtl::updateChatMessageTtl(int53 chat_id_, int32 message_ttl_)
  : chat_id_(chat_id_)
  , message_ttl_(message_ttl_)
{}

const std::int32_t updateChatMessageTtl::ID;

void updateChatMessageTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatMessageTtl");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_ttl", message_ttl_);
    s.store_class_end();
  }
}

updateChatNotificationSettings::updateChatNotificationSettings()
  : chat_id_()
  , notification_settings_()
{}

updateChatNotificationSettings::updateChatNotificationSettings(int53 chat_id_, object_ptr<chatNotificationSettings> &&notification_settings_)
  : chat_id_(chat_id_)
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t updateChatNotificationSettings::ID;

void updateChatNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatNotificationSettings");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

updateChatPendingJoinRequests::updateChatPendingJoinRequests()
  : chat_id_()
  , pending_join_requests_()
{}

updateChatPendingJoinRequests::updateChatPendingJoinRequests(int53 chat_id_, object_ptr<chatJoinRequestsInfo> &&pending_join_requests_)
  : chat_id_(chat_id_)
  , pending_join_requests_(std::move(pending_join_requests_))
{}

const std::int32_t updateChatPendingJoinRequests::ID;

void updateChatPendingJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPendingJoinRequests");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("pending_join_requests", static_cast<const BaseObject *>(pending_join_requests_.get()));
    s.store_class_end();
  }
}

updateChatReplyMarkup::updateChatReplyMarkup()
  : chat_id_()
  , reply_markup_message_id_()
{}

updateChatReplyMarkup::updateChatReplyMarkup(int53 chat_id_, int53 reply_markup_message_id_)
  : chat_id_(chat_id_)
  , reply_markup_message_id_(reply_markup_message_id_)
{}

const std::int32_t updateChatReplyMarkup::ID;

void updateChatReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatReplyMarkup");
    s.store_field("chat_id", chat_id_);
    s.store_field("reply_markup_message_id", reply_markup_message_id_);
    s.store_class_end();
  }
}

updateChatTheme::updateChatTheme()
  : chat_id_()
  , theme_name_()
{}

updateChatTheme::updateChatTheme(int53 chat_id_, string const &theme_name_)
  : chat_id_(chat_id_)
  , theme_name_(theme_name_)
{}

const std::int32_t updateChatTheme::ID;

void updateChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatTheme");
    s.store_field("chat_id", chat_id_);
    s.store_field("theme_name", theme_name_);
    s.store_class_end();
  }
}

updateChatUnreadMentionCount::updateChatUnreadMentionCount()
  : chat_id_()
  , unread_mention_count_()
{}

updateChatUnreadMentionCount::updateChatUnreadMentionCount(int53 chat_id_, int32 unread_mention_count_)
  : chat_id_(chat_id_)
  , unread_mention_count_(unread_mention_count_)
{}

const std::int32_t updateChatUnreadMentionCount::ID;

void updateChatUnreadMentionCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatUnreadMentionCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_class_end();
  }
}

updateChatUnreadReactionCount::updateChatUnreadReactionCount()
  : chat_id_()
  , unread_reaction_count_()
{}

updateChatUnreadReactionCount::updateChatUnreadReactionCount(int53 chat_id_, int32 unread_reaction_count_)
  : chat_id_(chat_id_)
  , unread_reaction_count_(unread_reaction_count_)
{}

const std::int32_t updateChatUnreadReactionCount::ID;

void updateChatUnreadReactionCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatUnreadReactionCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_class_end();
  }
}

updateChatVideoChat::updateChatVideoChat()
  : chat_id_()
  , video_chat_()
{}

updateChatVideoChat::updateChatVideoChat(int53 chat_id_, object_ptr<videoChat> &&video_chat_)
  : chat_id_(chat_id_)
  , video_chat_(std::move(video_chat_))
{}

const std::int32_t updateChatVideoChat::ID;

void updateChatVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatVideoChat");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("video_chat", static_cast<const BaseObject *>(video_chat_.get()));
    s.store_class_end();
  }
}

updateChatDefaultDisableNotification::updateChatDefaultDisableNotification()
  : chat_id_()
  , default_disable_notification_()
{}

updateChatDefaultDisableNotification::updateChatDefaultDisableNotification(int53 chat_id_, bool default_disable_notification_)
  : chat_id_(chat_id_)
  , default_disable_notification_(default_disable_notification_)
{}

const std::int32_t updateChatDefaultDisableNotification::ID;

void updateChatDefaultDisableNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatDefaultDisableNotification");
    s.store_field("chat_id", chat_id_);
    s.store_field("default_disable_notification", default_disable_notification_);
    s.store_class_end();
  }
}

updateChatHasProtectedContent::updateChatHasProtectedContent()
  : chat_id_()
  , has_protected_content_()
{}

updateChatHasProtectedContent::updateChatHasProtectedContent(int53 chat_id_, bool has_protected_content_)
  : chat_id_(chat_id_)
  , has_protected_content_(has_protected_content_)
{}

const std::int32_t updateChatHasProtectedContent::ID;

void updateChatHasProtectedContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatHasProtectedContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("has_protected_content", has_protected_content_);
    s.store_class_end();
  }
}

updateChatHasScheduledMessages::updateChatHasScheduledMessages()
  : chat_id_()
  , has_scheduled_messages_()
{}

updateChatHasScheduledMessages::updateChatHasScheduledMessages(int53 chat_id_, bool has_scheduled_messages_)
  : chat_id_(chat_id_)
  , has_scheduled_messages_(has_scheduled_messages_)
{}

const std::int32_t updateChatHasScheduledMessages::ID;

void updateChatHasScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatHasScheduledMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("has_scheduled_messages", has_scheduled_messages_);
    s.store_class_end();
  }
}

updateChatIsBlocked::updateChatIsBlocked()
  : chat_id_()
  , is_blocked_()
{}

updateChatIsBlocked::updateChatIsBlocked(int53 chat_id_, bool is_blocked_)
  : chat_id_(chat_id_)
  , is_blocked_(is_blocked_)
{}

const std::int32_t updateChatIsBlocked::ID;

void updateChatIsBlocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatIsBlocked");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_blocked", is_blocked_);
    s.store_class_end();
  }
}

updateChatIsMarkedAsUnread::updateChatIsMarkedAsUnread()
  : chat_id_()
  , is_marked_as_unread_()
{}

updateChatIsMarkedAsUnread::updateChatIsMarkedAsUnread(int53 chat_id_, bool is_marked_as_unread_)
  : chat_id_(chat_id_)
  , is_marked_as_unread_(is_marked_as_unread_)
{}

const std::int32_t updateChatIsMarkedAsUnread::ID;

void updateChatIsMarkedAsUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatIsMarkedAsUnread");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_class_end();
  }
}

updateChatFilters::updateChatFilters()
  : chat_filters_()
{}

updateChatFilters::updateChatFilters(array<object_ptr<chatFilterInfo>> &&chat_filters_)
  : chat_filters_(std::move(chat_filters_))
{}

const std::int32_t updateChatFilters::ID;

void updateChatFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatFilters");
    { s.store_vector_begin("chat_filters", chat_filters_.size()); for (const auto &_value : chat_filters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateChatOnlineMemberCount::updateChatOnlineMemberCount()
  : chat_id_()
  , online_member_count_()
{}

updateChatOnlineMemberCount::updateChatOnlineMemberCount(int53 chat_id_, int32 online_member_count_)
  : chat_id_(chat_id_)
  , online_member_count_(online_member_count_)
{}

const std::int32_t updateChatOnlineMemberCount::ID;

void updateChatOnlineMemberCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatOnlineMemberCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("online_member_count", online_member_count_);
    s.store_class_end();
  }
}

updateScopeNotificationSettings::updateScopeNotificationSettings()
  : scope_()
  , notification_settings_()
{}

updateScopeNotificationSettings::updateScopeNotificationSettings(object_ptr<NotificationSettingsScope> &&scope_, object_ptr<scopeNotificationSettings> &&notification_settings_)
  : scope_(std::move(scope_))
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t updateScopeNotificationSettings::ID;

void updateScopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateScopeNotificationSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

updateNotification::updateNotification()
  : notification_group_id_()
  , notification_()
{}

updateNotification::updateNotification(int32 notification_group_id_, object_ptr<notification> &&notification_)
  : notification_group_id_(notification_group_id_)
  , notification_(std::move(notification_))
{}

const std::int32_t updateNotification::ID;

void updateNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNotification");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_object_field("notification", static_cast<const BaseObject *>(notification_.get()));
    s.store_class_end();
  }
}

updateNotificationGroup::updateNotificationGroup()
  : notification_group_id_()
  , type_()
  , chat_id_()
  , notification_settings_chat_id_()
  , notification_sound_id_()
  , total_count_()
  , added_notifications_()
  , removed_notification_ids_()
{}

updateNotificationGroup::updateNotificationGroup(int32 notification_group_id_, object_ptr<NotificationGroupType> &&type_, int53 chat_id_, int53 notification_settings_chat_id_, int64 notification_sound_id_, int32 total_count_, array<object_ptr<notification>> &&added_notifications_, array<int32> &&removed_notification_ids_)
  : notification_group_id_(notification_group_id_)
  , type_(std::move(type_))
  , chat_id_(chat_id_)
  , notification_settings_chat_id_(notification_settings_chat_id_)
  , notification_sound_id_(notification_sound_id_)
  , total_count_(total_count_)
  , added_notifications_(std::move(added_notifications_))
  , removed_notification_ids_(std::move(removed_notification_ids_))
{}

const std::int32_t updateNotificationGroup::ID;

void updateNotificationGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNotificationGroup");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_field("notification_settings_chat_id", notification_settings_chat_id_);
    s.store_field("notification_sound_id", notification_sound_id_);
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("added_notifications", added_notifications_.size()); for (const auto &_value : added_notifications_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("removed_notification_ids", removed_notification_ids_.size()); for (const auto &_value : removed_notification_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateActiveNotifications::updateActiveNotifications()
  : groups_()
{}

updateActiveNotifications::updateActiveNotifications(array<object_ptr<notificationGroup>> &&groups_)
  : groups_(std::move(groups_))
{}

const std::int32_t updateActiveNotifications::ID;

void updateActiveNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateActiveNotifications");
    { s.store_vector_begin("groups", groups_.size()); for (const auto &_value : groups_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateHavePendingNotifications::updateHavePendingNotifications()
  : have_delayed_notifications_()
  , have_unreceived_notifications_()
{}

updateHavePendingNotifications::updateHavePendingNotifications(bool have_delayed_notifications_, bool have_unreceived_notifications_)
  : have_delayed_notifications_(have_delayed_notifications_)
  , have_unreceived_notifications_(have_unreceived_notifications_)
{}

const std::int32_t updateHavePendingNotifications::ID;

void updateHavePendingNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateHavePendingNotifications");
    s.store_field("have_delayed_notifications", have_delayed_notifications_);
    s.store_field("have_unreceived_notifications", have_unreceived_notifications_);
    s.store_class_end();
  }
}

updateDeleteMessages::updateDeleteMessages()
  : chat_id_()
  , message_ids_()
  , is_permanent_()
  , from_cache_()
{}

updateDeleteMessages::updateDeleteMessages(int53 chat_id_, array<int53> &&message_ids_, bool is_permanent_, bool from_cache_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
  , is_permanent_(is_permanent_)
  , from_cache_(from_cache_)
{}

const std::int32_t updateDeleteMessages::ID;

void updateDeleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("is_permanent", is_permanent_);
    s.store_field("from_cache", from_cache_);
    s.store_class_end();
  }
}

updateChatAction::updateChatAction()
  : chat_id_()
  , message_thread_id_()
  , sender_id_()
  , action_()
{}

updateChatAction::updateChatAction(int53 chat_id_, int53 message_thread_id_, object_ptr<MessageSender> &&sender_id_, object_ptr<ChatAction> &&action_)
  : chat_id_(chat_id_)
  , message_thread_id_(message_thread_id_)
  , sender_id_(std::move(sender_id_))
  , action_(std::move(action_))
{}

const std::int32_t updateChatAction::ID;

void updateChatAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatAction");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_thread_id", message_thread_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

updateUserStatus::updateUserStatus()
  : user_id_()
  , status_()
{}

updateUserStatus::updateUserStatus(int53 user_id_, object_ptr<UserStatus> &&status_)
  : user_id_(user_id_)
  , status_(std::move(status_))
{}

const std::int32_t updateUserStatus::ID;

void updateUserStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserStatus");
    s.store_field("user_id", user_id_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

updateUser::updateUser()
  : user_()
{}

updateUser::updateUser(object_ptr<user> &&user_)
  : user_(std::move(user_))
{}

const std::int32_t updateUser::ID;

void updateUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUser");
    s.store_object_field("user", static_cast<const BaseObject *>(user_.get()));
    s.store_class_end();
  }
}

updateBasicGroup::updateBasicGroup()
  : basic_group_()
{}

updateBasicGroup::updateBasicGroup(object_ptr<basicGroup> &&basic_group_)
  : basic_group_(std::move(basic_group_))
{}

const std::int32_t updateBasicGroup::ID;

void updateBasicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBasicGroup");
    s.store_object_field("basic_group", static_cast<const BaseObject *>(basic_group_.get()));
    s.store_class_end();
  }
}

updateSupergroup::updateSupergroup()
  : supergroup_()
{}

updateSupergroup::updateSupergroup(object_ptr<supergroup> &&supergroup_)
  : supergroup_(std::move(supergroup_))
{}

const std::int32_t updateSupergroup::ID;

void updateSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSupergroup");
    s.store_object_field("supergroup", static_cast<const BaseObject *>(supergroup_.get()));
    s.store_class_end();
  }
}

updateSecretChat::updateSecretChat()
  : secret_chat_()
{}

updateSecretChat::updateSecretChat(object_ptr<secretChat> &&secret_chat_)
  : secret_chat_(std::move(secret_chat_))
{}

const std::int32_t updateSecretChat::ID;

void updateSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSecretChat");
    s.store_object_field("secret_chat", static_cast<const BaseObject *>(secret_chat_.get()));
    s.store_class_end();
  }
}

updateUserFullInfo::updateUserFullInfo()
  : user_id_()
  , user_full_info_()
{}

updateUserFullInfo::updateUserFullInfo(int53 user_id_, object_ptr<userFullInfo> &&user_full_info_)
  : user_id_(user_id_)
  , user_full_info_(std::move(user_full_info_))
{}

const std::int32_t updateUserFullInfo::ID;

void updateUserFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserFullInfo");
    s.store_field("user_id", user_id_);
    s.store_object_field("user_full_info", static_cast<const BaseObject *>(user_full_info_.get()));
    s.store_class_end();
  }
}

updateBasicGroupFullInfo::updateBasicGroupFullInfo()
  : basic_group_id_()
  , basic_group_full_info_()
{}

updateBasicGroupFullInfo::updateBasicGroupFullInfo(int53 basic_group_id_, object_ptr<basicGroupFullInfo> &&basic_group_full_info_)
  : basic_group_id_(basic_group_id_)
  , basic_group_full_info_(std::move(basic_group_full_info_))
{}

const std::int32_t updateBasicGroupFullInfo::ID;

void updateBasicGroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBasicGroupFullInfo");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_object_field("basic_group_full_info", static_cast<const BaseObject *>(basic_group_full_info_.get()));
    s.store_class_end();
  }
}

updateSupergroupFullInfo::updateSupergroupFullInfo()
  : supergroup_id_()
  , supergroup_full_info_()
{}

updateSupergroupFullInfo::updateSupergroupFullInfo(int53 supergroup_id_, object_ptr<supergroupFullInfo> &&supergroup_full_info_)
  : supergroup_id_(supergroup_id_)
  , supergroup_full_info_(std::move(supergroup_full_info_))
{}

const std::int32_t updateSupergroupFullInfo::ID;

void updateSupergroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSupergroupFullInfo");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_object_field("supergroup_full_info", static_cast<const BaseObject *>(supergroup_full_info_.get()));
    s.store_class_end();
  }
}

updateServiceNotification::updateServiceNotification()
  : type_()
  , content_()
{}

updateServiceNotification::updateServiceNotification(string const &type_, object_ptr<MessageContent> &&content_)
  : type_(type_)
  , content_(std::move(content_))
{}

const std::int32_t updateServiceNotification::ID;

void updateServiceNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateServiceNotification");
    s.store_field("type", type_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

updateFile::updateFile()
  : file_()
{}

updateFile::updateFile(object_ptr<file> &&file_)
  : file_(std::move(file_))
{}

const std::int32_t updateFile::ID;

void updateFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFile");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

updateFileGenerationStart::updateFileGenerationStart()
  : generation_id_()
  , original_path_()
  , destination_path_()
  , conversion_()
{}

updateFileGenerationStart::updateFileGenerationStart(int64 generation_id_, string const &original_path_, string const &destination_path_, string const &conversion_)
  : generation_id_(generation_id_)
  , original_path_(original_path_)
  , destination_path_(destination_path_)
  , conversion_(conversion_)
{}

const std::int32_t updateFileGenerationStart::ID;

void updateFileGenerationStart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileGenerationStart");
    s.store_field("generation_id", generation_id_);
    s.store_field("original_path", original_path_);
    s.store_field("destination_path", destination_path_);
    s.store_field("conversion", conversion_);
    s.store_class_end();
  }
}

updateFileGenerationStop::updateFileGenerationStop()
  : generation_id_()
{}

updateFileGenerationStop::updateFileGenerationStop(int64 generation_id_)
  : generation_id_(generation_id_)
{}

const std::int32_t updateFileGenerationStop::ID;

void updateFileGenerationStop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileGenerationStop");
    s.store_field("generation_id", generation_id_);
    s.store_class_end();
  }
}

updateFileDownloads::updateFileDownloads()
  : total_size_()
  , total_count_()
  , downloaded_size_()
{}

updateFileDownloads::updateFileDownloads(int53 total_size_, int32 total_count_, int53 downloaded_size_)
  : total_size_(total_size_)
  , total_count_(total_count_)
  , downloaded_size_(downloaded_size_)
{}

const std::int32_t updateFileDownloads::ID;

void updateFileDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileDownloads");
    s.store_field("total_size", total_size_);
    s.store_field("total_count", total_count_);
    s.store_field("downloaded_size", downloaded_size_);
    s.store_class_end();
  }
}

updateFileAddedToDownloads::updateFileAddedToDownloads()
  : file_download_()
  , counts_()
{}

updateFileAddedToDownloads::updateFileAddedToDownloads(object_ptr<fileDownload> &&file_download_, object_ptr<downloadedFileCounts> &&counts_)
  : file_download_(std::move(file_download_))
  , counts_(std::move(counts_))
{}

const std::int32_t updateFileAddedToDownloads::ID;

void updateFileAddedToDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileAddedToDownloads");
    s.store_object_field("file_download", static_cast<const BaseObject *>(file_download_.get()));
    s.store_object_field("counts", static_cast<const BaseObject *>(counts_.get()));
    s.store_class_end();
  }
}

updateFileDownload::updateFileDownload()
  : file_id_()
  , complete_date_()
  , is_paused_()
  , counts_()
{}

updateFileDownload::updateFileDownload(int32 file_id_, int32 complete_date_, bool is_paused_, object_ptr<downloadedFileCounts> &&counts_)
  : file_id_(file_id_)
  , complete_date_(complete_date_)
  , is_paused_(is_paused_)
  , counts_(std::move(counts_))
{}

const std::int32_t updateFileDownload::ID;

void updateFileDownload::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileDownload");
    s.store_field("file_id", file_id_);
    s.store_field("complete_date", complete_date_);
    s.store_field("is_paused", is_paused_);
    s.store_object_field("counts", static_cast<const BaseObject *>(counts_.get()));
    s.store_class_end();
  }
}

updateFileRemovedFromDownloads::updateFileRemovedFromDownloads()
  : file_id_()
  , counts_()
{}

updateFileRemovedFromDownloads::updateFileRemovedFromDownloads(int32 file_id_, object_ptr<downloadedFileCounts> &&counts_)
  : file_id_(file_id_)
  , counts_(std::move(counts_))
{}

const std::int32_t updateFileRemovedFromDownloads::ID;

void updateFileRemovedFromDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileRemovedFromDownloads");
    s.store_field("file_id", file_id_);
    s.store_object_field("counts", static_cast<const BaseObject *>(counts_.get()));
    s.store_class_end();
  }
}

updateCall::updateCall()
  : call_()
{}

updateCall::updateCall(object_ptr<call> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t updateCall::ID;

void updateCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

updateGroupCall::updateGroupCall()
  : group_call_()
{}

updateGroupCall::updateGroupCall(object_ptr<groupCall> &&group_call_)
  : group_call_(std::move(group_call_))
{}

const std::int32_t updateGroupCall::ID;

void updateGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCall");
    s.store_object_field("group_call", static_cast<const BaseObject *>(group_call_.get()));
    s.store_class_end();
  }
}

updateGroupCallParticipant::updateGroupCallParticipant()
  : group_call_id_()
  , participant_()
{}

updateGroupCallParticipant::updateGroupCallParticipant(int32 group_call_id_, object_ptr<groupCallParticipant> &&participant_)
  : group_call_id_(group_call_id_)
  , participant_(std::move(participant_))
{}

const std::int32_t updateGroupCallParticipant::ID;

void updateGroupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallParticipant");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

updateNewCallSignalingData::updateNewCallSignalingData()
  : call_id_()
  , data_()
{}

updateNewCallSignalingData::updateNewCallSignalingData(int32 call_id_, bytes const &data_)
  : call_id_(call_id_)
  , data_(std::move(data_))
{}

const std::int32_t updateNewCallSignalingData::ID;

void updateNewCallSignalingData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCallSignalingData");
    s.store_field("call_id", call_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

updateUserPrivacySettingRules::updateUserPrivacySettingRules()
  : setting_()
  , rules_()
{}

updateUserPrivacySettingRules::updateUserPrivacySettingRules(object_ptr<UserPrivacySetting> &&setting_, object_ptr<userPrivacySettingRules> &&rules_)
  : setting_(std::move(setting_))
  , rules_(std::move(rules_))
{}

const std::int32_t updateUserPrivacySettingRules::ID;

void updateUserPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserPrivacySettingRules");
    s.store_object_field("setting", static_cast<const BaseObject *>(setting_.get()));
    s.store_object_field("rules", static_cast<const BaseObject *>(rules_.get()));
    s.store_class_end();
  }
}

updateUnreadMessageCount::updateUnreadMessageCount()
  : chat_list_()
  , unread_count_()
  , unread_unmuted_count_()
{}

updateUnreadMessageCount::updateUnreadMessageCount(object_ptr<ChatList> &&chat_list_, int32 unread_count_, int32 unread_unmuted_count_)
  : chat_list_(std::move(chat_list_))
  , unread_count_(unread_count_)
  , unread_unmuted_count_(unread_unmuted_count_)
{}

const std::int32_t updateUnreadMessageCount::ID;

void updateUnreadMessageCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUnreadMessageCount");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_unmuted_count", unread_unmuted_count_);
    s.store_class_end();
  }
}

updateUnreadChatCount::updateUnreadChatCount()
  : chat_list_()
  , total_count_()
  , unread_count_()
  , unread_unmuted_count_()
  , marked_as_unread_count_()
  , marked_as_unread_unmuted_count_()
{}

updateUnreadChatCount::updateUnreadChatCount(object_ptr<ChatList> &&chat_list_, int32 total_count_, int32 unread_count_, int32 unread_unmuted_count_, int32 marked_as_unread_count_, int32 marked_as_unread_unmuted_count_)
  : chat_list_(std::move(chat_list_))
  , total_count_(total_count_)
  , unread_count_(unread_count_)
  , unread_unmuted_count_(unread_unmuted_count_)
  , marked_as_unread_count_(marked_as_unread_count_)
  , marked_as_unread_unmuted_count_(marked_as_unread_unmuted_count_)
{}

const std::int32_t updateUnreadChatCount::ID;

void updateUnreadChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUnreadChatCount");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("total_count", total_count_);
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_unmuted_count", unread_unmuted_count_);
    s.store_field("marked_as_unread_count", marked_as_unread_count_);
    s.store_field("marked_as_unread_unmuted_count", marked_as_unread_unmuted_count_);
    s.store_class_end();
  }
}

updateOption::updateOption()
  : name_()
  , value_()
{}

updateOption::updateOption(string const &name_, object_ptr<OptionValue> &&value_)
  : name_(name_)
  , value_(std::move(value_))
{}

const std::int32_t updateOption::ID;

void updateOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateOption");
    s.store_field("name", name_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

updateStickerSet::updateStickerSet()
  : sticker_set_()
{}

updateStickerSet::updateStickerSet(object_ptr<stickerSet> &&sticker_set_)
  : sticker_set_(std::move(sticker_set_))
{}

const std::int32_t updateStickerSet::ID;

void updateStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStickerSet");
    s.store_object_field("sticker_set", static_cast<const BaseObject *>(sticker_set_.get()));
    s.store_class_end();
  }
}

updateInstalledStickerSets::updateInstalledStickerSets()
  : is_masks_()
  , sticker_set_ids_()
{}

updateInstalledStickerSets::updateInstalledStickerSets(bool is_masks_, array<int64> &&sticker_set_ids_)
  : is_masks_(is_masks_)
  , sticker_set_ids_(std::move(sticker_set_ids_))
{}

const std::int32_t updateInstalledStickerSets::ID;

void updateInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateInstalledStickerSets");
    s.store_field("is_masks", is_masks_);
    { s.store_vector_begin("sticker_set_ids", sticker_set_ids_.size()); for (const auto &_value : sticker_set_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateTrendingStickerSets::updateTrendingStickerSets()
  : sticker_sets_()
{}

updateTrendingStickerSets::updateTrendingStickerSets(object_ptr<stickerSets> &&sticker_sets_)
  : sticker_sets_(std::move(sticker_sets_))
{}

const std::int32_t updateTrendingStickerSets::ID;

void updateTrendingStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTrendingStickerSets");
    s.store_object_field("sticker_sets", static_cast<const BaseObject *>(sticker_sets_.get()));
    s.store_class_end();
  }
}

updateRecentStickers::updateRecentStickers()
  : is_attached_()
  , sticker_ids_()
{}

updateRecentStickers::updateRecentStickers(bool is_attached_, array<int32> &&sticker_ids_)
  : is_attached_(is_attached_)
  , sticker_ids_(std::move(sticker_ids_))
{}

const std::int32_t updateRecentStickers::ID;

void updateRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateRecentStickers");
    s.store_field("is_attached", is_attached_);
    { s.store_vector_begin("sticker_ids", sticker_ids_.size()); for (const auto &_value : sticker_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateFavoriteStickers::updateFavoriteStickers()
  : sticker_ids_()
{}

updateFavoriteStickers::updateFavoriteStickers(array<int32> &&sticker_ids_)
  : sticker_ids_(std::move(sticker_ids_))
{}

const std::int32_t updateFavoriteStickers::ID;

void updateFavoriteStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFavoriteStickers");
    { s.store_vector_begin("sticker_ids", sticker_ids_.size()); for (const auto &_value : sticker_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSavedAnimations::updateSavedAnimations()
  : animation_ids_()
{}

updateSavedAnimations::updateSavedAnimations(array<int32> &&animation_ids_)
  : animation_ids_(std::move(animation_ids_))
{}

const std::int32_t updateSavedAnimations::ID;

void updateSavedAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedAnimations");
    { s.store_vector_begin("animation_ids", animation_ids_.size()); for (const auto &_value : animation_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSavedNotificationSounds::updateSavedNotificationSounds()
  : notification_sound_ids_()
{}

updateSavedNotificationSounds::updateSavedNotificationSounds(array<int64> &&notification_sound_ids_)
  : notification_sound_ids_(std::move(notification_sound_ids_))
{}

const std::int32_t updateSavedNotificationSounds::ID;

void updateSavedNotificationSounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedNotificationSounds");
    { s.store_vector_begin("notification_sound_ids", notification_sound_ids_.size()); for (const auto &_value : notification_sound_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSelectedBackground::updateSelectedBackground()
  : for_dark_theme_()
  , background_()
{}

updateSelectedBackground::updateSelectedBackground(bool for_dark_theme_, object_ptr<background> &&background_)
  : for_dark_theme_(for_dark_theme_)
  , background_(std::move(background_))
{}

const std::int32_t updateSelectedBackground::ID;

void updateSelectedBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSelectedBackground");
    s.store_field("for_dark_theme", for_dark_theme_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_class_end();
  }
}

updateChatThemes::updateChatThemes()
  : chat_themes_()
{}

updateChatThemes::updateChatThemes(array<object_ptr<chatTheme>> &&chat_themes_)
  : chat_themes_(std::move(chat_themes_))
{}

const std::int32_t updateChatThemes::ID;

void updateChatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatThemes");
    { s.store_vector_begin("chat_themes", chat_themes_.size()); for (const auto &_value : chat_themes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateLanguagePackStrings::updateLanguagePackStrings()
  : localization_target_()
  , language_pack_id_()
  , strings_()
{}

updateLanguagePackStrings::updateLanguagePackStrings(string const &localization_target_, string const &language_pack_id_, array<object_ptr<languagePackString>> &&strings_)
  : localization_target_(localization_target_)
  , language_pack_id_(language_pack_id_)
  , strings_(std::move(strings_))
{}

const std::int32_t updateLanguagePackStrings::ID;

void updateLanguagePackStrings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateLanguagePackStrings");
    s.store_field("localization_target", localization_target_);
    s.store_field("language_pack_id", language_pack_id_);
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateConnectionState::updateConnectionState()
  : state_()
{}

updateConnectionState::updateConnectionState(object_ptr<ConnectionState> &&state_)
  : state_(std::move(state_))
{}

const std::int32_t updateConnectionState::ID;

void updateConnectionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateConnectionState");
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

updateTermsOfService::updateTermsOfService()
  : terms_of_service_id_()
  , terms_of_service_()
{}

updateTermsOfService::updateTermsOfService(string const &terms_of_service_id_, object_ptr<termsOfService> &&terms_of_service_)
  : terms_of_service_id_(terms_of_service_id_)
  , terms_of_service_(std::move(terms_of_service_))
{}

const std::int32_t updateTermsOfService::ID;

void updateTermsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTermsOfService");
    s.store_field("terms_of_service_id", terms_of_service_id_);
    s.store_object_field("terms_of_service", static_cast<const BaseObject *>(terms_of_service_.get()));
    s.store_class_end();
  }
}

updateUsersNearby::updateUsersNearby()
  : users_nearby_()
{}

updateUsersNearby::updateUsersNearby(array<object_ptr<chatNearby>> &&users_nearby_)
  : users_nearby_(std::move(users_nearby_))
{}

const std::int32_t updateUsersNearby::ID;

void updateUsersNearby::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUsersNearby");
    { s.store_vector_begin("users_nearby", users_nearby_.size()); for (const auto &_value : users_nearby_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateAttachmentMenuBots::updateAttachmentMenuBots()
  : bots_()
{}

updateAttachmentMenuBots::updateAttachmentMenuBots(array<object_ptr<attachmentMenuBot>> &&bots_)
  : bots_(std::move(bots_))
{}

const std::int32_t updateAttachmentMenuBots::ID;

void updateAttachmentMenuBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAttachmentMenuBots");
    { s.store_vector_begin("bots", bots_.size()); for (const auto &_value : bots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateWebAppMessageSent::updateWebAppMessageSent()
  : web_app_launch_id_()
{}

updateWebAppMessageSent::updateWebAppMessageSent(int64 web_app_launch_id_)
  : web_app_launch_id_(web_app_launch_id_)
{}

const std::int32_t updateWebAppMessageSent::ID;

void updateWebAppMessageSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebAppMessageSent");
    s.store_field("web_app_launch_id", web_app_launch_id_);
    s.store_class_end();
  }
}

updateReactions::updateReactions()
  : reactions_()
{}

updateReactions::updateReactions(array<object_ptr<reaction>> &&reactions_)
  : reactions_(std::move(reactions_))
{}

const std::int32_t updateReactions::ID;

void updateReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReactions");
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateDiceEmojis::updateDiceEmojis()
  : emojis_()
{}

updateDiceEmojis::updateDiceEmojis(array<string> &&emojis_)
  : emojis_(std::move(emojis_))
{}

const std::int32_t updateDiceEmojis::ID;

void updateDiceEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDiceEmojis");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateAnimatedEmojiMessageClicked::updateAnimatedEmojiMessageClicked()
  : chat_id_()
  , message_id_()
  , sticker_()
{}

updateAnimatedEmojiMessageClicked::updateAnimatedEmojiMessageClicked(int53 chat_id_, int53 message_id_, object_ptr<sticker> &&sticker_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t updateAnimatedEmojiMessageClicked::ID;

void updateAnimatedEmojiMessageClicked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAnimatedEmojiMessageClicked");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

updateAnimationSearchParameters::updateAnimationSearchParameters()
  : provider_()
  , emojis_()
{}

updateAnimationSearchParameters::updateAnimationSearchParameters(string const &provider_, array<string> &&emojis_)
  : provider_(provider_)
  , emojis_(std::move(emojis_))
{}

const std::int32_t updateAnimationSearchParameters::ID;

void updateAnimationSearchParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAnimationSearchParameters");
    s.store_field("provider", provider_);
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSuggestedActions::updateSuggestedActions()
  : added_actions_()
  , removed_actions_()
{}

updateSuggestedActions::updateSuggestedActions(array<object_ptr<SuggestedAction>> &&added_actions_, array<object_ptr<SuggestedAction>> &&removed_actions_)
  : added_actions_(std::move(added_actions_))
  , removed_actions_(std::move(removed_actions_))
{}

const std::int32_t updateSuggestedActions::ID;

void updateSuggestedActions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSuggestedActions");
    { s.store_vector_begin("added_actions", added_actions_.size()); for (const auto &_value : added_actions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("removed_actions", removed_actions_.size()); for (const auto &_value : removed_actions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateNewInlineQuery::updateNewInlineQuery()
  : id_()
  , sender_user_id_()
  , user_location_()
  , chat_type_()
  , query_()
  , offset_()
{}

updateNewInlineQuery::updateNewInlineQuery(int64 id_, int53 sender_user_id_, object_ptr<location> &&user_location_, object_ptr<ChatType> &&chat_type_, string const &query_, string const &offset_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , user_location_(std::move(user_location_))
  , chat_type_(std::move(chat_type_))
  , query_(query_)
  , offset_(offset_)
{}

const std::int32_t updateNewInlineQuery::ID;

void updateNewInlineQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewInlineQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_object_field("user_location", static_cast<const BaseObject *>(user_location_.get()));
    s.store_object_field("chat_type", static_cast<const BaseObject *>(chat_type_.get()));
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

updateNewChosenInlineResult::updateNewChosenInlineResult()
  : sender_user_id_()
  , user_location_()
  , query_()
  , result_id_()
  , inline_message_id_()
{}

updateNewChosenInlineResult::updateNewChosenInlineResult(int53 sender_user_id_, object_ptr<location> &&user_location_, string const &query_, string const &result_id_, string const &inline_message_id_)
  : sender_user_id_(sender_user_id_)
  , user_location_(std::move(user_location_))
  , query_(query_)
  , result_id_(result_id_)
  , inline_message_id_(inline_message_id_)
{}

const std::int32_t updateNewChosenInlineResult::ID;

void updateNewChosenInlineResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewChosenInlineResult");
    s.store_field("sender_user_id", sender_user_id_);
    s.store_object_field("user_location", static_cast<const BaseObject *>(user_location_.get()));
    s.store_field("query", query_);
    s.store_field("result_id", result_id_);
    s.store_field("inline_message_id", inline_message_id_);
    s.store_class_end();
  }
}

updateNewCallbackQuery::updateNewCallbackQuery()
  : id_()
  , sender_user_id_()
  , chat_id_()
  , message_id_()
  , chat_instance_()
  , payload_()
{}

updateNewCallbackQuery::updateNewCallbackQuery(int64 id_, int53 sender_user_id_, int53 chat_id_, int53 message_id_, int64 chat_instance_, object_ptr<CallbackQueryPayload> &&payload_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , chat_instance_(chat_instance_)
  , payload_(std::move(payload_))
{}

const std::int32_t updateNewCallbackQuery::ID;

void updateNewCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCallbackQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("chat_instance", chat_instance_);
    s.store_object_field("payload", static_cast<const BaseObject *>(payload_.get()));
    s.store_class_end();
  }
}

updateNewInlineCallbackQuery::updateNewInlineCallbackQuery()
  : id_()
  , sender_user_id_()
  , inline_message_id_()
  , chat_instance_()
  , payload_()
{}

updateNewInlineCallbackQuery::updateNewInlineCallbackQuery(int64 id_, int53 sender_user_id_, string const &inline_message_id_, int64 chat_instance_, object_ptr<CallbackQueryPayload> &&payload_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , inline_message_id_(inline_message_id_)
  , chat_instance_(chat_instance_)
  , payload_(std::move(payload_))
{}

const std::int32_t updateNewInlineCallbackQuery::ID;

void updateNewInlineCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewInlineCallbackQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("inline_message_id", inline_message_id_);
    s.store_field("chat_instance", chat_instance_);
    s.store_object_field("payload", static_cast<const BaseObject *>(payload_.get()));
    s.store_class_end();
  }
}

updateNewShippingQuery::updateNewShippingQuery()
  : id_()
  , sender_user_id_()
  , invoice_payload_()
  , shipping_address_()
{}

updateNewShippingQuery::updateNewShippingQuery(int64 id_, int53 sender_user_id_, string const &invoice_payload_, object_ptr<address> &&shipping_address_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , invoice_payload_(invoice_payload_)
  , shipping_address_(std::move(shipping_address_))
{}

const std::int32_t updateNewShippingQuery::ID;

void updateNewShippingQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewShippingQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("invoice_payload", invoice_payload_);
    s.store_object_field("shipping_address", static_cast<const BaseObject *>(shipping_address_.get()));
    s.store_class_end();
  }
}

updateNewPreCheckoutQuery::updateNewPreCheckoutQuery()
  : id_()
  , sender_user_id_()
  , currency_()
  , total_amount_()
  , invoice_payload_()
  , shipping_option_id_()
  , order_info_()
{}

updateNewPreCheckoutQuery::updateNewPreCheckoutQuery(int64 id_, int53 sender_user_id_, string const &currency_, int53 total_amount_, bytes const &invoice_payload_, string const &shipping_option_id_, object_ptr<orderInfo> &&order_info_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , currency_(currency_)
  , total_amount_(total_amount_)
  , invoice_payload_(std::move(invoice_payload_))
  , shipping_option_id_(shipping_option_id_)
  , order_info_(std::move(order_info_))
{}

const std::int32_t updateNewPreCheckoutQuery::ID;

void updateNewPreCheckoutQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewPreCheckoutQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_field("shipping_option_id", shipping_option_id_);
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_class_end();
  }
}

updateNewCustomEvent::updateNewCustomEvent()
  : event_()
{}

updateNewCustomEvent::updateNewCustomEvent(string const &event_)
  : event_(event_)
{}

const std::int32_t updateNewCustomEvent::ID;

void updateNewCustomEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCustomEvent");
    s.store_field("event", event_);
    s.store_class_end();
  }
}

updateNewCustomQuery::updateNewCustomQuery()
  : id_()
  , data_()
  , timeout_()
{}

updateNewCustomQuery::updateNewCustomQuery(int64 id_, string const &data_, int32 timeout_)
  : id_(id_)
  , data_(data_)
  , timeout_(timeout_)
{}

const std::int32_t updateNewCustomQuery::ID;

void updateNewCustomQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCustomQuery");
    s.store_field("id", id_);
    s.store_field("data", data_);
    s.store_field("timeout", timeout_);
    s.store_class_end();
  }
}

updatePoll::updatePoll()
  : poll_()
{}

updatePoll::updatePoll(object_ptr<poll> &&poll_)
  : poll_(std::move(poll_))
{}

const std::int32_t updatePoll::ID;

void updatePoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePoll");
    s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get()));
    s.store_class_end();
  }
}

updatePollAnswer::updatePollAnswer()
  : poll_id_()
  , user_id_()
  , option_ids_()
{}

updatePollAnswer::updatePollAnswer(int64 poll_id_, int53 user_id_, array<int32> &&option_ids_)
  : poll_id_(poll_id_)
  , user_id_(user_id_)
  , option_ids_(std::move(option_ids_))
{}

const std::int32_t updatePollAnswer::ID;

void updatePollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePollAnswer");
    s.store_field("poll_id", poll_id_);
    s.store_field("user_id", user_id_);
    { s.store_vector_begin("option_ids", option_ids_.size()); for (const auto &_value : option_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateChatMember::updateChatMember()
  : chat_id_()
  , actor_user_id_()
  , date_()
  , invite_link_()
  , old_chat_member_()
  , new_chat_member_()
{}

updateChatMember::updateChatMember(int53 chat_id_, int53 actor_user_id_, int32 date_, object_ptr<chatInviteLink> &&invite_link_, object_ptr<chatMember> &&old_chat_member_, object_ptr<chatMember> &&new_chat_member_)
  : chat_id_(chat_id_)
  , actor_user_id_(actor_user_id_)
  , date_(date_)
  , invite_link_(std::move(invite_link_))
  , old_chat_member_(std::move(old_chat_member_))
  , new_chat_member_(std::move(new_chat_member_))
{}

const std::int32_t updateChatMember::ID;

void updateChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_field("actor_user_id", actor_user_id_);
    s.store_field("date", date_);
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_object_field("old_chat_member", static_cast<const BaseObject *>(old_chat_member_.get()));
    s.store_object_field("new_chat_member", static_cast<const BaseObject *>(new_chat_member_.get()));
    s.store_class_end();
  }
}

updateNewChatJoinRequest::updateNewChatJoinRequest()
  : chat_id_()
  , request_()
  , invite_link_()
{}

updateNewChatJoinRequest::updateNewChatJoinRequest(int53 chat_id_, object_ptr<chatJoinRequest> &&request_, object_ptr<chatInviteLink> &&invite_link_)
  : chat_id_(chat_id_)
  , request_(std::move(request_))
  , invite_link_(std::move(invite_link_))
{}

const std::int32_t updateNewChatJoinRequest::ID;

void updateNewChatJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewChatJoinRequest");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("request", static_cast<const BaseObject *>(request_.get()));
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

updates::updates()
  : updates_()
{}

updates::updates(array<object_ptr<Update>> &&updates_)
  : updates_(std::move(updates_))
{}

const std::int32_t updates::ID;

void updates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates");
    { s.store_vector_begin("updates", updates_.size()); for (const auto &_value : updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

user::user()
  : id_()
  , first_name_()
  , last_name_()
  , username_()
  , phone_number_()
  , status_()
  , profile_photo_()
  , is_contact_()
  , is_mutual_contact_()
  , is_verified_()
  , is_support_()
  , restriction_reason_()
  , is_scam_()
  , is_fake_()
  , have_access_()
  , type_()
  , language_code_()
{}

user::user(int53 id_, string const &first_name_, string const &last_name_, string const &username_, string const &phone_number_, object_ptr<UserStatus> &&status_, object_ptr<profilePhoto> &&profile_photo_, bool is_contact_, bool is_mutual_contact_, bool is_verified_, bool is_support_, string const &restriction_reason_, bool is_scam_, bool is_fake_, bool have_access_, object_ptr<UserType> &&type_, string const &language_code_)
  : id_(id_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , username_(username_)
  , phone_number_(phone_number_)
  , status_(std::move(status_))
  , profile_photo_(std::move(profile_photo_))
  , is_contact_(is_contact_)
  , is_mutual_contact_(is_mutual_contact_)
  , is_verified_(is_verified_)
  , is_support_(is_support_)
  , restriction_reason_(restriction_reason_)
  , is_scam_(is_scam_)
  , is_fake_(is_fake_)
  , have_access_(have_access_)
  , type_(std::move(type_))
  , language_code_(language_code_)
{}

const std::int32_t user::ID;

void user::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "user");
    s.store_field("id", id_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("username", username_);
    s.store_field("phone_number", phone_number_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_object_field("profile_photo", static_cast<const BaseObject *>(profile_photo_.get()));
    s.store_field("is_contact", is_contact_);
    s.store_field("is_mutual_contact", is_mutual_contact_);
    s.store_field("is_verified", is_verified_);
    s.store_field("is_support", is_support_);
    s.store_field("restriction_reason", restriction_reason_);
    s.store_field("is_scam", is_scam_);
    s.store_field("is_fake", is_fake_);
    s.store_field("have_access", have_access_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

userFullInfo::userFullInfo()
  : photo_()
  , is_blocked_()
  , can_be_called_()
  , supports_video_calls_()
  , has_private_calls_()
  , has_private_forwards_()
  , need_phone_number_privacy_exception_()
  , bio_()
  , group_in_common_count_()
  , bot_info_()
{}

userFullInfo::userFullInfo(object_ptr<chatPhoto> &&photo_, bool is_blocked_, bool can_be_called_, bool supports_video_calls_, bool has_private_calls_, bool has_private_forwards_, bool need_phone_number_privacy_exception_, string const &bio_, int32 group_in_common_count_, object_ptr<botInfo> &&bot_info_)
  : photo_(std::move(photo_))
  , is_blocked_(is_blocked_)
  , can_be_called_(can_be_called_)
  , supports_video_calls_(supports_video_calls_)
  , has_private_calls_(has_private_calls_)
  , has_private_forwards_(has_private_forwards_)
  , need_phone_number_privacy_exception_(need_phone_number_privacy_exception_)
  , bio_(bio_)
  , group_in_common_count_(group_in_common_count_)
  , bot_info_(std::move(bot_info_))
{}

const std::int32_t userFullInfo::ID;

void userFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userFullInfo");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("is_blocked", is_blocked_);
    s.store_field("can_be_called", can_be_called_);
    s.store_field("supports_video_calls", supports_video_calls_);
    s.store_field("has_private_calls", has_private_calls_);
    s.store_field("has_private_forwards", has_private_forwards_);
    s.store_field("need_phone_number_privacy_exception", need_phone_number_privacy_exception_);
    s.store_field("bio", bio_);
    s.store_field("group_in_common_count", group_in_common_count_);
    s.store_object_field("bot_info", static_cast<const BaseObject *>(bot_info_.get()));
    s.store_class_end();
  }
}

userPrivacySettingShowStatus::userPrivacySettingShowStatus() {
}

const std::int32_t userPrivacySettingShowStatus::ID;

void userPrivacySettingShowStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowStatus");
    s.store_class_end();
  }
}

userPrivacySettingShowProfilePhoto::userPrivacySettingShowProfilePhoto() {
}

const std::int32_t userPrivacySettingShowProfilePhoto::ID;

void userPrivacySettingShowProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowProfilePhoto");
    s.store_class_end();
  }
}

userPrivacySettingShowLinkInForwardedMessages::userPrivacySettingShowLinkInForwardedMessages() {
}

const std::int32_t userPrivacySettingShowLinkInForwardedMessages::ID;

void userPrivacySettingShowLinkInForwardedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowLinkInForwardedMessages");
    s.store_class_end();
  }
}

userPrivacySettingShowPhoneNumber::userPrivacySettingShowPhoneNumber() {
}

const std::int32_t userPrivacySettingShowPhoneNumber::ID;

void userPrivacySettingShowPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingShowPhoneNumber");
    s.store_class_end();
  }
}

userPrivacySettingAllowChatInvites::userPrivacySettingAllowChatInvites() {
}

const std::int32_t userPrivacySettingAllowChatInvites::ID;

void userPrivacySettingAllowChatInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowChatInvites");
    s.store_class_end();
  }
}

userPrivacySettingAllowCalls::userPrivacySettingAllowCalls() {
}

const std::int32_t userPrivacySettingAllowCalls::ID;

void userPrivacySettingAllowCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowCalls");
    s.store_class_end();
  }
}

userPrivacySettingAllowPeerToPeerCalls::userPrivacySettingAllowPeerToPeerCalls() {
}

const std::int32_t userPrivacySettingAllowPeerToPeerCalls::ID;

void userPrivacySettingAllowPeerToPeerCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowPeerToPeerCalls");
    s.store_class_end();
  }
}

userPrivacySettingAllowFindingByPhoneNumber::userPrivacySettingAllowFindingByPhoneNumber() {
}

const std::int32_t userPrivacySettingAllowFindingByPhoneNumber::ID;

void userPrivacySettingAllowFindingByPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingAllowFindingByPhoneNumber");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowAll::userPrivacySettingRuleAllowAll() {
}

const std::int32_t userPrivacySettingRuleAllowAll::ID;

void userPrivacySettingRuleAllowAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowAll");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowContacts::userPrivacySettingRuleAllowContacts() {
}

const std::int32_t userPrivacySettingRuleAllowContacts::ID;

void userPrivacySettingRuleAllowContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowContacts");
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowUsers::userPrivacySettingRuleAllowUsers()
  : user_ids_()
{}

userPrivacySettingRuleAllowUsers::userPrivacySettingRuleAllowUsers(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t userPrivacySettingRuleAllowUsers::ID;

void userPrivacySettingRuleAllowUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowUsers");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userPrivacySettingRuleAllowChatMembers::userPrivacySettingRuleAllowChatMembers()
  : chat_ids_()
{}

userPrivacySettingRuleAllowChatMembers::userPrivacySettingRuleAllowChatMembers(array<int53> &&chat_ids_)
  : chat_ids_(std::move(chat_ids_))
{}

const std::int32_t userPrivacySettingRuleAllowChatMembers::ID;

void userPrivacySettingRuleAllowChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleAllowChatMembers");
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictAll::userPrivacySettingRuleRestrictAll() {
}

const std::int32_t userPrivacySettingRuleRestrictAll::ID;

void userPrivacySettingRuleRestrictAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictAll");
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictContacts::userPrivacySettingRuleRestrictContacts() {
}

const std::int32_t userPrivacySettingRuleRestrictContacts::ID;

void userPrivacySettingRuleRestrictContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictContacts");
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictUsers::userPrivacySettingRuleRestrictUsers()
  : user_ids_()
{}

userPrivacySettingRuleRestrictUsers::userPrivacySettingRuleRestrictUsers(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t userPrivacySettingRuleRestrictUsers::ID;

void userPrivacySettingRuleRestrictUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictUsers");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userPrivacySettingRuleRestrictChatMembers::userPrivacySettingRuleRestrictChatMembers()
  : chat_ids_()
{}

userPrivacySettingRuleRestrictChatMembers::userPrivacySettingRuleRestrictChatMembers(array<int53> &&chat_ids_)
  : chat_ids_(std::move(chat_ids_))
{}

const std::int32_t userPrivacySettingRuleRestrictChatMembers::ID;

void userPrivacySettingRuleRestrictChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRuleRestrictChatMembers");
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

userPrivacySettingRules::userPrivacySettingRules()
  : rules_()
{}

userPrivacySettingRules::userPrivacySettingRules(array<object_ptr<UserPrivacySettingRule>> &&rules_)
  : rules_(std::move(rules_))
{}

const std::int32_t userPrivacySettingRules::ID;

void userPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRules");
    { s.store_vector_begin("rules", rules_.size()); for (const auto &_value : rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

userStatusEmpty::userStatusEmpty() {
}

const std::int32_t userStatusEmpty::ID;

void userStatusEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusEmpty");
    s.store_class_end();
  }
}

userStatusOnline::userStatusOnline()
  : expires_()
{}

userStatusOnline::userStatusOnline(int32 expires_)
  : expires_(expires_)
{}

const std::int32_t userStatusOnline::ID;

void userStatusOnline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusOnline");
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

userStatusOffline::userStatusOffline()
  : was_online_()
{}

userStatusOffline::userStatusOffline(int32 was_online_)
  : was_online_(was_online_)
{}

const std::int32_t userStatusOffline::ID;

void userStatusOffline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusOffline");
    s.store_field("was_online", was_online_);
    s.store_class_end();
  }
}

userStatusRecently::userStatusRecently() {
}

const std::int32_t userStatusRecently::ID;

void userStatusRecently::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusRecently");
    s.store_class_end();
  }
}

userStatusLastWeek::userStatusLastWeek() {
}

const std::int32_t userStatusLastWeek::ID;

void userStatusLastWeek::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusLastWeek");
    s.store_class_end();
  }
}

userStatusLastMonth::userStatusLastMonth() {
}

const std::int32_t userStatusLastMonth::ID;

void userStatusLastMonth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusLastMonth");
    s.store_class_end();
  }
}

userTypeRegular::userTypeRegular() {
}

const std::int32_t userTypeRegular::ID;

void userTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeRegular");
    s.store_class_end();
  }
}

userTypeDeleted::userTypeDeleted() {
}

const std::int32_t userTypeDeleted::ID;

void userTypeDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeDeleted");
    s.store_class_end();
  }
}

userTypeBot::userTypeBot()
  : can_join_groups_()
  , can_read_all_group_messages_()
  , is_inline_()
  , inline_query_placeholder_()
  , need_location_()
  , can_be_added_to_attachment_menu_()
{}

userTypeBot::userTypeBot(bool can_join_groups_, bool can_read_all_group_messages_, bool is_inline_, string const &inline_query_placeholder_, bool need_location_, bool can_be_added_to_attachment_menu_)
  : can_join_groups_(can_join_groups_)
  , can_read_all_group_messages_(can_read_all_group_messages_)
  , is_inline_(is_inline_)
  , inline_query_placeholder_(inline_query_placeholder_)
  , need_location_(need_location_)
  , can_be_added_to_attachment_menu_(can_be_added_to_attachment_menu_)
{}

const std::int32_t userTypeBot::ID;

void userTypeBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeBot");
    s.store_field("can_join_groups", can_join_groups_);
    s.store_field("can_read_all_group_messages", can_read_all_group_messages_);
    s.store_field("is_inline", is_inline_);
    s.store_field("inline_query_placeholder", inline_query_placeholder_);
    s.store_field("need_location", need_location_);
    s.store_field("can_be_added_to_attachment_menu", can_be_added_to_attachment_menu_);
    s.store_class_end();
  }
}

userTypeUnknown::userTypeUnknown() {
}

const std::int32_t userTypeUnknown::ID;

void userTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userTypeUnknown");
    s.store_class_end();
  }
}

users::users()
  : total_count_()
  , user_ids_()
{}

users::users(int32 total_count_, array<int53> &&user_ids_)
  : total_count_(total_count_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t users::ID;

void users::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

validatedOrderInfo::validatedOrderInfo()
  : order_info_id_()
  , shipping_options_()
{}

validatedOrderInfo::validatedOrderInfo(string const &order_info_id_, array<object_ptr<shippingOption>> &&shipping_options_)
  : order_info_id_(order_info_id_)
  , shipping_options_(std::move(shipping_options_))
{}

const std::int32_t validatedOrderInfo::ID;

void validatedOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "validatedOrderInfo");
    s.store_field("order_info_id", order_info_id_);
    { s.store_vector_begin("shipping_options", shipping_options_.size()); for (const auto &_value : shipping_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

vectorPathCommandLine::vectorPathCommandLine()
  : end_point_()
{}

vectorPathCommandLine::vectorPathCommandLine(object_ptr<point> &&end_point_)
  : end_point_(std::move(end_point_))
{}

const std::int32_t vectorPathCommandLine::ID;

void vectorPathCommandLine::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "vectorPathCommandLine");
    s.store_object_field("end_point", static_cast<const BaseObject *>(end_point_.get()));
    s.store_class_end();
  }
}

vectorPathCommandCubicBezierCurve::vectorPathCommandCubicBezierCurve()
  : start_control_point_()
  , end_control_point_()
  , end_point_()
{}

vectorPathCommandCubicBezierCurve::vectorPathCommandCubicBezierCurve(object_ptr<point> &&start_control_point_, object_ptr<point> &&end_control_point_, object_ptr<point> &&end_point_)
  : start_control_point_(std::move(start_control_point_))
  , end_control_point_(std::move(end_control_point_))
  , end_point_(std::move(end_point_))
{}

const std::int32_t vectorPathCommandCubicBezierCurve::ID;

void vectorPathCommandCubicBezierCurve::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "vectorPathCommandCubicBezierCurve");
    s.store_object_field("start_control_point", static_cast<const BaseObject *>(start_control_point_.get()));
    s.store_object_field("end_control_point", static_cast<const BaseObject *>(end_control_point_.get()));
    s.store_object_field("end_point", static_cast<const BaseObject *>(end_point_.get()));
    s.store_class_end();
  }
}

venue::venue()
  : location_()
  , title_()
  , address_()
  , provider_()
  , id_()
  , type_()
{}

venue::venue(object_ptr<location> &&location_, string const &title_, string const &address_, string const &provider_, string const &id_, string const &type_)
  : location_(std::move(location_))
  , title_(title_)
  , address_(address_)
  , provider_(provider_)
  , id_(id_)
  , type_(type_)
{}

const std::int32_t venue::ID;

void venue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "venue");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("id", id_);
    s.store_field("type", type_);
    s.store_class_end();
  }
}

video::video()
  : duration_()
  , width_()
  , height_()
  , file_name_()
  , mime_type_()
  , has_stickers_()
  , supports_streaming_()
  , minithumbnail_()
  , thumbnail_()
  , video_()
{}

video::video(int32 duration_, int32 width_, int32 height_, string const &file_name_, string const &mime_type_, bool has_stickers_, bool supports_streaming_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&video_)
  : duration_(duration_)
  , width_(width_)
  , height_(height_)
  , file_name_(file_name_)
  , mime_type_(mime_type_)
  , has_stickers_(has_stickers_)
  , supports_streaming_(supports_streaming_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , video_(std::move(video_))
{}

const std::int32_t video::ID;

void video::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "video");
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_field("has_stickers", has_stickers_);
    s.store_field("supports_streaming", supports_streaming_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

videoChat::videoChat()
  : group_call_id_()
  , has_participants_()
  , default_participant_id_()
{}

videoChat::videoChat(int32 group_call_id_, bool has_participants_, object_ptr<MessageSender> &&default_participant_id_)
  : group_call_id_(group_call_id_)
  , has_participants_(has_participants_)
  , default_participant_id_(std::move(default_participant_id_))
{}

const std::int32_t videoChat::ID;

void videoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoChat");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("has_participants", has_participants_);
    s.store_object_field("default_participant_id", static_cast<const BaseObject *>(default_participant_id_.get()));
    s.store_class_end();
  }
}

videoNote::videoNote()
  : duration_()
  , length_()
  , minithumbnail_()
  , thumbnail_()
  , video_()
{}

videoNote::videoNote(int32 duration_, int32 length_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&video_)
  : duration_(duration_)
  , length_(length_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , video_(std::move(video_))
{}

const std::int32_t videoNote::ID;

void videoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoNote");
    s.store_field("duration", duration_);
    s.store_field("length", length_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

voiceNote::voiceNote()
  : duration_()
  , waveform_()
  , mime_type_()
  , voice_()
{}

voiceNote::voiceNote(int32 duration_, bytes const &waveform_, string const &mime_type_, object_ptr<file> &&voice_)
  : duration_(duration_)
  , waveform_(std::move(waveform_))
  , mime_type_(mime_type_)
  , voice_(std::move(voice_))
{}

const std::int32_t voiceNote::ID;

void voiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "voiceNote");
    s.store_field("duration", duration_);
    s.store_bytes_field("waveform", waveform_);
    s.store_field("mime_type", mime_type_);
    s.store_object_field("voice", static_cast<const BaseObject *>(voice_.get()));
    s.store_class_end();
  }
}

webAppInfo::webAppInfo()
  : launch_id_()
  , url_()
{}

webAppInfo::webAppInfo(int64 launch_id_, string const &url_)
  : launch_id_(launch_id_)
  , url_(url_)
{}

const std::int32_t webAppInfo::ID;

void webAppInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppInfo");
    s.store_field("launch_id", launch_id_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

webPage::webPage()
  : url_()
  , display_url_()
  , type_()
  , site_name_()
  , title_()
  , description_()
  , photo_()
  , embed_url_()
  , embed_type_()
  , embed_width_()
  , embed_height_()
  , duration_()
  , author_()
  , animation_()
  , audio_()
  , document_()
  , sticker_()
  , video_()
  , video_note_()
  , voice_note_()
  , instant_view_version_()
{}

webPage::webPage(string const &url_, string const &display_url_, string const &type_, string const &site_name_, string const &title_, object_ptr<formattedText> &&description_, object_ptr<photo> &&photo_, string const &embed_url_, string const &embed_type_, int32 embed_width_, int32 embed_height_, int32 duration_, string const &author_, object_ptr<animation> &&animation_, object_ptr<audio> &&audio_, object_ptr<document> &&document_, object_ptr<sticker> &&sticker_, object_ptr<video> &&video_, object_ptr<videoNote> &&video_note_, object_ptr<voiceNote> &&voice_note_, int32 instant_view_version_)
  : url_(url_)
  , display_url_(display_url_)
  , type_(type_)
  , site_name_(site_name_)
  , title_(title_)
  , description_(std::move(description_))
  , photo_(std::move(photo_))
  , embed_url_(embed_url_)
  , embed_type_(embed_type_)
  , embed_width_(embed_width_)
  , embed_height_(embed_height_)
  , duration_(duration_)
  , author_(author_)
  , animation_(std::move(animation_))
  , audio_(std::move(audio_))
  , document_(std::move(document_))
  , sticker_(std::move(sticker_))
  , video_(std::move(video_))
  , video_note_(std::move(video_note_))
  , voice_note_(std::move(voice_note_))
  , instant_view_version_(instant_view_version_)
{}

const std::int32_t webPage::ID;

void webPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPage");
    s.store_field("url", url_);
    s.store_field("display_url", display_url_);
    s.store_field("type", type_);
    s.store_field("site_name", site_name_);
    s.store_field("title", title_);
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("embed_url", embed_url_);
    s.store_field("embed_type", embed_type_);
    s.store_field("embed_width", embed_width_);
    s.store_field("embed_height", embed_height_);
    s.store_field("duration", duration_);
    s.store_field("author", author_);
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_field("instant_view_version", instant_view_version_);
    s.store_class_end();
  }
}

webPageInstantView::webPageInstantView()
  : page_blocks_()
  , view_count_()
  , version_()
  , is_rtl_()
  , is_full_()
  , feedback_link_()
{}

webPageInstantView::webPageInstantView(array<object_ptr<PageBlock>> &&page_blocks_, int32 view_count_, int32 version_, bool is_rtl_, bool is_full_, object_ptr<InternalLinkType> &&feedback_link_)
  : page_blocks_(std::move(page_blocks_))
  , view_count_(view_count_)
  , version_(version_)
  , is_rtl_(is_rtl_)
  , is_full_(is_full_)
  , feedback_link_(std::move(feedback_link_))
{}

const std::int32_t webPageInstantView::ID;

void webPageInstantView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageInstantView");
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("view_count", view_count_);
    s.store_field("version", version_);
    s.store_field("is_rtl", is_rtl_);
    s.store_field("is_full", is_full_);
    s.store_object_field("feedback_link", static_cast<const BaseObject *>(feedback_link_.get()));
    s.store_class_end();
  }
}

acceptCall::acceptCall()
  : call_id_()
  , protocol_()
{}

acceptCall::acceptCall(int32 call_id_, object_ptr<callProtocol> &&protocol_)
  : call_id_(call_id_)
  , protocol_(std::move(protocol_))
{}

const std::int32_t acceptCall::ID;

void acceptCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "acceptCall");
    s.store_field("call_id", call_id_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

acceptTermsOfService::acceptTermsOfService()
  : terms_of_service_id_()
{}

acceptTermsOfService::acceptTermsOfService(string const &terms_of_service_id_)
  : terms_of_service_id_(terms_of_service_id_)
{}

const std::int32_t acceptTermsOfService::ID;

void acceptTermsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "acceptTermsOfService");
    s.store_field("terms_of_service_id", terms_of_service_id_);
    s.store_class_end();
  }
}

addChatMember::addChatMember()
  : chat_id_()
  , user_id_()
  , forward_limit_()
{}

addChatMember::addChatMember(int53 chat_id_, int53 user_id_, int32 forward_limit_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
  , forward_limit_(forward_limit_)
{}

const std::int32_t addChatMember::ID;

void addChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("forward_limit", forward_limit_);
    s.store_class_end();
  }
}

addChatMembers::addChatMembers()
  : chat_id_()
  , user_ids_()
{}

addChatMembers::addChatMembers(int53 chat_id_, array<int53> &&user_ids_)
  : chat_id_(chat_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t addChatMembers::ID;

void addChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatMembers");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

addChatToList::addChatToList()
  : chat_id_()
  , chat_list_()
{}

addChatToList::addChatToList(int53 chat_id_, object_ptr<ChatList> &&chat_list_)
  : chat_id_(chat_id_)
  , chat_list_(std::move(chat_list_))
{}

const std::int32_t addChatToList::ID;

void addChatToList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatToList");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_class_end();
  }
}

addContact::addContact()
  : contact_()
  , share_phone_number_()
{}

addContact::addContact(object_ptr<contact> &&contact_, bool share_phone_number_)
  : contact_(std::move(contact_))
  , share_phone_number_(share_phone_number_)
{}

const std::int32_t addContact::ID;

void addContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addContact");
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_field("share_phone_number", share_phone_number_);
    s.store_class_end();
  }
}

addCustomServerLanguagePack::addCustomServerLanguagePack()
  : language_pack_id_()
{}

addCustomServerLanguagePack::addCustomServerLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t addCustomServerLanguagePack::ID;

void addCustomServerLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addCustomServerLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

addFavoriteSticker::addFavoriteSticker()
  : sticker_()
{}

addFavoriteSticker::addFavoriteSticker(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t addFavoriteSticker::ID;

void addFavoriteSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addFavoriteSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

addFileToDownloads::addFileToDownloads()
  : file_id_()
  , chat_id_()
  , message_id_()
  , priority_()
{}

addFileToDownloads::addFileToDownloads(int32 file_id_, int53 chat_id_, int53 message_id_, int32 priority_)
  : file_id_(file_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , priority_(priority_)
{}

const std::int32_t addFileToDownloads::ID;

void addFileToDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addFileToDownloads");
    s.store_field("file_id", file_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("priority", priority_);
    s.store_class_end();
  }
}

addLocalMessage::addLocalMessage()
  : chat_id_()
  , sender_id_()
  , reply_to_message_id_()
  , disable_notification_()
  , input_message_content_()
{}

addLocalMessage::addLocalMessage(int53 chat_id_, object_ptr<MessageSender> &&sender_id_, int53 reply_to_message_id_, bool disable_notification_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , sender_id_(std::move(sender_id_))
  , reply_to_message_id_(reply_to_message_id_)
  , disable_notification_(disable_notification_)
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t addLocalMessage::ID;

void addLocalMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addLocalMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_field("disable_notification", disable_notification_);
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

addLogMessage::addLogMessage()
  : verbosity_level_()
  , text_()
{}

addLogMessage::addLogMessage(int32 verbosity_level_, string const &text_)
  : verbosity_level_(verbosity_level_)
  , text_(text_)
{}

const std::int32_t addLogMessage::ID;

void addLogMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addLogMessage");
    s.store_field("verbosity_level", verbosity_level_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

addNetworkStatistics::addNetworkStatistics()
  : entry_()
{}

addNetworkStatistics::addNetworkStatistics(object_ptr<NetworkStatisticsEntry> &&entry_)
  : entry_(std::move(entry_))
{}

const std::int32_t addNetworkStatistics::ID;

void addNetworkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addNetworkStatistics");
    s.store_object_field("entry", static_cast<const BaseObject *>(entry_.get()));
    s.store_class_end();
  }
}

addProxy::addProxy()
  : server_()
  , port_()
  , enable_()
  , type_()
{}

addProxy::addProxy(string const &server_, int32 port_, bool enable_, object_ptr<ProxyType> &&type_)
  : server_(server_)
  , port_(port_)
  , enable_(enable_)
  , type_(std::move(type_))
{}

const std::int32_t addProxy::ID;

void addProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addProxy");
    s.store_field("server", server_);
    s.store_field("port", port_);
    s.store_field("enable", enable_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

addRecentSticker::addRecentSticker()
  : is_attached_()
  , sticker_()
{}

addRecentSticker::addRecentSticker(bool is_attached_, object_ptr<InputFile> &&sticker_)
  : is_attached_(is_attached_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t addRecentSticker::ID;

void addRecentSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addRecentSticker");
    s.store_field("is_attached", is_attached_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

addRecentlyFoundChat::addRecentlyFoundChat()
  : chat_id_()
{}

addRecentlyFoundChat::addRecentlyFoundChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t addRecentlyFoundChat::ID;

void addRecentlyFoundChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addRecentlyFoundChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

addSavedAnimation::addSavedAnimation()
  : animation_()
{}

addSavedAnimation::addSavedAnimation(object_ptr<InputFile> &&animation_)
  : animation_(std::move(animation_))
{}

const std::int32_t addSavedAnimation::ID;

void addSavedAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addSavedAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

addSavedNotificationSound::addSavedNotificationSound()
  : sound_()
{}

addSavedNotificationSound::addSavedNotificationSound(object_ptr<InputFile> &&sound_)
  : sound_(std::move(sound_))
{}

const std::int32_t addSavedNotificationSound::ID;

void addSavedNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addSavedNotificationSound");
    s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get()));
    s.store_class_end();
  }
}

addStickerToSet::addStickerToSet()
  : user_id_()
  , name_()
  , sticker_()
{}

addStickerToSet::addStickerToSet(int53 user_id_, string const &name_, object_ptr<inputSticker> &&sticker_)
  : user_id_(user_id_)
  , name_(name_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t addStickerToSet::ID;

void addStickerToSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addStickerToSet");
    s.store_field("user_id", user_id_);
    s.store_field("name", name_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

answerCallbackQuery::answerCallbackQuery()
  : callback_query_id_()
  , text_()
  , show_alert_()
  , url_()
  , cache_time_()
{}

answerCallbackQuery::answerCallbackQuery(int64 callback_query_id_, string const &text_, bool show_alert_, string const &url_, int32 cache_time_)
  : callback_query_id_(callback_query_id_)
  , text_(text_)
  , show_alert_(show_alert_)
  , url_(url_)
  , cache_time_(cache_time_)
{}

const std::int32_t answerCallbackQuery::ID;

void answerCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerCallbackQuery");
    s.store_field("callback_query_id", callback_query_id_);
    s.store_field("text", text_);
    s.store_field("show_alert", show_alert_);
    s.store_field("url", url_);
    s.store_field("cache_time", cache_time_);
    s.store_class_end();
  }
}

answerCustomQuery::answerCustomQuery()
  : custom_query_id_()
  , data_()
{}

answerCustomQuery::answerCustomQuery(int64 custom_query_id_, string const &data_)
  : custom_query_id_(custom_query_id_)
  , data_(data_)
{}

const std::int32_t answerCustomQuery::ID;

void answerCustomQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerCustomQuery");
    s.store_field("custom_query_id", custom_query_id_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

answerInlineQuery::answerInlineQuery()
  : inline_query_id_()
  , is_personal_()
  , results_()
  , cache_time_()
  , next_offset_()
  , switch_pm_text_()
  , switch_pm_parameter_()
{}

answerInlineQuery::answerInlineQuery(int64 inline_query_id_, bool is_personal_, array<object_ptr<InputInlineQueryResult>> &&results_, int32 cache_time_, string const &next_offset_, string const &switch_pm_text_, string const &switch_pm_parameter_)
  : inline_query_id_(inline_query_id_)
  , is_personal_(is_personal_)
  , results_(std::move(results_))
  , cache_time_(cache_time_)
  , next_offset_(next_offset_)
  , switch_pm_text_(switch_pm_text_)
  , switch_pm_parameter_(switch_pm_parameter_)
{}

const std::int32_t answerInlineQuery::ID;

void answerInlineQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerInlineQuery");
    s.store_field("inline_query_id", inline_query_id_);
    s.store_field("is_personal", is_personal_);
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("cache_time", cache_time_);
    s.store_field("next_offset", next_offset_);
    s.store_field("switch_pm_text", switch_pm_text_);
    s.store_field("switch_pm_parameter", switch_pm_parameter_);
    s.store_class_end();
  }
}

answerPreCheckoutQuery::answerPreCheckoutQuery()
  : pre_checkout_query_id_()
  , error_message_()
{}

answerPreCheckoutQuery::answerPreCheckoutQuery(int64 pre_checkout_query_id_, string const &error_message_)
  : pre_checkout_query_id_(pre_checkout_query_id_)
  , error_message_(error_message_)
{}

const std::int32_t answerPreCheckoutQuery::ID;

void answerPreCheckoutQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerPreCheckoutQuery");
    s.store_field("pre_checkout_query_id", pre_checkout_query_id_);
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

answerShippingQuery::answerShippingQuery()
  : shipping_query_id_()
  , shipping_options_()
  , error_message_()
{}

answerShippingQuery::answerShippingQuery(int64 shipping_query_id_, array<object_ptr<shippingOption>> &&shipping_options_, string const &error_message_)
  : shipping_query_id_(shipping_query_id_)
  , shipping_options_(std::move(shipping_options_))
  , error_message_(error_message_)
{}

const std::int32_t answerShippingQuery::ID;

void answerShippingQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerShippingQuery");
    s.store_field("shipping_query_id", shipping_query_id_);
    { s.store_vector_begin("shipping_options", shipping_options_.size()); for (const auto &_value : shipping_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

answerWebAppQuery::answerWebAppQuery()
  : web_app_query_id_()
  , result_()
{}

answerWebAppQuery::answerWebAppQuery(string const &web_app_query_id_, object_ptr<InputInlineQueryResult> &&result_)
  : web_app_query_id_(web_app_query_id_)
  , result_(std::move(result_))
{}

const std::int32_t answerWebAppQuery::ID;

void answerWebAppQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerWebAppQuery");
    s.store_field("web_app_query_id", web_app_query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_class_end();
  }
}

banChatMember::banChatMember()
  : chat_id_()
  , member_id_()
  , banned_until_date_()
  , revoke_messages_()
{}

banChatMember::banChatMember(int53 chat_id_, object_ptr<MessageSender> &&member_id_, int32 banned_until_date_, bool revoke_messages_)
  : chat_id_(chat_id_)
  , member_id_(std::move(member_id_))
  , banned_until_date_(banned_until_date_)
  , revoke_messages_(revoke_messages_)
{}

const std::int32_t banChatMember::ID;

void banChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "banChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_field("banned_until_date", banned_until_date_);
    s.store_field("revoke_messages", revoke_messages_);
    s.store_class_end();
  }
}

blockMessageSenderFromReplies::blockMessageSenderFromReplies()
  : message_id_()
  , delete_message_()
  , delete_all_messages_()
  , report_spam_()
{}

blockMessageSenderFromReplies::blockMessageSenderFromReplies(int53 message_id_, bool delete_message_, bool delete_all_messages_, bool report_spam_)
  : message_id_(message_id_)
  , delete_message_(delete_message_)
  , delete_all_messages_(delete_all_messages_)
  , report_spam_(report_spam_)
{}

const std::int32_t blockMessageSenderFromReplies::ID;

void blockMessageSenderFromReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "blockMessageSenderFromReplies");
    s.store_field("message_id", message_id_);
    s.store_field("delete_message", delete_message_);
    s.store_field("delete_all_messages", delete_all_messages_);
    s.store_field("report_spam", report_spam_);
    s.store_class_end();
  }
}

canTransferOwnership::canTransferOwnership() {
}

const std::int32_t canTransferOwnership::ID;

void canTransferOwnership::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnership");
    s.store_class_end();
  }
}

cancelDownloadFile::cancelDownloadFile()
  : file_id_()
  , only_if_pending_()
{}

cancelDownloadFile::cancelDownloadFile(int32 file_id_, bool only_if_pending_)
  : file_id_(file_id_)
  , only_if_pending_(only_if_pending_)
{}

const std::int32_t cancelDownloadFile::ID;

void cancelDownloadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelDownloadFile");
    s.store_field("file_id", file_id_);
    s.store_field("only_if_pending", only_if_pending_);
    s.store_class_end();
  }
}

cancelPasswordReset::cancelPasswordReset() {
}

const std::int32_t cancelPasswordReset::ID;

void cancelPasswordReset::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelPasswordReset");
    s.store_class_end();
  }
}

cancelUploadFile::cancelUploadFile()
  : file_id_()
{}

cancelUploadFile::cancelUploadFile(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t cancelUploadFile::ID;

void cancelUploadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelUploadFile");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

changeImportedContacts::changeImportedContacts()
  : contacts_()
{}

changeImportedContacts::changeImportedContacts(array<object_ptr<contact>> &&contacts_)
  : contacts_(std::move(contacts_))
{}

const std::int32_t changeImportedContacts::ID;

void changeImportedContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "changeImportedContacts");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

changePhoneNumber::changePhoneNumber()
  : phone_number_()
  , settings_()
{}

changePhoneNumber::changePhoneNumber(string const &phone_number_, object_ptr<phoneNumberAuthenticationSettings> &&settings_)
  : phone_number_(phone_number_)
  , settings_(std::move(settings_))
{}

const std::int32_t changePhoneNumber::ID;

void changePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "changePhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

changeStickerSet::changeStickerSet()
  : set_id_()
  , is_installed_()
  , is_archived_()
{}

changeStickerSet::changeStickerSet(int64 set_id_, bool is_installed_, bool is_archived_)
  : set_id_(set_id_)
  , is_installed_(is_installed_)
  , is_archived_(is_archived_)
{}

const std::int32_t changeStickerSet::ID;

void changeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "changeStickerSet");
    s.store_field("set_id", set_id_);
    s.store_field("is_installed", is_installed_);
    s.store_field("is_archived", is_archived_);
    s.store_class_end();
  }
}

checkAuthenticationBotToken::checkAuthenticationBotToken()
  : token_()
{}

checkAuthenticationBotToken::checkAuthenticationBotToken(string const &token_)
  : token_(token_)
{}

const std::int32_t checkAuthenticationBotToken::ID;

void checkAuthenticationBotToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationBotToken");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

checkAuthenticationCode::checkAuthenticationCode()
  : code_()
{}

checkAuthenticationCode::checkAuthenticationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkAuthenticationCode::ID;

void checkAuthenticationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

checkAuthenticationPassword::checkAuthenticationPassword()
  : password_()
{}

checkAuthenticationPassword::checkAuthenticationPassword(string const &password_)
  : password_(password_)
{}

const std::int32_t checkAuthenticationPassword::ID;

void checkAuthenticationPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationPassword");
    s.store_field("password", password_);
    s.store_class_end();
  }
}

checkAuthenticationPasswordRecoveryCode::checkAuthenticationPasswordRecoveryCode()
  : recovery_code_()
{}

checkAuthenticationPasswordRecoveryCode::checkAuthenticationPasswordRecoveryCode(string const &recovery_code_)
  : recovery_code_(recovery_code_)
{}

const std::int32_t checkAuthenticationPasswordRecoveryCode::ID;

void checkAuthenticationPasswordRecoveryCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationPasswordRecoveryCode");
    s.store_field("recovery_code", recovery_code_);
    s.store_class_end();
  }
}

checkChangePhoneNumberCode::checkChangePhoneNumberCode()
  : code_()
{}

checkChangePhoneNumberCode::checkChangePhoneNumberCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkChangePhoneNumberCode::ID;

void checkChangePhoneNumberCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChangePhoneNumberCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

checkChatInviteLink::checkChatInviteLink()
  : invite_link_()
{}

checkChatInviteLink::checkChatInviteLink(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t checkChatInviteLink::ID;

void checkChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

checkChatUsername::checkChatUsername()
  : chat_id_()
  , username_()
{}

checkChatUsername::checkChatUsername(int53 chat_id_, string const &username_)
  : chat_id_(chat_id_)
  , username_(username_)
{}

const std::int32_t checkChatUsername::ID;

void checkChatUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsername");
    s.store_field("chat_id", chat_id_);
    s.store_field("username", username_);
    s.store_class_end();
  }
}

checkCreatedPublicChatsLimit::checkCreatedPublicChatsLimit()
  : type_()
{}

checkCreatedPublicChatsLimit::checkCreatedPublicChatsLimit(object_ptr<PublicChatType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t checkCreatedPublicChatsLimit::ID;

void checkCreatedPublicChatsLimit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkCreatedPublicChatsLimit");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

checkDatabaseEncryptionKey::checkDatabaseEncryptionKey()
  : encryption_key_()
{}

checkDatabaseEncryptionKey::checkDatabaseEncryptionKey(bytes const &encryption_key_)
  : encryption_key_(std::move(encryption_key_))
{}

const std::int32_t checkDatabaseEncryptionKey::ID;

void checkDatabaseEncryptionKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkDatabaseEncryptionKey");
    s.store_bytes_field("encryption_key", encryption_key_);
    s.store_class_end();
  }
}

checkEmailAddressVerificationCode::checkEmailAddressVerificationCode()
  : code_()
{}

checkEmailAddressVerificationCode::checkEmailAddressVerificationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkEmailAddressVerificationCode::ID;

void checkEmailAddressVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkEmailAddressVerificationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

checkPasswordRecoveryCode::checkPasswordRecoveryCode()
  : recovery_code_()
{}

checkPasswordRecoveryCode::checkPasswordRecoveryCode(string const &recovery_code_)
  : recovery_code_(recovery_code_)
{}

const std::int32_t checkPasswordRecoveryCode::ID;

void checkPasswordRecoveryCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkPasswordRecoveryCode");
    s.store_field("recovery_code", recovery_code_);
    s.store_class_end();
  }
}

checkPhoneNumberConfirmationCode::checkPhoneNumberConfirmationCode()
  : code_()
{}

checkPhoneNumberConfirmationCode::checkPhoneNumberConfirmationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkPhoneNumberConfirmationCode::ID;

void checkPhoneNumberConfirmationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkPhoneNumberConfirmationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

checkPhoneNumberVerificationCode::checkPhoneNumberVerificationCode()
  : code_()
{}

checkPhoneNumberVerificationCode::checkPhoneNumberVerificationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkPhoneNumberVerificationCode::ID;

void checkPhoneNumberVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkPhoneNumberVerificationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

checkRecoveryEmailAddressCode::checkRecoveryEmailAddressCode()
  : code_()
{}

checkRecoveryEmailAddressCode::checkRecoveryEmailAddressCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkRecoveryEmailAddressCode::ID;

void checkRecoveryEmailAddressCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkRecoveryEmailAddressCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

checkStickerSetName::checkStickerSetName()
  : name_()
{}

checkStickerSetName::checkStickerSetName(string const &name_)
  : name_(name_)
{}

const std::int32_t checkStickerSetName::ID;

void checkStickerSetName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkStickerSetName");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

cleanFileName::cleanFileName()
  : file_name_()
{}

cleanFileName::cleanFileName(string const &file_name_)
  : file_name_(file_name_)
{}

const std::int32_t cleanFileName::ID;

void cleanFileName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cleanFileName");
    s.store_field("file_name", file_name_);
    s.store_class_end();
  }
}

clearAllDraftMessages::clearAllDraftMessages()
  : exclude_secret_chats_()
{}

clearAllDraftMessages::clearAllDraftMessages(bool exclude_secret_chats_)
  : exclude_secret_chats_(exclude_secret_chats_)
{}

const std::int32_t clearAllDraftMessages::ID;

void clearAllDraftMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearAllDraftMessages");
    s.store_field("exclude_secret_chats", exclude_secret_chats_);
    s.store_class_end();
  }
}

clearImportedContacts::clearImportedContacts() {
}

const std::int32_t clearImportedContacts::ID;

void clearImportedContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearImportedContacts");
    s.store_class_end();
  }
}

clearRecentStickers::clearRecentStickers()
  : is_attached_()
{}

clearRecentStickers::clearRecentStickers(bool is_attached_)
  : is_attached_(is_attached_)
{}

const std::int32_t clearRecentStickers::ID;

void clearRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearRecentStickers");
    s.store_field("is_attached", is_attached_);
    s.store_class_end();
  }
}

clearRecentlyFoundChats::clearRecentlyFoundChats() {
}

const std::int32_t clearRecentlyFoundChats::ID;

void clearRecentlyFoundChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearRecentlyFoundChats");
    s.store_class_end();
  }
}

clickAnimatedEmojiMessage::clickAnimatedEmojiMessage()
  : chat_id_()
  , message_id_()
{}

clickAnimatedEmojiMessage::clickAnimatedEmojiMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t clickAnimatedEmojiMessage::ID;

void clickAnimatedEmojiMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clickAnimatedEmojiMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

close::close() {
}

const std::int32_t close::ID;

void close::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "close");
    s.store_class_end();
  }
}

closeChat::closeChat()
  : chat_id_()
{}

closeChat::closeChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t closeChat::ID;

void closeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

closeSecretChat::closeSecretChat()
  : secret_chat_id_()
{}

closeSecretChat::closeSecretChat(int32 secret_chat_id_)
  : secret_chat_id_(secret_chat_id_)
{}

const std::int32_t closeSecretChat::ID;

void closeSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeSecretChat");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_class_end();
  }
}

closeWebApp::closeWebApp()
  : web_app_launch_id_()
{}

closeWebApp::closeWebApp(int64 web_app_launch_id_)
  : web_app_launch_id_(web_app_launch_id_)
{}

const std::int32_t closeWebApp::ID;

void closeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeWebApp");
    s.store_field("web_app_launch_id", web_app_launch_id_);
    s.store_class_end();
  }
}

confirmQrCodeAuthentication::confirmQrCodeAuthentication()
  : link_()
{}

confirmQrCodeAuthentication::confirmQrCodeAuthentication(string const &link_)
  : link_(link_)
{}

const std::int32_t confirmQrCodeAuthentication::ID;

void confirmQrCodeAuthentication::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "confirmQrCodeAuthentication");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

createBasicGroupChat::createBasicGroupChat()
  : basic_group_id_()
  , force_()
{}

createBasicGroupChat::createBasicGroupChat(int53 basic_group_id_, bool force_)
  : basic_group_id_(basic_group_id_)
  , force_(force_)
{}

const std::int32_t createBasicGroupChat::ID;

void createBasicGroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createBasicGroupChat");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

createCall::createCall()
  : user_id_()
  , protocol_()
  , is_video_()
{}

createCall::createCall(int53 user_id_, object_ptr<callProtocol> &&protocol_, bool is_video_)
  : user_id_(user_id_)
  , protocol_(std::move(protocol_))
  , is_video_(is_video_)
{}

const std::int32_t createCall::ID;

void createCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createCall");
    s.store_field("user_id", user_id_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_field("is_video", is_video_);
    s.store_class_end();
  }
}

createChatFilter::createChatFilter()
  : filter_()
{}

createChatFilter::createChatFilter(object_ptr<chatFilter> &&filter_)
  : filter_(std::move(filter_))
{}

const std::int32_t createChatFilter::ID;

void createChatFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createChatFilter");
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_class_end();
  }
}

createChatInviteLink::createChatInviteLink()
  : chat_id_()
  , name_()
  , expiration_date_()
  , member_limit_()
  , creates_join_request_()
{}

createChatInviteLink::createChatInviteLink(int53 chat_id_, string const &name_, int32 expiration_date_, int32 member_limit_, bool creates_join_request_)
  : chat_id_(chat_id_)
  , name_(name_)
  , expiration_date_(expiration_date_)
  , member_limit_(member_limit_)
  , creates_join_request_(creates_join_request_)
{}

const std::int32_t createChatInviteLink::ID;

void createChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("name", name_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("member_limit", member_limit_);
    s.store_field("creates_join_request", creates_join_request_);
    s.store_class_end();
  }
}

createNewBasicGroupChat::createNewBasicGroupChat()
  : user_ids_()
  , title_()
{}

createNewBasicGroupChat::createNewBasicGroupChat(array<int53> &&user_ids_, string const &title_)
  : user_ids_(std::move(user_ids_))
  , title_(title_)
{}

const std::int32_t createNewBasicGroupChat::ID;

void createNewBasicGroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewBasicGroupChat");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("title", title_);
    s.store_class_end();
  }
}

createNewSecretChat::createNewSecretChat()
  : user_id_()
{}

createNewSecretChat::createNewSecretChat(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t createNewSecretChat::ID;

void createNewSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewSecretChat");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

createNewStickerSet::createNewStickerSet()
  : user_id_()
  , title_()
  , name_()
  , stickers_()
  , source_()
{}

createNewStickerSet::createNewStickerSet(int53 user_id_, string const &title_, string const &name_, array<object_ptr<inputSticker>> &&stickers_, string const &source_)
  : user_id_(user_id_)
  , title_(title_)
  , name_(name_)
  , stickers_(std::move(stickers_))
  , source_(source_)
{}

const std::int32_t createNewStickerSet::ID;

void createNewStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewStickerSet");
    s.store_field("user_id", user_id_);
    s.store_field("title", title_);
    s.store_field("name", name_);
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("source", source_);
    s.store_class_end();
  }
}

createNewSupergroupChat::createNewSupergroupChat()
  : title_()
  , is_channel_()
  , description_()
  , location_()
  , for_import_()
{}

createNewSupergroupChat::createNewSupergroupChat(string const &title_, bool is_channel_, string const &description_, object_ptr<chatLocation> &&location_, bool for_import_)
  : title_(title_)
  , is_channel_(is_channel_)
  , description_(description_)
  , location_(std::move(location_))
  , for_import_(for_import_)
{}

const std::int32_t createNewSupergroupChat::ID;

void createNewSupergroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewSupergroupChat");
    s.store_field("title", title_);
    s.store_field("is_channel", is_channel_);
    s.store_field("description", description_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("for_import", for_import_);
    s.store_class_end();
  }
}

createPrivateChat::createPrivateChat()
  : user_id_()
  , force_()
{}

createPrivateChat::createPrivateChat(int53 user_id_, bool force_)
  : user_id_(user_id_)
  , force_(force_)
{}

const std::int32_t createPrivateChat::ID;

void createPrivateChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createPrivateChat");
    s.store_field("user_id", user_id_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

createSecretChat::createSecretChat()
  : secret_chat_id_()
{}

createSecretChat::createSecretChat(int32 secret_chat_id_)
  : secret_chat_id_(secret_chat_id_)
{}

const std::int32_t createSecretChat::ID;

void createSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createSecretChat");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_class_end();
  }
}

createSupergroupChat::createSupergroupChat()
  : supergroup_id_()
  , force_()
{}

createSupergroupChat::createSupergroupChat(int53 supergroup_id_, bool force_)
  : supergroup_id_(supergroup_id_)
  , force_(force_)
{}

const std::int32_t createSupergroupChat::ID;

void createSupergroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createSupergroupChat");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

createTemporaryPassword::createTemporaryPassword()
  : password_()
  , valid_for_()
{}

createTemporaryPassword::createTemporaryPassword(string const &password_, int32 valid_for_)
  : password_(password_)
  , valid_for_(valid_for_)
{}

const std::int32_t createTemporaryPassword::ID;

void createTemporaryPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createTemporaryPassword");
    s.store_field("password", password_);
    s.store_field("valid_for", valid_for_);
    s.store_class_end();
  }
}

createVideoChat::createVideoChat()
  : chat_id_()
  , title_()
  , start_date_()
  , is_rtmp_stream_()
{}

createVideoChat::createVideoChat(int53 chat_id_, string const &title_, int32 start_date_, bool is_rtmp_stream_)
  : chat_id_(chat_id_)
  , title_(title_)
  , start_date_(start_date_)
  , is_rtmp_stream_(is_rtmp_stream_)
{}

const std::int32_t createVideoChat::ID;

void createVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createVideoChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_field("start_date", start_date_);
    s.store_field("is_rtmp_stream", is_rtmp_stream_);
    s.store_class_end();
  }
}

deleteAccount::deleteAccount()
  : reason_()
{}

deleteAccount::deleteAccount(string const &reason_)
  : reason_(reason_)
{}

const std::int32_t deleteAccount::ID;

void deleteAccount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteAccount");
    s.store_field("reason", reason_);
    s.store_class_end();
  }
}

deleteAllCallMessages::deleteAllCallMessages()
  : revoke_()
{}

deleteAllCallMessages::deleteAllCallMessages(bool revoke_)
  : revoke_(revoke_)
{}

const std::int32_t deleteAllCallMessages::ID;

void deleteAllCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteAllCallMessages");
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

deleteAllRevokedChatInviteLinks::deleteAllRevokedChatInviteLinks()
  : chat_id_()
  , creator_user_id_()
{}

deleteAllRevokedChatInviteLinks::deleteAllRevokedChatInviteLinks(int53 chat_id_, int53 creator_user_id_)
  : chat_id_(chat_id_)
  , creator_user_id_(creator_user_id_)
{}

const std::int32_t deleteAllRevokedChatInviteLinks::ID;

void deleteAllRevokedChatInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteAllRevokedChatInviteLinks");
    s.store_field("chat_id", chat_id_);
    s.store_field("creator_user_id", creator_user_id_);
    s.store_class_end();
  }
}

deleteChat::deleteChat()
  : chat_id_()
{}

deleteChat::deleteChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t deleteChat::ID;

void deleteChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

deleteChatFilter::deleteChatFilter()
  : chat_filter_id_()
{}

deleteChatFilter::deleteChatFilter(int32 chat_filter_id_)
  : chat_filter_id_(chat_filter_id_)
{}

const std::int32_t deleteChatFilter::ID;

void deleteChatFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatFilter");
    s.store_field("chat_filter_id", chat_filter_id_);
    s.store_class_end();
  }
}

deleteChatHistory::deleteChatHistory()
  : chat_id_()
  , remove_from_chat_list_()
  , revoke_()
{}

deleteChatHistory::deleteChatHistory(int53 chat_id_, bool remove_from_chat_list_, bool revoke_)
  : chat_id_(chat_id_)
  , remove_from_chat_list_(remove_from_chat_list_)
  , revoke_(revoke_)
{}

const std::int32_t deleteChatHistory::ID;

void deleteChatHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("remove_from_chat_list", remove_from_chat_list_);
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

deleteChatMessagesByDate::deleteChatMessagesByDate()
  : chat_id_()
  , min_date_()
  , max_date_()
  , revoke_()
{}

deleteChatMessagesByDate::deleteChatMessagesByDate(int53 chat_id_, int32 min_date_, int32 max_date_, bool revoke_)
  : chat_id_(chat_id_)
  , min_date_(min_date_)
  , max_date_(max_date_)
  , revoke_(revoke_)
{}

const std::int32_t deleteChatMessagesByDate::ID;

void deleteChatMessagesByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatMessagesByDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

deleteChatMessagesBySender::deleteChatMessagesBySender()
  : chat_id_()
  , sender_id_()
{}

deleteChatMessagesBySender::deleteChatMessagesBySender(int53 chat_id_, object_ptr<MessageSender> &&sender_id_)
  : chat_id_(chat_id_)
  , sender_id_(std::move(sender_id_))
{}

const std::int32_t deleteChatMessagesBySender::ID;

void deleteChatMessagesBySender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatMessagesBySender");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_class_end();
  }
}

deleteChatReplyMarkup::deleteChatReplyMarkup()
  : chat_id_()
  , message_id_()
{}

deleteChatReplyMarkup::deleteChatReplyMarkup(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t deleteChatReplyMarkup::ID;

void deleteChatReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatReplyMarkup");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

deleteCommands::deleteCommands()
  : scope_()
  , language_code_()
{}

deleteCommands::deleteCommands(object_ptr<BotCommandScope> &&scope_, string const &language_code_)
  : scope_(std::move(scope_))
  , language_code_(language_code_)
{}

const std::int32_t deleteCommands::ID;

void deleteCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

deleteFile::deleteFile()
  : file_id_()
{}

deleteFile::deleteFile(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t deleteFile::ID;

void deleteFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteFile");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

deleteLanguagePack::deleteLanguagePack()
  : language_pack_id_()
{}

deleteLanguagePack::deleteLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t deleteLanguagePack::ID;

void deleteLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

deleteMessages::deleteMessages()
  : chat_id_()
  , message_ids_()
  , revoke_()
{}

deleteMessages::deleteMessages(int53 chat_id_, array<int53> &&message_ids_, bool revoke_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
  , revoke_(revoke_)
{}

const std::int32_t deleteMessages::ID;

void deleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

deletePassportElement::deletePassportElement()
  : type_()
{}

deletePassportElement::deletePassportElement(object_ptr<PassportElementType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t deletePassportElement::ID;

void deletePassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deletePassportElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

deleteProfilePhoto::deleteProfilePhoto()
  : profile_photo_id_()
{}

deleteProfilePhoto::deleteProfilePhoto(int64 profile_photo_id_)
  : profile_photo_id_(profile_photo_id_)
{}

const std::int32_t deleteProfilePhoto::ID;

void deleteProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteProfilePhoto");
    s.store_field("profile_photo_id", profile_photo_id_);
    s.store_class_end();
  }
}

deleteRevokedChatInviteLink::deleteRevokedChatInviteLink()
  : chat_id_()
  , invite_link_()
{}

deleteRevokedChatInviteLink::deleteRevokedChatInviteLink(int53 chat_id_, string const &invite_link_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
{}

const std::int32_t deleteRevokedChatInviteLink::ID;

void deleteRevokedChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteRevokedChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

deleteSavedCredentials::deleteSavedCredentials() {
}

const std::int32_t deleteSavedCredentials::ID;

void deleteSavedCredentials::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteSavedCredentials");
    s.store_class_end();
  }
}

deleteSavedOrderInfo::deleteSavedOrderInfo() {
}

const std::int32_t deleteSavedOrderInfo::ID;

void deleteSavedOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteSavedOrderInfo");
    s.store_class_end();
  }
}

destroy::destroy() {
}

const std::int32_t destroy::ID;

void destroy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "destroy");
    s.store_class_end();
  }
}

disableProxy::disableProxy() {
}

const std::int32_t disableProxy::ID;

void disableProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disableProxy");
    s.store_class_end();
  }
}

discardCall::discardCall()
  : call_id_()
  , is_disconnected_()
  , duration_()
  , is_video_()
  , connection_id_()
{}

discardCall::discardCall(int32 call_id_, bool is_disconnected_, int32 duration_, bool is_video_, int64 connection_id_)
  : call_id_(call_id_)
  , is_disconnected_(is_disconnected_)
  , duration_(duration_)
  , is_video_(is_video_)
  , connection_id_(connection_id_)
{}

const std::int32_t discardCall::ID;

void discardCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "discardCall");
    s.store_field("call_id", call_id_);
    s.store_field("is_disconnected", is_disconnected_);
    s.store_field("duration", duration_);
    s.store_field("is_video", is_video_);
    s.store_field("connection_id", connection_id_);
    s.store_class_end();
  }
}

disconnectAllWebsites::disconnectAllWebsites() {
}

const std::int32_t disconnectAllWebsites::ID;

void disconnectAllWebsites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disconnectAllWebsites");
    s.store_class_end();
  }
}

disconnectWebsite::disconnectWebsite()
  : website_id_()
{}

disconnectWebsite::disconnectWebsite(int64 website_id_)
  : website_id_(website_id_)
{}

const std::int32_t disconnectWebsite::ID;

void disconnectWebsite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disconnectWebsite");
    s.store_field("website_id", website_id_);
    s.store_class_end();
  }
}

downloadFile::downloadFile()
  : file_id_()
  , priority_()
  , offset_()
  , limit_()
  , synchronous_()
{}

downloadFile::downloadFile(int32 file_id_, int32 priority_, int32 offset_, int32 limit_, bool synchronous_)
  : file_id_(file_id_)
  , priority_(priority_)
  , offset_(offset_)
  , limit_(limit_)
  , synchronous_(synchronous_)
{}

const std::int32_t downloadFile::ID;

void downloadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "downloadFile");
    s.store_field("file_id", file_id_);
    s.store_field("priority", priority_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("synchronous", synchronous_);
    s.store_class_end();
  }
}

editChatFilter::editChatFilter()
  : chat_filter_id_()
  , filter_()
{}

editChatFilter::editChatFilter(int32 chat_filter_id_, object_ptr<chatFilter> &&filter_)
  : chat_filter_id_(chat_filter_id_)
  , filter_(std::move(filter_))
{}

const std::int32_t editChatFilter::ID;

void editChatFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editChatFilter");
    s.store_field("chat_filter_id", chat_filter_id_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_class_end();
  }
}

editChatInviteLink::editChatInviteLink()
  : chat_id_()
  , invite_link_()
  , name_()
  , expiration_date_()
  , member_limit_()
  , creates_join_request_()
{}

editChatInviteLink::editChatInviteLink(int53 chat_id_, string const &invite_link_, string const &name_, int32 expiration_date_, int32 member_limit_, bool creates_join_request_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , name_(name_)
  , expiration_date_(expiration_date_)
  , member_limit_(member_limit_)
  , creates_join_request_(creates_join_request_)
{}

const std::int32_t editChatInviteLink::ID;

void editChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("member_limit", member_limit_);
    s.store_field("creates_join_request", creates_join_request_);
    s.store_class_end();
  }
}

editCustomLanguagePackInfo::editCustomLanguagePackInfo()
  : info_()
{}

editCustomLanguagePackInfo::editCustomLanguagePackInfo(object_ptr<languagePackInfo> &&info_)
  : info_(std::move(info_))
{}

const std::int32_t editCustomLanguagePackInfo::ID;

void editCustomLanguagePackInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editCustomLanguagePackInfo");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

editInlineMessageCaption::editInlineMessageCaption()
  : inline_message_id_()
  , reply_markup_()
  , caption_()
{}

editInlineMessageCaption::editInlineMessageCaption(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<formattedText> &&caption_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , caption_(std::move(caption_))
{}

const std::int32_t editInlineMessageCaption::ID;

void editInlineMessageCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageCaption");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

editInlineMessageLiveLocation::editInlineMessageLiveLocation()
  : inline_message_id_()
  , reply_markup_()
  , location_()
  , heading_()
  , proximity_alert_radius_()
{}

editInlineMessageLiveLocation::editInlineMessageLiveLocation(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<location> &&location_, int32 heading_, int32 proximity_alert_radius_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , location_(std::move(location_))
  , heading_(heading_)
  , proximity_alert_radius_(proximity_alert_radius_)
{}

const std::int32_t editInlineMessageLiveLocation::ID;

void editInlineMessageLiveLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageLiveLocation");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("heading", heading_);
    s.store_field("proximity_alert_radius", proximity_alert_radius_);
    s.store_class_end();
  }
}

editInlineMessageMedia::editInlineMessageMedia()
  : inline_message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editInlineMessageMedia::editInlineMessageMedia(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editInlineMessageMedia::ID;

void editInlineMessageMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageMedia");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editInlineMessageReplyMarkup::editInlineMessageReplyMarkup()
  : inline_message_id_()
  , reply_markup_()
{}

editInlineMessageReplyMarkup::editInlineMessageReplyMarkup(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t editInlineMessageReplyMarkup::ID;

void editInlineMessageReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageReplyMarkup");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

editInlineMessageText::editInlineMessageText()
  : inline_message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editInlineMessageText::editInlineMessageText(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editInlineMessageText::ID;

void editInlineMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageText");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editMessageCaption::editMessageCaption()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , caption_()
{}

editMessageCaption::editMessageCaption(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<formattedText> &&caption_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , caption_(std::move(caption_))
{}

const std::int32_t editMessageCaption::ID;

void editMessageCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageCaption");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

editMessageLiveLocation::editMessageLiveLocation()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , location_()
  , heading_()
  , proximity_alert_radius_()
{}

editMessageLiveLocation::editMessageLiveLocation(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<location> &&location_, int32 heading_, int32 proximity_alert_radius_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , location_(std::move(location_))
  , heading_(heading_)
  , proximity_alert_radius_(proximity_alert_radius_)
{}

const std::int32_t editMessageLiveLocation::ID;

void editMessageLiveLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageLiveLocation");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("heading", heading_);
    s.store_field("proximity_alert_radius", proximity_alert_radius_);
    s.store_class_end();
  }
}

editMessageMedia::editMessageMedia()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editMessageMedia::editMessageMedia(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editMessageMedia::ID;

void editMessageMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageMedia");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editMessageReplyMarkup::editMessageReplyMarkup()
  : chat_id_()
  , message_id_()
  , reply_markup_()
{}

editMessageReplyMarkup::editMessageReplyMarkup(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t editMessageReplyMarkup::ID;

void editMessageReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageReplyMarkup");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

editMessageSchedulingState::editMessageSchedulingState()
  : chat_id_()
  , message_id_()
  , scheduling_state_()
{}

editMessageSchedulingState::editMessageSchedulingState(int53 chat_id_, int53 message_id_, object_ptr<MessageSchedulingState> &&scheduling_state_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , scheduling_state_(std::move(scheduling_state_))
{}

const std::int32_t editMessageSchedulingState::ID;

void editMessageSchedulingState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageSchedulingState");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("scheduling_state", static_cast<const BaseObject *>(scheduling_state_.get()));
    s.store_class_end();
  }
}

editMessageText::editMessageText()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editMessageText::editMessageText(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editMessageText::ID;

void editMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageText");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editProxy::editProxy()
  : proxy_id_()
  , server_()
  , port_()
  , enable_()
  , type_()
{}

editProxy::editProxy(int32 proxy_id_, string const &server_, int32 port_, bool enable_, object_ptr<ProxyType> &&type_)
  : proxy_id_(proxy_id_)
  , server_(server_)
  , port_(port_)
  , enable_(enable_)
  , type_(std::move(type_))
{}

const std::int32_t editProxy::ID;

void editProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editProxy");
    s.store_field("proxy_id", proxy_id_);
    s.store_field("server", server_);
    s.store_field("port", port_);
    s.store_field("enable", enable_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

enableProxy::enableProxy()
  : proxy_id_()
{}

enableProxy::enableProxy(int32 proxy_id_)
  : proxy_id_(proxy_id_)
{}

const std::int32_t enableProxy::ID;

void enableProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "enableProxy");
    s.store_field("proxy_id", proxy_id_);
    s.store_class_end();
  }
}

endGroupCall::endGroupCall()
  : group_call_id_()
{}

endGroupCall::endGroupCall(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t endGroupCall::ID;

void endGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "endGroupCall");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

endGroupCallRecording::endGroupCallRecording()
  : group_call_id_()
{}

endGroupCallRecording::endGroupCallRecording(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t endGroupCallRecording::ID;

void endGroupCallRecording::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "endGroupCallRecording");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

endGroupCallScreenSharing::endGroupCallScreenSharing()
  : group_call_id_()
{}

endGroupCallScreenSharing::endGroupCallScreenSharing(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t endGroupCallScreenSharing::ID;

void endGroupCallScreenSharing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "endGroupCallScreenSharing");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

finishFileGeneration::finishFileGeneration()
  : generation_id_()
  , error_()
{}

finishFileGeneration::finishFileGeneration(int64 generation_id_, object_ptr<error> &&error_)
  : generation_id_(generation_id_)
  , error_(std::move(error_))
{}

const std::int32_t finishFileGeneration::ID;

void finishFileGeneration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "finishFileGeneration");
    s.store_field("generation_id", generation_id_);
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

forwardMessages::forwardMessages()
  : chat_id_()
  , from_chat_id_()
  , message_ids_()
  , options_()
  , send_copy_()
  , remove_caption_()
  , only_preview_()
{}

forwardMessages::forwardMessages(int53 chat_id_, int53 from_chat_id_, array<int53> &&message_ids_, object_ptr<messageSendOptions> &&options_, bool send_copy_, bool remove_caption_, bool only_preview_)
  : chat_id_(chat_id_)
  , from_chat_id_(from_chat_id_)
  , message_ids_(std::move(message_ids_))
  , options_(std::move(options_))
  , send_copy_(send_copy_)
  , remove_caption_(remove_caption_)
  , only_preview_(only_preview_)
{}

const std::int32_t forwardMessages::ID;

void forwardMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forwardMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("from_chat_id", from_chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_field("send_copy", send_copy_);
    s.store_field("remove_caption", remove_caption_);
    s.store_field("only_preview", only_preview_);
    s.store_class_end();
  }
}

getAccountTtl::getAccountTtl() {
}

const std::int32_t getAccountTtl::ID;

void getAccountTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAccountTtl");
    s.store_class_end();
  }
}

getActiveLiveLocationMessages::getActiveLiveLocationMessages() {
}

const std::int32_t getActiveLiveLocationMessages::ID;

void getActiveLiveLocationMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getActiveLiveLocationMessages");
    s.store_class_end();
  }
}

getActiveSessions::getActiveSessions() {
}

const std::int32_t getActiveSessions::ID;

void getActiveSessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getActiveSessions");
    s.store_class_end();
  }
}

getAllPassportElements::getAllPassportElements()
  : password_()
{}

getAllPassportElements::getAllPassportElements(string const &password_)
  : password_(password_)
{}

const std::int32_t getAllPassportElements::ID;

void getAllPassportElements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAllPassportElements");
    s.store_field("password", password_);
    s.store_class_end();
  }
}

getAnimatedEmoji::getAnimatedEmoji()
  : emoji_()
{}

getAnimatedEmoji::getAnimatedEmoji(string const &emoji_)
  : emoji_(emoji_)
{}

const std::int32_t getAnimatedEmoji::ID;

void getAnimatedEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAnimatedEmoji");
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

getApplicationConfig::getApplicationConfig() {
}

const std::int32_t getApplicationConfig::ID;

void getApplicationConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getApplicationConfig");
    s.store_class_end();
  }
}

getApplicationDownloadLink::getApplicationDownloadLink() {
}

const std::int32_t getApplicationDownloadLink::ID;

void getApplicationDownloadLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getApplicationDownloadLink");
    s.store_class_end();
  }
}

getArchivedStickerSets::getArchivedStickerSets()
  : is_masks_()
  , offset_sticker_set_id_()
  , limit_()
{}

getArchivedStickerSets::getArchivedStickerSets(bool is_masks_, int64 offset_sticker_set_id_, int32 limit_)
  : is_masks_(is_masks_)
  , offset_sticker_set_id_(offset_sticker_set_id_)
  , limit_(limit_)
{}

const std::int32_t getArchivedStickerSets::ID;

void getArchivedStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getArchivedStickerSets");
    s.store_field("is_masks", is_masks_);
    s.store_field("offset_sticker_set_id", offset_sticker_set_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getAttachedStickerSets::getAttachedStickerSets()
  : file_id_()
{}

getAttachedStickerSets::getAttachedStickerSets(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t getAttachedStickerSets::ID;

void getAttachedStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAttachedStickerSets");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

getAttachmentMenuBot::getAttachmentMenuBot()
  : bot_user_id_()
{}

getAttachmentMenuBot::getAttachmentMenuBot(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t getAttachmentMenuBot::ID;

void getAttachmentMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAttachmentMenuBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

getAuthorizationState::getAuthorizationState() {
}

const std::int32_t getAuthorizationState::ID;

void getAuthorizationState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAuthorizationState");
    s.store_class_end();
  }
}

getAutoDownloadSettingsPresets::getAutoDownloadSettingsPresets() {
}

const std::int32_t getAutoDownloadSettingsPresets::ID;

void getAutoDownloadSettingsPresets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAutoDownloadSettingsPresets");
    s.store_class_end();
  }
}

getBackgroundUrl::getBackgroundUrl()
  : name_()
  , type_()
{}

getBackgroundUrl::getBackgroundUrl(string const &name_, object_ptr<BackgroundType> &&type_)
  : name_(name_)
  , type_(std::move(type_))
{}

const std::int32_t getBackgroundUrl::ID;

void getBackgroundUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBackgroundUrl");
    s.store_field("name", name_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

getBackgrounds::getBackgrounds()
  : for_dark_theme_()
{}

getBackgrounds::getBackgrounds(bool for_dark_theme_)
  : for_dark_theme_(for_dark_theme_)
{}

const std::int32_t getBackgrounds::ID;

void getBackgrounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBackgrounds");
    s.store_field("for_dark_theme", for_dark_theme_);
    s.store_class_end();
  }
}

getBankCardInfo::getBankCardInfo()
  : bank_card_number_()
{}

getBankCardInfo::getBankCardInfo(string const &bank_card_number_)
  : bank_card_number_(bank_card_number_)
{}

const std::int32_t getBankCardInfo::ID;

void getBankCardInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBankCardInfo");
    s.store_field("bank_card_number", bank_card_number_);
    s.store_class_end();
  }
}

getBasicGroup::getBasicGroup()
  : basic_group_id_()
{}

getBasicGroup::getBasicGroup(int53 basic_group_id_)
  : basic_group_id_(basic_group_id_)
{}

const std::int32_t getBasicGroup::ID;

void getBasicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBasicGroup");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

getBasicGroupFullInfo::getBasicGroupFullInfo()
  : basic_group_id_()
{}

getBasicGroupFullInfo::getBasicGroupFullInfo(int53 basic_group_id_)
  : basic_group_id_(basic_group_id_)
{}

const std::int32_t getBasicGroupFullInfo::ID;

void getBasicGroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBasicGroupFullInfo");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_class_end();
  }
}

getBlockedMessageSenders::getBlockedMessageSenders()
  : offset_()
  , limit_()
{}

getBlockedMessageSenders::getBlockedMessageSenders(int32 offset_, int32 limit_)
  : offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getBlockedMessageSenders::ID;

void getBlockedMessageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBlockedMessageSenders");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getCallbackQueryAnswer::getCallbackQueryAnswer()
  : chat_id_()
  , message_id_()
  , payload_()
{}

getCallbackQueryAnswer::getCallbackQueryAnswer(int53 chat_id_, int53 message_id_, object_ptr<CallbackQueryPayload> &&payload_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , payload_(std::move(payload_))
{}

const std::int32_t getCallbackQueryAnswer::ID;

void getCallbackQueryAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCallbackQueryAnswer");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("payload", static_cast<const BaseObject *>(payload_.get()));
    s.store_class_end();
  }
}

getCallbackQueryMessage::getCallbackQueryMessage()
  : chat_id_()
  , message_id_()
  , callback_query_id_()
{}

getCallbackQueryMessage::getCallbackQueryMessage(int53 chat_id_, int53 message_id_, int64 callback_query_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , callback_query_id_(callback_query_id_)
{}

const std::int32_t getCallbackQueryMessage::ID;

void getCallbackQueryMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCallbackQueryMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("callback_query_id", callback_query_id_);
    s.store_class_end();
  }
}

getChat::getChat()
  : chat_id_()
{}

getChat::getChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChat::ID;

void getChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatAdministrators::getChatAdministrators()
  : chat_id_()
{}

getChatAdministrators::getChatAdministrators(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatAdministrators::ID;

void getChatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatAdministrators");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatAvailableMessageSenders::getChatAvailableMessageSenders()
  : chat_id_()
{}

getChatAvailableMessageSenders::getChatAvailableMessageSenders(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatAvailableMessageSenders::ID;

void getChatAvailableMessageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatAvailableMessageSenders");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatEventLog::getChatEventLog()
  : chat_id_()
  , query_()
  , from_event_id_()
  , limit_()
  , filters_()
  , user_ids_()
{}

getChatEventLog::getChatEventLog(int53 chat_id_, string const &query_, int64 from_event_id_, int32 limit_, object_ptr<chatEventLogFilters> &&filters_, array<int53> &&user_ids_)
  : chat_id_(chat_id_)
  , query_(query_)
  , from_event_id_(from_event_id_)
  , limit_(limit_)
  , filters_(std::move(filters_))
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t getChatEventLog::ID;

void getChatEventLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatEventLog");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_field("from_event_id", from_event_id_);
    s.store_field("limit", limit_);
    s.store_object_field("filters", static_cast<const BaseObject *>(filters_.get()));
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getChatFilter::getChatFilter()
  : chat_filter_id_()
{}

getChatFilter::getChatFilter(int32 chat_filter_id_)
  : chat_filter_id_(chat_filter_id_)
{}

const std::int32_t getChatFilter::ID;

void getChatFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFilter");
    s.store_field("chat_filter_id", chat_filter_id_);
    s.store_class_end();
  }
}

getChatFilterDefaultIconName::getChatFilterDefaultIconName()
  : filter_()
{}

getChatFilterDefaultIconName::getChatFilterDefaultIconName(object_ptr<chatFilter> &&filter_)
  : filter_(std::move(filter_))
{}

const std::int32_t getChatFilterDefaultIconName::ID;

void getChatFilterDefaultIconName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFilterDefaultIconName");
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_class_end();
  }
}

getChatHistory::getChatHistory()
  : chat_id_()
  , from_message_id_()
  , offset_()
  , limit_()
  , only_local_()
{}

getChatHistory::getChatHistory(int53 chat_id_, int53 from_message_id_, int32 offset_, int32 limit_, bool only_local_)
  : chat_id_(chat_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
  , only_local_(only_local_)
{}

const std::int32_t getChatHistory::ID;

void getChatHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

getChatInviteLink::getChatInviteLink()
  : chat_id_()
  , invite_link_()
{}

getChatInviteLink::getChatInviteLink(int53 chat_id_, string const &invite_link_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
{}

const std::int32_t getChatInviteLink::ID;

void getChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

getChatInviteLinkCounts::getChatInviteLinkCounts()
  : chat_id_()
{}

getChatInviteLinkCounts::getChatInviteLinkCounts(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatInviteLinkCounts::ID;

void getChatInviteLinkCounts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLinkCounts");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatInviteLinkMembers::getChatInviteLinkMembers()
  : chat_id_()
  , invite_link_()
  , offset_member_()
  , limit_()
{}

getChatInviteLinkMembers::getChatInviteLinkMembers(int53 chat_id_, string const &invite_link_, object_ptr<chatInviteLinkMember> &&offset_member_, int32 limit_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , offset_member_(std::move(offset_member_))
  , limit_(limit_)
{}

const std::int32_t getChatInviteLinkMembers::ID;

void getChatInviteLinkMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLinkMembers");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_object_field("offset_member", static_cast<const BaseObject *>(offset_member_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatInviteLinks::getChatInviteLinks()
  : chat_id_()
  , creator_user_id_()
  , is_revoked_()
  , offset_date_()
  , offset_invite_link_()
  , limit_()
{}

getChatInviteLinks::getChatInviteLinks(int53 chat_id_, int53 creator_user_id_, bool is_revoked_, int32 offset_date_, string const &offset_invite_link_, int32 limit_)
  : chat_id_(chat_id_)
  , creator_user_id_(creator_user_id_)
  , is_revoked_(is_revoked_)
  , offset_date_(offset_date_)
  , offset_invite_link_(offset_invite_link_)
  , limit_(limit_)
{}

const std::int32_t getChatInviteLinks::ID;

void getChatInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLinks");
    s.store_field("chat_id", chat_id_);
    s.store_field("creator_user_id", creator_user_id_);
    s.store_field("is_revoked", is_revoked_);
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_invite_link", offset_invite_link_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatJoinRequests::getChatJoinRequests()
  : chat_id_()
  , invite_link_()
  , query_()
  , offset_request_()
  , limit_()
{}

getChatJoinRequests::getChatJoinRequests(int53 chat_id_, string const &invite_link_, string const &query_, object_ptr<chatJoinRequest> &&offset_request_, int32 limit_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , query_(query_)
  , offset_request_(std::move(offset_request_))
  , limit_(limit_)
{}

const std::int32_t getChatJoinRequests::ID;

void getChatJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatJoinRequests");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("query", query_);
    s.store_object_field("offset_request", static_cast<const BaseObject *>(offset_request_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatListsToAddChat::getChatListsToAddChat()
  : chat_id_()
{}

getChatListsToAddChat::getChatListsToAddChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatListsToAddChat::ID;

void getChatListsToAddChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatListsToAddChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatMember::getChatMember()
  : chat_id_()
  , member_id_()
{}

getChatMember::getChatMember(int53 chat_id_, object_ptr<MessageSender> &&member_id_)
  : chat_id_(chat_id_)
  , member_id_(std::move(member_id_))
{}

const std::int32_t getChatMember::ID;

void getChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_class_end();
  }
}

getChatMessageByDate::getChatMessageByDate()
  : chat_id_()
  , date_()
{}

getChatMessageByDate::getChatMessageByDate(int53 chat_id_, int32 date_)
  : chat_id_(chat_id_)
  , date_(date_)
{}

const std::int32_t getChatMessageByDate::ID;

void getChatMessageByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessageByDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

getChatMessageCalendar::getChatMessageCalendar()
  : chat_id_()
  , filter_()
  , from_message_id_()
{}

getChatMessageCalendar::getChatMessageCalendar(int53 chat_id_, object_ptr<SearchMessagesFilter> &&filter_, int53 from_message_id_)
  : chat_id_(chat_id_)
  , filter_(std::move(filter_))
  , from_message_id_(from_message_id_)
{}

const std::int32_t getChatMessageCalendar::ID;

void getChatMessageCalendar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessageCalendar");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("from_message_id", from_message_id_);
    s.store_class_end();
  }
}

getChatMessageCount::getChatMessageCount()
  : chat_id_()
  , filter_()
  , return_local_()
{}

getChatMessageCount::getChatMessageCount(int53 chat_id_, object_ptr<SearchMessagesFilter> &&filter_, bool return_local_)
  : chat_id_(chat_id_)
  , filter_(std::move(filter_))
  , return_local_(return_local_)
{}

const std::int32_t getChatMessageCount::ID;

void getChatMessageCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessageCount");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("return_local", return_local_);
    s.store_class_end();
  }
}

getChatNotificationSettingsExceptions::getChatNotificationSettingsExceptions()
  : scope_()
  , compare_sound_()
{}

getChatNotificationSettingsExceptions::getChatNotificationSettingsExceptions(object_ptr<NotificationSettingsScope> &&scope_, bool compare_sound_)
  : scope_(std::move(scope_))
  , compare_sound_(compare_sound_)
{}

const std::int32_t getChatNotificationSettingsExceptions::ID;

void getChatNotificationSettingsExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatNotificationSettingsExceptions");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("compare_sound", compare_sound_);
    s.store_class_end();
  }
}

getChatPinnedMessage::getChatPinnedMessage()
  : chat_id_()
{}

getChatPinnedMessage::getChatPinnedMessage(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatPinnedMessage::ID;

void getChatPinnedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatPinnedMessage");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatScheduledMessages::getChatScheduledMessages()
  : chat_id_()
{}

getChatScheduledMessages::getChatScheduledMessages(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatScheduledMessages::ID;

void getChatScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatScheduledMessages");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatSparseMessagePositions::getChatSparseMessagePositions()
  : chat_id_()
  , filter_()
  , from_message_id_()
  , limit_()
{}

getChatSparseMessagePositions::getChatSparseMessagePositions(int53 chat_id_, object_ptr<SearchMessagesFilter> &&filter_, int53 from_message_id_, int32 limit_)
  : chat_id_(chat_id_)
  , filter_(std::move(filter_))
  , from_message_id_(from_message_id_)
  , limit_(limit_)
{}

const std::int32_t getChatSparseMessagePositions::ID;

void getChatSparseMessagePositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatSparseMessagePositions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("from_message_id", from_message_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatSponsoredMessage::getChatSponsoredMessage()
  : chat_id_()
{}

getChatSponsoredMessage::getChatSponsoredMessage(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatSponsoredMessage::ID;

void getChatSponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatSponsoredMessage");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatStatistics::getChatStatistics()
  : chat_id_()
  , is_dark_()
{}

getChatStatistics::getChatStatistics(int53 chat_id_, bool is_dark_)
  : chat_id_(chat_id_)
  , is_dark_(is_dark_)
{}

const std::int32_t getChatStatistics::ID;

void getChatStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatStatistics");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getChats::getChats()
  : chat_list_()
  , limit_()
{}

getChats::getChats(object_ptr<ChatList> &&chat_list_, int32 limit_)
  : chat_list_(std::move(chat_list_))
  , limit_(limit_)
{}

const std::int32_t getChats::ID;

void getChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChats");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getCommands::getCommands()
  : scope_()
  , language_code_()
{}

getCommands::getCommands(object_ptr<BotCommandScope> &&scope_, string const &language_code_)
  : scope_(std::move(scope_))
  , language_code_(language_code_)
{}

const std::int32_t getCommands::ID;

void getCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getConnectedWebsites::getConnectedWebsites() {
}

const std::int32_t getConnectedWebsites::ID;

void getConnectedWebsites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getConnectedWebsites");
    s.store_class_end();
  }
}

getContacts::getContacts() {
}

const std::int32_t getContacts::ID;

void getContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getContacts");
    s.store_class_end();
  }
}

getCountries::getCountries() {
}

const std::int32_t getCountries::ID;

void getCountries::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCountries");
    s.store_class_end();
  }
}

getCountryCode::getCountryCode() {
}

const std::int32_t getCountryCode::ID;

void getCountryCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCountryCode");
    s.store_class_end();
  }
}

getCreatedPublicChats::getCreatedPublicChats()
  : type_()
{}

getCreatedPublicChats::getCreatedPublicChats(object_ptr<PublicChatType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t getCreatedPublicChats::ID;

void getCreatedPublicChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCreatedPublicChats");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

getCurrentState::getCurrentState() {
}

const std::int32_t getCurrentState::ID;

void getCurrentState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCurrentState");
    s.store_class_end();
  }
}

getDatabaseStatistics::getDatabaseStatistics() {
}

const std::int32_t getDatabaseStatistics::ID;

void getDatabaseStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDatabaseStatistics");
    s.store_class_end();
  }
}

getDeepLinkInfo::getDeepLinkInfo()
  : link_()
{}

getDeepLinkInfo::getDeepLinkInfo(string const &link_)
  : link_(link_)
{}

const std::int32_t getDeepLinkInfo::ID;

void getDeepLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDeepLinkInfo");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

getEmojiSuggestionsUrl::getEmojiSuggestionsUrl()
  : language_code_()
{}

getEmojiSuggestionsUrl::getEmojiSuggestionsUrl(string const &language_code_)
  : language_code_(language_code_)
{}

const std::int32_t getEmojiSuggestionsUrl::ID;

void getEmojiSuggestionsUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getEmojiSuggestionsUrl");
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getExternalLink::getExternalLink()
  : link_()
  , allow_write_access_()
{}

getExternalLink::getExternalLink(string const &link_, bool allow_write_access_)
  : link_(link_)
  , allow_write_access_(allow_write_access_)
{}

const std::int32_t getExternalLink::ID;

void getExternalLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getExternalLink");
    s.store_field("link", link_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_class_end();
  }
}

getExternalLinkInfo::getExternalLinkInfo()
  : link_()
{}

getExternalLinkInfo::getExternalLinkInfo(string const &link_)
  : link_(link_)
{}

const std::int32_t getExternalLinkInfo::ID;

void getExternalLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getExternalLinkInfo");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

getFavoriteStickers::getFavoriteStickers() {
}

const std::int32_t getFavoriteStickers::ID;

void getFavoriteStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFavoriteStickers");
    s.store_class_end();
  }
}

getFile::getFile()
  : file_id_()
{}

getFile::getFile(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t getFile::ID;

void getFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFile");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

getFileDownloadedPrefixSize::getFileDownloadedPrefixSize()
  : file_id_()
  , offset_()
{}

getFileDownloadedPrefixSize::getFileDownloadedPrefixSize(int32 file_id_, int32 offset_)
  : file_id_(file_id_)
  , offset_(offset_)
{}

const std::int32_t getFileDownloadedPrefixSize::ID;

void getFileDownloadedPrefixSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFileDownloadedPrefixSize");
    s.store_field("file_id", file_id_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

getFileExtension::getFileExtension()
  : mime_type_()
{}

getFileExtension::getFileExtension(string const &mime_type_)
  : mime_type_(mime_type_)
{}

const std::int32_t getFileExtension::ID;

void getFileExtension::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFileExtension");
    s.store_field("mime_type", mime_type_);
    s.store_class_end();
  }
}

getFileMimeType::getFileMimeType()
  : file_name_()
{}

getFileMimeType::getFileMimeType(string const &file_name_)
  : file_name_(file_name_)
{}

const std::int32_t getFileMimeType::ID;

void getFileMimeType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFileMimeType");
    s.store_field("file_name", file_name_);
    s.store_class_end();
  }
}

getGameHighScores::getGameHighScores()
  : chat_id_()
  , message_id_()
  , user_id_()
{}

getGameHighScores::getGameHighScores(int53 chat_id_, int53 message_id_, int53 user_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , user_id_(user_id_)
{}

const std::int32_t getGameHighScores::ID;

void getGameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGameHighScores");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getGroupCall::getGroupCall()
  : group_call_id_()
{}

getGroupCall::getGroupCall(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getGroupCall::ID;

void getGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCall");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getGroupCallInviteLink::getGroupCallInviteLink()
  : group_call_id_()
  , can_self_unmute_()
{}

getGroupCallInviteLink::getGroupCallInviteLink(int32 group_call_id_, bool can_self_unmute_)
  : group_call_id_(group_call_id_)
  , can_self_unmute_(can_self_unmute_)
{}

const std::int32_t getGroupCallInviteLink::ID;

void getGroupCallInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCallInviteLink");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("can_self_unmute", can_self_unmute_);
    s.store_class_end();
  }
}

getGroupCallStreamSegment::getGroupCallStreamSegment()
  : group_call_id_()
  , time_offset_()
  , scale_()
  , channel_id_()
  , video_quality_()
{}

getGroupCallStreamSegment::getGroupCallStreamSegment(int32 group_call_id_, int53 time_offset_, int32 scale_, int32 channel_id_, object_ptr<GroupCallVideoQuality> &&video_quality_)
  : group_call_id_(group_call_id_)
  , time_offset_(time_offset_)
  , scale_(scale_)
  , channel_id_(channel_id_)
  , video_quality_(std::move(video_quality_))
{}

const std::int32_t getGroupCallStreamSegment::ID;

void getGroupCallStreamSegment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCallStreamSegment");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("time_offset", time_offset_);
    s.store_field("scale", scale_);
    s.store_field("channel_id", channel_id_);
    s.store_object_field("video_quality", static_cast<const BaseObject *>(video_quality_.get()));
    s.store_class_end();
  }
}

getGroupCallStreams::getGroupCallStreams()
  : group_call_id_()
{}

getGroupCallStreams::getGroupCallStreams(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getGroupCallStreams::ID;

void getGroupCallStreams::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCallStreams");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getGroupsInCommon::getGroupsInCommon()
  : user_id_()
  , offset_chat_id_()
  , limit_()
{}

getGroupsInCommon::getGroupsInCommon(int53 user_id_, int53 offset_chat_id_, int32 limit_)
  : user_id_(user_id_)
  , offset_chat_id_(offset_chat_id_)
  , limit_(limit_)
{}

const std::int32_t getGroupsInCommon::ID;

void getGroupsInCommon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupsInCommon");
    s.store_field("user_id", user_id_);
    s.store_field("offset_chat_id", offset_chat_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getImportedContactCount::getImportedContactCount() {
}

const std::int32_t getImportedContactCount::ID;

void getImportedContactCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getImportedContactCount");
    s.store_class_end();
  }
}

getInactiveSupergroupChats::getInactiveSupergroupChats() {
}

const std::int32_t getInactiveSupergroupChats::ID;

void getInactiveSupergroupChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInactiveSupergroupChats");
    s.store_class_end();
  }
}

getInlineGameHighScores::getInlineGameHighScores()
  : inline_message_id_()
  , user_id_()
{}

getInlineGameHighScores::getInlineGameHighScores(string const &inline_message_id_, int53 user_id_)
  : inline_message_id_(inline_message_id_)
  , user_id_(user_id_)
{}

const std::int32_t getInlineGameHighScores::ID;

void getInlineGameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInlineGameHighScores");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getInlineQueryResults::getInlineQueryResults()
  : bot_user_id_()
  , chat_id_()
  , user_location_()
  , query_()
  , offset_()
{}

getInlineQueryResults::getInlineQueryResults(int53 bot_user_id_, int53 chat_id_, object_ptr<location> &&user_location_, string const &query_, string const &offset_)
  : bot_user_id_(bot_user_id_)
  , chat_id_(chat_id_)
  , user_location_(std::move(user_location_))
  , query_(query_)
  , offset_(offset_)
{}

const std::int32_t getInlineQueryResults::ID;

void getInlineQueryResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInlineQueryResults");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("user_location", static_cast<const BaseObject *>(user_location_.get()));
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

getInstalledStickerSets::getInstalledStickerSets()
  : is_masks_()
{}

getInstalledStickerSets::getInstalledStickerSets(bool is_masks_)
  : is_masks_(is_masks_)
{}

const std::int32_t getInstalledStickerSets::ID;

void getInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInstalledStickerSets");
    s.store_field("is_masks", is_masks_);
    s.store_class_end();
  }
}

getInternalLinkType::getInternalLinkType()
  : link_()
{}

getInternalLinkType::getInternalLinkType(string const &link_)
  : link_(link_)
{}

const std::int32_t getInternalLinkType::ID;

void getInternalLinkType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInternalLinkType");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

getJsonString::getJsonString()
  : json_value_()
{}

getJsonString::getJsonString(object_ptr<JsonValue> &&json_value_)
  : json_value_(std::move(json_value_))
{}

const std::int32_t getJsonString::ID;

void getJsonString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getJsonString");
    s.store_object_field("json_value", static_cast<const BaseObject *>(json_value_.get()));
    s.store_class_end();
  }
}

getJsonValue::getJsonValue()
  : json_()
{}

getJsonValue::getJsonValue(string const &json_)
  : json_(json_)
{}

const std::int32_t getJsonValue::ID;

void getJsonValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getJsonValue");
    s.store_field("json", json_);
    s.store_class_end();
  }
}

getLanguagePackInfo::getLanguagePackInfo()
  : language_pack_id_()
{}

getLanguagePackInfo::getLanguagePackInfo(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t getLanguagePackInfo::ID;

void getLanguagePackInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLanguagePackInfo");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

getLanguagePackString::getLanguagePackString()
  : language_pack_database_path_()
  , localization_target_()
  , language_pack_id_()
  , key_()
{}

getLanguagePackString::getLanguagePackString(string const &language_pack_database_path_, string const &localization_target_, string const &language_pack_id_, string const &key_)
  : language_pack_database_path_(language_pack_database_path_)
  , localization_target_(localization_target_)
  , language_pack_id_(language_pack_id_)
  , key_(key_)
{}

const std::int32_t getLanguagePackString::ID;

void getLanguagePackString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLanguagePackString");
    s.store_field("language_pack_database_path", language_pack_database_path_);
    s.store_field("localization_target", localization_target_);
    s.store_field("language_pack_id", language_pack_id_);
    s.store_field("key", key_);
    s.store_class_end();
  }
}

getLanguagePackStrings::getLanguagePackStrings()
  : language_pack_id_()
  , keys_()
{}

getLanguagePackStrings::getLanguagePackStrings(string const &language_pack_id_, array<string> &&keys_)
  : language_pack_id_(language_pack_id_)
  , keys_(std::move(keys_))
{}

const std::int32_t getLanguagePackStrings::ID;

void getLanguagePackStrings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLanguagePackStrings");
    s.store_field("language_pack_id", language_pack_id_);
    { s.store_vector_begin("keys", keys_.size()); for (const auto &_value : keys_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getLocalizationTargetInfo::getLocalizationTargetInfo()
  : only_local_()
{}

getLocalizationTargetInfo::getLocalizationTargetInfo(bool only_local_)
  : only_local_(only_local_)
{}

const std::int32_t getLocalizationTargetInfo::ID;

void getLocalizationTargetInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLocalizationTargetInfo");
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

getLogStream::getLogStream() {
}

const std::int32_t getLogStream::ID;

void getLogStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogStream");
    s.store_class_end();
  }
}

getLogTagVerbosityLevel::getLogTagVerbosityLevel()
  : tag_()
{}

getLogTagVerbosityLevel::getLogTagVerbosityLevel(string const &tag_)
  : tag_(tag_)
{}

const std::int32_t getLogTagVerbosityLevel::ID;

void getLogTagVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogTagVerbosityLevel");
    s.store_field("tag", tag_);
    s.store_class_end();
  }
}

getLogTags::getLogTags() {
}

const std::int32_t getLogTags::ID;

void getLogTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogTags");
    s.store_class_end();
  }
}

getLogVerbosityLevel::getLogVerbosityLevel() {
}

const std::int32_t getLogVerbosityLevel::ID;

void getLogVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogVerbosityLevel");
    s.store_class_end();
  }
}

getLoginUrl::getLoginUrl()
  : chat_id_()
  , message_id_()
  , button_id_()
  , allow_write_access_()
{}

getLoginUrl::getLoginUrl(int53 chat_id_, int53 message_id_, int53 button_id_, bool allow_write_access_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , button_id_(button_id_)
  , allow_write_access_(allow_write_access_)
{}

const std::int32_t getLoginUrl::ID;

void getLoginUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLoginUrl");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("button_id", button_id_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_class_end();
  }
}

getLoginUrlInfo::getLoginUrlInfo()
  : chat_id_()
  , message_id_()
  , button_id_()
{}

getLoginUrlInfo::getLoginUrlInfo(int53 chat_id_, int53 message_id_, int53 button_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , button_id_(button_id_)
{}

const std::int32_t getLoginUrlInfo::ID;

void getLoginUrlInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLoginUrlInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("button_id", button_id_);
    s.store_class_end();
  }
}

getMapThumbnailFile::getMapThumbnailFile()
  : location_()
  , zoom_()
  , width_()
  , height_()
  , scale_()
  , chat_id_()
{}

getMapThumbnailFile::getMapThumbnailFile(object_ptr<location> &&location_, int32 zoom_, int32 width_, int32 height_, int32 scale_, int53 chat_id_)
  : location_(std::move(location_))
  , zoom_(zoom_)
  , width_(width_)
  , height_(height_)
  , scale_(scale_)
  , chat_id_(chat_id_)
{}

const std::int32_t getMapThumbnailFile::ID;

void getMapThumbnailFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMapThumbnailFile");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("zoom", zoom_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("scale", scale_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getMarkdownText::getMarkdownText()
  : text_()
{}

getMarkdownText::getMarkdownText(object_ptr<formattedText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t getMarkdownText::ID;

void getMarkdownText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMarkdownText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

getMe::getMe() {
}

const std::int32_t getMe::ID;

void getMe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMe");
    s.store_class_end();
  }
}

getMenuButton::getMenuButton()
  : user_id_()
{}

getMenuButton::getMenuButton(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getMenuButton::ID;

void getMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMenuButton");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getMessage::getMessage()
  : chat_id_()
  , message_id_()
{}

getMessage::getMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessage::ID;

void getMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessageAddedReactions::getMessageAddedReactions()
  : chat_id_()
  , message_id_()
  , reaction_()
  , offset_()
  , limit_()
{}

getMessageAddedReactions::getMessageAddedReactions(int53 chat_id_, int53 message_id_, string const &reaction_, string const &offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reaction_(reaction_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getMessageAddedReactions::ID;

void getMessageAddedReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageAddedReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("reaction", reaction_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getMessageAvailableReactions::getMessageAvailableReactions()
  : chat_id_()
  , message_id_()
{}

getMessageAvailableReactions::getMessageAvailableReactions(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageAvailableReactions::ID;

void getMessageAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageAvailableReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessageEmbeddingCode::getMessageEmbeddingCode()
  : chat_id_()
  , message_id_()
  , for_album_()
{}

getMessageEmbeddingCode::getMessageEmbeddingCode(int53 chat_id_, int53 message_id_, bool for_album_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , for_album_(for_album_)
{}

const std::int32_t getMessageEmbeddingCode::ID;

void getMessageEmbeddingCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageEmbeddingCode");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("for_album", for_album_);
    s.store_class_end();
  }
}

getMessageFileType::getMessageFileType()
  : message_file_head_()
{}

getMessageFileType::getMessageFileType(string const &message_file_head_)
  : message_file_head_(message_file_head_)
{}

const std::int32_t getMessageFileType::ID;

void getMessageFileType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageFileType");
    s.store_field("message_file_head", message_file_head_);
    s.store_class_end();
  }
}

getMessageImportConfirmationText::getMessageImportConfirmationText()
  : chat_id_()
{}

getMessageImportConfirmationText::getMessageImportConfirmationText(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getMessageImportConfirmationText::ID;

void getMessageImportConfirmationText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageImportConfirmationText");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getMessageLink::getMessageLink()
  : chat_id_()
  , message_id_()
  , media_timestamp_()
  , for_album_()
  , for_comment_()
{}

getMessageLink::getMessageLink(int53 chat_id_, int53 message_id_, int32 media_timestamp_, bool for_album_, bool for_comment_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , media_timestamp_(media_timestamp_)
  , for_album_(for_album_)
  , for_comment_(for_comment_)
{}

const std::int32_t getMessageLink::ID;

void getMessageLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("media_timestamp", media_timestamp_);
    s.store_field("for_album", for_album_);
    s.store_field("for_comment", for_comment_);
    s.store_class_end();
  }
}

getMessageLinkInfo::getMessageLinkInfo()
  : url_()
{}

getMessageLinkInfo::getMessageLinkInfo(string const &url_)
  : url_(url_)
{}

const std::int32_t getMessageLinkInfo::ID;

void getMessageLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageLinkInfo");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

getMessageLocally::getMessageLocally()
  : chat_id_()
  , message_id_()
{}

getMessageLocally::getMessageLocally(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageLocally::ID;

void getMessageLocally::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageLocally");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessagePublicForwards::getMessagePublicForwards()
  : chat_id_()
  , message_id_()
  , offset_()
  , limit_()
{}

getMessagePublicForwards::getMessagePublicForwards(int53 chat_id_, int53 message_id_, string const &offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getMessagePublicForwards::ID;

void getMessagePublicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessagePublicForwards");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getMessageStatistics::getMessageStatistics()
  : chat_id_()
  , message_id_()
  , is_dark_()
{}

getMessageStatistics::getMessageStatistics(int53 chat_id_, int53 message_id_, bool is_dark_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_dark_(is_dark_)
{}

const std::int32_t getMessageStatistics::ID;

void getMessageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageStatistics");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getMessageThread::getMessageThread()
  : chat_id_()
  , message_id_()
{}

getMessageThread::getMessageThread(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageThread::ID;

void getMessageThread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageThread");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessageThreadHistory::getMessageThreadHistory()
  : chat_id_()
  , message_id_()
  , from_message_id_()
  , offset_()
  , limit_()
{}

getMessageThreadHistory::getMessageThreadHistory(int53 chat_id_, int53 message_id_, int53 from_message_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getMessageThreadHistory::ID;

void getMessageThreadHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageThreadHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getMessageViewers::getMessageViewers()
  : chat_id_()
  , message_id_()
{}

getMessageViewers::getMessageViewers(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageViewers::ID;

void getMessageViewers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageViewers");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessages::getMessages()
  : chat_id_()
  , message_ids_()
{}

getMessages::getMessages(int53 chat_id_, array<int53> &&message_ids_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t getMessages::ID;

void getMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getNetworkStatistics::getNetworkStatistics()
  : only_current_()
{}

getNetworkStatistics::getNetworkStatistics(bool only_current_)
  : only_current_(only_current_)
{}

const std::int32_t getNetworkStatistics::ID;

void getNetworkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getNetworkStatistics");
    s.store_field("only_current", only_current_);
    s.store_class_end();
  }
}

getOption::getOption()
  : name_()
{}

getOption::getOption(string const &name_)
  : name_(name_)
{}

const std::int32_t getOption::ID;

void getOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOption");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

getPassportAuthorizationForm::getPassportAuthorizationForm()
  : bot_user_id_()
  , scope_()
  , public_key_()
  , nonce_()
{}

getPassportAuthorizationForm::getPassportAuthorizationForm(int53 bot_user_id_, string const &scope_, string const &public_key_, string const &nonce_)
  : bot_user_id_(bot_user_id_)
  , scope_(scope_)
  , public_key_(public_key_)
  , nonce_(nonce_)
{}

const std::int32_t getPassportAuthorizationForm::ID;

void getPassportAuthorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPassportAuthorizationForm");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("scope", scope_);
    s.store_field("public_key", public_key_);
    s.store_field("nonce", nonce_);
    s.store_class_end();
  }
}

getPassportAuthorizationFormAvailableElements::getPassportAuthorizationFormAvailableElements()
  : autorization_form_id_()
  , password_()
{}

getPassportAuthorizationFormAvailableElements::getPassportAuthorizationFormAvailableElements(int32 autorization_form_id_, string const &password_)
  : autorization_form_id_(autorization_form_id_)
  , password_(password_)
{}

const std::int32_t getPassportAuthorizationFormAvailableElements::ID;

void getPassportAuthorizationFormAvailableElements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPassportAuthorizationFormAvailableElements");
    s.store_field("autorization_form_id", autorization_form_id_);
    s.store_field("password", password_);
    s.store_class_end();
  }
}

getPassportElement::getPassportElement()
  : type_()
  , password_()
{}

getPassportElement::getPassportElement(object_ptr<PassportElementType> &&type_, string const &password_)
  : type_(std::move(type_))
  , password_(password_)
{}

const std::int32_t getPassportElement::ID;

void getPassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPassportElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("password", password_);
    s.store_class_end();
  }
}

getPasswordState::getPasswordState() {
}

const std::int32_t getPasswordState::ID;

void getPasswordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPasswordState");
    s.store_class_end();
  }
}

getPaymentForm::getPaymentForm()
  : chat_id_()
  , message_id_()
  , theme_()
{}

getPaymentForm::getPaymentForm(int53 chat_id_, int53 message_id_, object_ptr<themeParameters> &&theme_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , theme_(std::move(theme_))
{}

const std::int32_t getPaymentForm::ID;

void getPaymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPaymentForm");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

getPaymentReceipt::getPaymentReceipt()
  : chat_id_()
  , message_id_()
{}

getPaymentReceipt::getPaymentReceipt(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getPaymentReceipt::ID;

void getPaymentReceipt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPaymentReceipt");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getPhoneNumberInfo::getPhoneNumberInfo()
  : phone_number_prefix_()
{}

getPhoneNumberInfo::getPhoneNumberInfo(string const &phone_number_prefix_)
  : phone_number_prefix_(phone_number_prefix_)
{}

const std::int32_t getPhoneNumberInfo::ID;

void getPhoneNumberInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPhoneNumberInfo");
    s.store_field("phone_number_prefix", phone_number_prefix_);
    s.store_class_end();
  }
}

getPhoneNumberInfoSync::getPhoneNumberInfoSync()
  : language_code_()
  , phone_number_prefix_()
{}

getPhoneNumberInfoSync::getPhoneNumberInfoSync(string const &language_code_, string const &phone_number_prefix_)
  : language_code_(language_code_)
  , phone_number_prefix_(phone_number_prefix_)
{}

const std::int32_t getPhoneNumberInfoSync::ID;

void getPhoneNumberInfoSync::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPhoneNumberInfoSync");
    s.store_field("language_code", language_code_);
    s.store_field("phone_number_prefix", phone_number_prefix_);
    s.store_class_end();
  }
}

getPollVoters::getPollVoters()
  : chat_id_()
  , message_id_()
  , option_id_()
  , offset_()
  , limit_()
{}

getPollVoters::getPollVoters(int53 chat_id_, int53 message_id_, int32 option_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_id_(option_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getPollVoters::ID;

void getPollVoters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPollVoters");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("option_id", option_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getPreferredCountryLanguage::getPreferredCountryLanguage()
  : country_code_()
{}

getPreferredCountryLanguage::getPreferredCountryLanguage(string const &country_code_)
  : country_code_(country_code_)
{}

const std::int32_t getPreferredCountryLanguage::ID;

void getPreferredCountryLanguage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPreferredCountryLanguage");
    s.store_field("country_code", country_code_);
    s.store_class_end();
  }
}

getProxies::getProxies() {
}

const std::int32_t getProxies::ID;

void getProxies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getProxies");
    s.store_class_end();
  }
}

getProxyLink::getProxyLink()
  : proxy_id_()
{}

getProxyLink::getProxyLink(int32 proxy_id_)
  : proxy_id_(proxy_id_)
{}

const std::int32_t getProxyLink::ID;

void getProxyLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getProxyLink");
    s.store_field("proxy_id", proxy_id_);
    s.store_class_end();
  }
}

getPushReceiverId::getPushReceiverId()
  : payload_()
{}

getPushReceiverId::getPushReceiverId(string const &payload_)
  : payload_(payload_)
{}

const std::int32_t getPushReceiverId::ID;

void getPushReceiverId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPushReceiverId");
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

getRecentInlineBots::getRecentInlineBots() {
}

const std::int32_t getRecentInlineBots::ID;

void getRecentInlineBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentInlineBots");
    s.store_class_end();
  }
}

getRecentStickers::getRecentStickers()
  : is_attached_()
{}

getRecentStickers::getRecentStickers(bool is_attached_)
  : is_attached_(is_attached_)
{}

const std::int32_t getRecentStickers::ID;

void getRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentStickers");
    s.store_field("is_attached", is_attached_);
    s.store_class_end();
  }
}

getRecentlyOpenedChats::getRecentlyOpenedChats()
  : limit_()
{}

getRecentlyOpenedChats::getRecentlyOpenedChats(int32 limit_)
  : limit_(limit_)
{}

const std::int32_t getRecentlyOpenedChats::ID;

void getRecentlyOpenedChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentlyOpenedChats");
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getRecentlyVisitedTMeUrls::getRecentlyVisitedTMeUrls()
  : referrer_()
{}

getRecentlyVisitedTMeUrls::getRecentlyVisitedTMeUrls(string const &referrer_)
  : referrer_(referrer_)
{}

const std::int32_t getRecentlyVisitedTMeUrls::ID;

void getRecentlyVisitedTMeUrls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentlyVisitedTMeUrls");
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

getRecommendedChatFilters::getRecommendedChatFilters() {
}

const std::int32_t getRecommendedChatFilters::ID;

void getRecommendedChatFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecommendedChatFilters");
    s.store_class_end();
  }
}

getRecoveryEmailAddress::getRecoveryEmailAddress()
  : password_()
{}

getRecoveryEmailAddress::getRecoveryEmailAddress(string const &password_)
  : password_(password_)
{}

const std::int32_t getRecoveryEmailAddress::ID;

void getRecoveryEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecoveryEmailAddress");
    s.store_field("password", password_);
    s.store_class_end();
  }
}

getRemoteFile::getRemoteFile()
  : remote_file_id_()
  , file_type_()
{}

getRemoteFile::getRemoteFile(string const &remote_file_id_, object_ptr<FileType> &&file_type_)
  : remote_file_id_(remote_file_id_)
  , file_type_(std::move(file_type_))
{}

const std::int32_t getRemoteFile::ID;

void getRemoteFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRemoteFile");
    s.store_field("remote_file_id", remote_file_id_);
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_class_end();
  }
}

getRepliedMessage::getRepliedMessage()
  : chat_id_()
  , message_id_()
{}

getRepliedMessage::getRepliedMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getRepliedMessage::ID;

void getRepliedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRepliedMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getSavedAnimations::getSavedAnimations() {
}

const std::int32_t getSavedAnimations::ID;

void getSavedAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedAnimations");
    s.store_class_end();
  }
}

getSavedNotificationSound::getSavedNotificationSound()
  : notification_sound_id_()
{}

getSavedNotificationSound::getSavedNotificationSound(int64 notification_sound_id_)
  : notification_sound_id_(notification_sound_id_)
{}

const std::int32_t getSavedNotificationSound::ID;

void getSavedNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedNotificationSound");
    s.store_field("notification_sound_id", notification_sound_id_);
    s.store_class_end();
  }
}

getSavedNotificationSounds::getSavedNotificationSounds() {
}

const std::int32_t getSavedNotificationSounds::ID;

void getSavedNotificationSounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedNotificationSounds");
    s.store_class_end();
  }
}

getSavedOrderInfo::getSavedOrderInfo() {
}

const std::int32_t getSavedOrderInfo::ID;

void getSavedOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedOrderInfo");
    s.store_class_end();
  }
}

getScopeNotificationSettings::getScopeNotificationSettings()
  : scope_()
{}

getScopeNotificationSettings::getScopeNotificationSettings(object_ptr<NotificationSettingsScope> &&scope_)
  : scope_(std::move(scope_))
{}

const std::int32_t getScopeNotificationSettings::ID;

void getScopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getScopeNotificationSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_class_end();
  }
}

getSecretChat::getSecretChat()
  : secret_chat_id_()
{}

getSecretChat::getSecretChat(int32 secret_chat_id_)
  : secret_chat_id_(secret_chat_id_)
{}

const std::int32_t getSecretChat::ID;

void getSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSecretChat");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_class_end();
  }
}

getStatisticalGraph::getStatisticalGraph()
  : chat_id_()
  , token_()
  , x_()
{}

getStatisticalGraph::getStatisticalGraph(int53 chat_id_, string const &token_, int53 x_)
  : chat_id_(chat_id_)
  , token_(token_)
  , x_(x_)
{}

const std::int32_t getStatisticalGraph::ID;

void getStatisticalGraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStatisticalGraph");
    s.store_field("chat_id", chat_id_);
    s.store_field("token", token_);
    s.store_field("x", x_);
    s.store_class_end();
  }
}

getStickerEmojis::getStickerEmojis()
  : sticker_()
{}

getStickerEmojis::getStickerEmojis(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t getStickerEmojis::ID;

void getStickerEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerEmojis");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

getStickerSet::getStickerSet()
  : set_id_()
{}

getStickerSet::getStickerSet(int64 set_id_)
  : set_id_(set_id_)
{}

const std::int32_t getStickerSet::ID;

void getStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerSet");
    s.store_field("set_id", set_id_);
    s.store_class_end();
  }
}

getStickers::getStickers()
  : emoji_()
  , limit_()
{}

getStickers::getStickers(string const &emoji_, int32 limit_)
  : emoji_(emoji_)
  , limit_(limit_)
{}

const std::int32_t getStickers::ID;

void getStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickers");
    s.store_field("emoji", emoji_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getStorageStatistics::getStorageStatistics()
  : chat_limit_()
{}

getStorageStatistics::getStorageStatistics(int32 chat_limit_)
  : chat_limit_(chat_limit_)
{}

const std::int32_t getStorageStatistics::ID;

void getStorageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStorageStatistics");
    s.store_field("chat_limit", chat_limit_);
    s.store_class_end();
  }
}

getStorageStatisticsFast::getStorageStatisticsFast() {
}

const std::int32_t getStorageStatisticsFast::ID;

void getStorageStatisticsFast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStorageStatisticsFast");
    s.store_class_end();
  }
}

getSuggestedFileName::getSuggestedFileName()
  : file_id_()
  , directory_()
{}

getSuggestedFileName::getSuggestedFileName(int32 file_id_, string const &directory_)
  : file_id_(file_id_)
  , directory_(directory_)
{}

const std::int32_t getSuggestedFileName::ID;

void getSuggestedFileName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuggestedFileName");
    s.store_field("file_id", file_id_);
    s.store_field("directory", directory_);
    s.store_class_end();
  }
}

getSuggestedStickerSetName::getSuggestedStickerSetName()
  : title_()
{}

getSuggestedStickerSetName::getSuggestedStickerSetName(string const &title_)
  : title_(title_)
{}

const std::int32_t getSuggestedStickerSetName::ID;

void getSuggestedStickerSetName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuggestedStickerSetName");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

getSuitableDiscussionChats::getSuitableDiscussionChats() {
}

const std::int32_t getSuitableDiscussionChats::ID;

void getSuitableDiscussionChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuitableDiscussionChats");
    s.store_class_end();
  }
}

getSupergroup::getSupergroup()
  : supergroup_id_()
{}

getSupergroup::getSupergroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t getSupergroup::ID;

void getSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupergroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

getSupergroupFullInfo::getSupergroupFullInfo()
  : supergroup_id_()
{}

getSupergroupFullInfo::getSupergroupFullInfo(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t getSupergroupFullInfo::ID;

void getSupergroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupergroupFullInfo");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

getSupergroupMembers::getSupergroupMembers()
  : supergroup_id_()
  , filter_()
  , offset_()
  , limit_()
{}

getSupergroupMembers::getSupergroupMembers(int53 supergroup_id_, object_ptr<SupergroupMembersFilter> &&filter_, int32 offset_, int32 limit_)
  : supergroup_id_(supergroup_id_)
  , filter_(std::move(filter_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getSupergroupMembers::ID;

void getSupergroupMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupergroupMembers");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getSupportUser::getSupportUser() {
}

const std::int32_t getSupportUser::ID;

void getSupportUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupportUser");
    s.store_class_end();
  }
}

getTemporaryPasswordState::getTemporaryPasswordState() {
}

const std::int32_t getTemporaryPasswordState::ID;

void getTemporaryPasswordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTemporaryPasswordState");
    s.store_class_end();
  }
}

getTextEntities::getTextEntities()
  : text_()
{}

getTextEntities::getTextEntities(string const &text_)
  : text_(text_)
{}

const std::int32_t getTextEntities::ID;

void getTextEntities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTextEntities");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

getThemeParametersJsonString::getThemeParametersJsonString()
  : theme_()
{}

getThemeParametersJsonString::getThemeParametersJsonString(object_ptr<themeParameters> &&theme_)
  : theme_(std::move(theme_))
{}

const std::int32_t getThemeParametersJsonString::ID;

void getThemeParametersJsonString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getThemeParametersJsonString");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

getTopChats::getTopChats()
  : category_()
  , limit_()
{}

getTopChats::getTopChats(object_ptr<TopChatCategory> &&category_, int32 limit_)
  : category_(std::move(category_))
  , limit_(limit_)
{}

const std::int32_t getTopChats::ID;

void getTopChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTopChats");
    s.store_object_field("category", static_cast<const BaseObject *>(category_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getTrendingStickerSets::getTrendingStickerSets()
  : offset_()
  , limit_()
{}

getTrendingStickerSets::getTrendingStickerSets(int32 offset_, int32 limit_)
  : offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getTrendingStickerSets::ID;

void getTrendingStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTrendingStickerSets");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getUser::getUser()
  : user_id_()
{}

getUser::getUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getUser::ID;

void getUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getUserFullInfo::getUserFullInfo()
  : user_id_()
{}

getUserFullInfo::getUserFullInfo(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getUserFullInfo::ID;

void getUserFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserFullInfo");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getUserPrivacySettingRules::getUserPrivacySettingRules()
  : setting_()
{}

getUserPrivacySettingRules::getUserPrivacySettingRules(object_ptr<UserPrivacySetting> &&setting_)
  : setting_(std::move(setting_))
{}

const std::int32_t getUserPrivacySettingRules::ID;

void getUserPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserPrivacySettingRules");
    s.store_object_field("setting", static_cast<const BaseObject *>(setting_.get()));
    s.store_class_end();
  }
}

getUserProfilePhotos::getUserProfilePhotos()
  : user_id_()
  , offset_()
  , limit_()
{}

getUserProfilePhotos::getUserProfilePhotos(int53 user_id_, int32 offset_, int32 limit_)
  : user_id_(user_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getUserProfilePhotos::ID;

void getUserProfilePhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserProfilePhotos");
    s.store_field("user_id", user_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getVideoChatAvailableParticipants::getVideoChatAvailableParticipants()
  : chat_id_()
{}

getVideoChatAvailableParticipants::getVideoChatAvailableParticipants(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getVideoChatAvailableParticipants::ID;

void getVideoChatAvailableParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getVideoChatAvailableParticipants");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getVideoChatRtmpUrl::getVideoChatRtmpUrl()
  : chat_id_()
{}

getVideoChatRtmpUrl::getVideoChatRtmpUrl(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getVideoChatRtmpUrl::ID;

void getVideoChatRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getVideoChatRtmpUrl");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getWebAppUrl::getWebAppUrl()
  : bot_user_id_()
  , url_()
  , theme_()
{}

getWebAppUrl::getWebAppUrl(int53 bot_user_id_, string const &url_, object_ptr<themeParameters> &&theme_)
  : bot_user_id_(bot_user_id_)
  , url_(url_)
  , theme_(std::move(theme_))
{}

const std::int32_t getWebAppUrl::ID;

void getWebAppUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWebAppUrl");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("url", url_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

getWebPageInstantView::getWebPageInstantView()
  : url_()
  , force_full_()
{}

getWebPageInstantView::getWebPageInstantView(string const &url_, bool force_full_)
  : url_(url_)
  , force_full_(force_full_)
{}

const std::int32_t getWebPageInstantView::ID;

void getWebPageInstantView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWebPageInstantView");
    s.store_field("url", url_);
    s.store_field("force_full", force_full_);
    s.store_class_end();
  }
}

getWebPagePreview::getWebPagePreview()
  : text_()
{}

getWebPagePreview::getWebPagePreview(object_ptr<formattedText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t getWebPagePreview::ID;

void getWebPagePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWebPagePreview");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

hideSuggestedAction::hideSuggestedAction()
  : action_()
{}

hideSuggestedAction::hideSuggestedAction(object_ptr<SuggestedAction> &&action_)
  : action_(std::move(action_))
{}

const std::int32_t hideSuggestedAction::ID;

void hideSuggestedAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "hideSuggestedAction");
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

importContacts::importContacts()
  : contacts_()
{}

importContacts::importContacts(array<object_ptr<contact>> &&contacts_)
  : contacts_(std::move(contacts_))
{}

const std::int32_t importContacts::ID;

void importContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importContacts");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

importMessages::importMessages()
  : chat_id_()
  , message_file_()
  , attached_files_()
{}

importMessages::importMessages(int53 chat_id_, object_ptr<InputFile> &&message_file_, array<object_ptr<InputFile>> &&attached_files_)
  : chat_id_(chat_id_)
  , message_file_(std::move(message_file_))
  , attached_files_(std::move(attached_files_))
{}

const std::int32_t importMessages::ID;

void importMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importMessages");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("message_file", static_cast<const BaseObject *>(message_file_.get()));
    { s.store_vector_begin("attached_files", attached_files_.size()); for (const auto &_value : attached_files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inviteGroupCallParticipants::inviteGroupCallParticipants()
  : group_call_id_()
  , user_ids_()
{}

inviteGroupCallParticipants::inviteGroupCallParticipants(int32 group_call_id_, array<int53> &&user_ids_)
  : group_call_id_(group_call_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t inviteGroupCallParticipants::ID;

void inviteGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inviteGroupCallParticipants");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

joinChat::joinChat()
  : chat_id_()
{}

joinChat::joinChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t joinChat::ID;

void joinChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

joinChatByInviteLink::joinChatByInviteLink()
  : invite_link_()
{}

joinChatByInviteLink::joinChatByInviteLink(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t joinChatByInviteLink::ID;

void joinChatByInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinChatByInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

joinGroupCall::joinGroupCall()
  : group_call_id_()
  , participant_id_()
  , audio_source_id_()
  , payload_()
  , is_muted_()
  , is_my_video_enabled_()
  , invite_hash_()
{}

joinGroupCall::joinGroupCall(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, int32 audio_source_id_, string const &payload_, bool is_muted_, bool is_my_video_enabled_, string const &invite_hash_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , audio_source_id_(audio_source_id_)
  , payload_(payload_)
  , is_muted_(is_muted_)
  , is_my_video_enabled_(is_my_video_enabled_)
  , invite_hash_(invite_hash_)
{}

const std::int32_t joinGroupCall::ID;

void joinGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinGroupCall");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("audio_source_id", audio_source_id_);
    s.store_field("payload", payload_);
    s.store_field("is_muted", is_muted_);
    s.store_field("is_my_video_enabled", is_my_video_enabled_);
    s.store_field("invite_hash", invite_hash_);
    s.store_class_end();
  }
}

leaveChat::leaveChat()
  : chat_id_()
{}

leaveChat::leaveChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t leaveChat::ID;

void leaveChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "leaveChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

leaveGroupCall::leaveGroupCall()
  : group_call_id_()
{}

leaveGroupCall::leaveGroupCall(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t leaveGroupCall::ID;

void leaveGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "leaveGroupCall");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

loadChats::loadChats()
  : chat_list_()
  , limit_()
{}

loadChats::loadChats(object_ptr<ChatList> &&chat_list_, int32 limit_)
  : chat_list_(std::move(chat_list_))
  , limit_(limit_)
{}

const std::int32_t loadChats::ID;

void loadChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadChats");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

loadGroupCallParticipants::loadGroupCallParticipants()
  : group_call_id_()
  , limit_()
{}

loadGroupCallParticipants::loadGroupCallParticipants(int32 group_call_id_, int32 limit_)
  : group_call_id_(group_call_id_)
  , limit_(limit_)
{}

const std::int32_t loadGroupCallParticipants::ID;

void loadGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadGroupCallParticipants");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

logOut::logOut() {
}

const std::int32_t logOut::ID;

void logOut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logOut");
    s.store_class_end();
  }
}

openChat::openChat()
  : chat_id_()
{}

openChat::openChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t openChat::ID;

void openChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

openMessageContent::openMessageContent()
  : chat_id_()
  , message_id_()
{}

openMessageContent::openMessageContent(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t openMessageContent::ID;

void openMessageContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openMessageContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

openWebApp::openWebApp()
  : chat_id_()
  , bot_user_id_()
  , url_()
  , theme_()
  , reply_to_message_id_()
{}

openWebApp::openWebApp(int53 chat_id_, int53 bot_user_id_, string const &url_, object_ptr<themeParameters> &&theme_, int53 reply_to_message_id_)
  : chat_id_(chat_id_)
  , bot_user_id_(bot_user_id_)
  , url_(url_)
  , theme_(std::move(theme_))
  , reply_to_message_id_(reply_to_message_id_)
{}

const std::int32_t openWebApp::ID;

void openWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openWebApp");
    s.store_field("chat_id", chat_id_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("url", url_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_class_end();
  }
}

optimizeStorage::optimizeStorage()
  : size_()
  , ttl_()
  , count_()
  , immunity_delay_()
  , file_types_()
  , chat_ids_()
  , exclude_chat_ids_()
  , return_deleted_file_statistics_()
  , chat_limit_()
{}

optimizeStorage::optimizeStorage(int53 size_, int32 ttl_, int32 count_, int32 immunity_delay_, array<object_ptr<FileType>> &&file_types_, array<int53> &&chat_ids_, array<int53> &&exclude_chat_ids_, bool return_deleted_file_statistics_, int32 chat_limit_)
  : size_(size_)
  , ttl_(ttl_)
  , count_(count_)
  , immunity_delay_(immunity_delay_)
  , file_types_(std::move(file_types_))
  , chat_ids_(std::move(chat_ids_))
  , exclude_chat_ids_(std::move(exclude_chat_ids_))
  , return_deleted_file_statistics_(return_deleted_file_statistics_)
  , chat_limit_(chat_limit_)
{}

const std::int32_t optimizeStorage::ID;

void optimizeStorage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optimizeStorage");
    s.store_field("size", size_);
    s.store_field("ttl", ttl_);
    s.store_field("count", count_);
    s.store_field("immunity_delay", immunity_delay_);
    { s.store_vector_begin("file_types", file_types_.size()); for (const auto &_value : file_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("exclude_chat_ids", exclude_chat_ids_.size()); for (const auto &_value : exclude_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("return_deleted_file_statistics", return_deleted_file_statistics_);
    s.store_field("chat_limit", chat_limit_);
    s.store_class_end();
  }
}

parseMarkdown::parseMarkdown()
  : text_()
{}

parseMarkdown::parseMarkdown(object_ptr<formattedText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t parseMarkdown::ID;

void parseMarkdown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "parseMarkdown");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

parseTextEntities::parseTextEntities()
  : text_()
  , parse_mode_()
{}

parseTextEntities::parseTextEntities(string const &text_, object_ptr<TextParseMode> &&parse_mode_)
  : text_(text_)
  , parse_mode_(std::move(parse_mode_))
{}

const std::int32_t parseTextEntities::ID;

void parseTextEntities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "parseTextEntities");
    s.store_field("text", text_);
    s.store_object_field("parse_mode", static_cast<const BaseObject *>(parse_mode_.get()));
    s.store_class_end();
  }
}

pinChatMessage::pinChatMessage()
  : chat_id_()
  , message_id_()
  , disable_notification_()
  , only_for_self_()
{}

pinChatMessage::pinChatMessage(int53 chat_id_, int53 message_id_, bool disable_notification_, bool only_for_self_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , disable_notification_(disable_notification_)
  , only_for_self_(only_for_self_)
{}

const std::int32_t pinChatMessage::ID;

void pinChatMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pinChatMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("disable_notification", disable_notification_);
    s.store_field("only_for_self", only_for_self_);
    s.store_class_end();
  }
}

pingProxy::pingProxy()
  : proxy_id_()
{}

pingProxy::pingProxy(int32 proxy_id_)
  : proxy_id_(proxy_id_)
{}

const std::int32_t pingProxy::ID;

void pingProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pingProxy");
    s.store_field("proxy_id", proxy_id_);
    s.store_class_end();
  }
}

processChatJoinRequest::processChatJoinRequest()
  : chat_id_()
  , user_id_()
  , approve_()
{}

processChatJoinRequest::processChatJoinRequest(int53 chat_id_, int53 user_id_, bool approve_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
  , approve_(approve_)
{}

const std::int32_t processChatJoinRequest::ID;

void processChatJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processChatJoinRequest");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("approve", approve_);
    s.store_class_end();
  }
}

processChatJoinRequests::processChatJoinRequests()
  : chat_id_()
  , invite_link_()
  , approve_()
{}

processChatJoinRequests::processChatJoinRequests(int53 chat_id_, string const &invite_link_, bool approve_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , approve_(approve_)
{}

const std::int32_t processChatJoinRequests::ID;

void processChatJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processChatJoinRequests");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("approve", approve_);
    s.store_class_end();
  }
}

processPushNotification::processPushNotification()
  : payload_()
{}

processPushNotification::processPushNotification(string const &payload_)
  : payload_(payload_)
{}

const std::int32_t processPushNotification::ID;

void processPushNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processPushNotification");
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

readAllChatMentions::readAllChatMentions()
  : chat_id_()
{}

readAllChatMentions::readAllChatMentions(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t readAllChatMentions::ID;

void readAllChatMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllChatMentions");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

readAllChatReactions::readAllChatReactions()
  : chat_id_()
{}

readAllChatReactions::readAllChatReactions(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t readAllChatReactions::ID;

void readAllChatReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllChatReactions");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

readFilePart::readFilePart()
  : file_id_()
  , offset_()
  , count_()
{}

readFilePart::readFilePart(int32 file_id_, int32 offset_, int32 count_)
  : file_id_(file_id_)
  , offset_(offset_)
  , count_(count_)
{}

const std::int32_t readFilePart::ID;

void readFilePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readFilePart");
    s.store_field("file_id", file_id_);
    s.store_field("offset", offset_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

recoverAuthenticationPassword::recoverAuthenticationPassword()
  : recovery_code_()
  , new_password_()
  , new_hint_()
{}

recoverAuthenticationPassword::recoverAuthenticationPassword(string const &recovery_code_, string const &new_password_, string const &new_hint_)
  : recovery_code_(recovery_code_)
  , new_password_(new_password_)
  , new_hint_(new_hint_)
{}

const std::int32_t recoverAuthenticationPassword::ID;

void recoverAuthenticationPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recoverAuthenticationPassword");
    s.store_field("recovery_code", recovery_code_);
    s.store_field("new_password", new_password_);
    s.store_field("new_hint", new_hint_);
    s.store_class_end();
  }
}

recoverPassword::recoverPassword()
  : recovery_code_()
  , new_password_()
  , new_hint_()
{}

recoverPassword::recoverPassword(string const &recovery_code_, string const &new_password_, string const &new_hint_)
  : recovery_code_(recovery_code_)
  , new_password_(new_password_)
  , new_hint_(new_hint_)
{}

const std::int32_t recoverPassword::ID;

void recoverPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recoverPassword");
    s.store_field("recovery_code", recovery_code_);
    s.store_field("new_password", new_password_);
    s.store_field("new_hint", new_hint_);
    s.store_class_end();
  }
}

registerDevice::registerDevice()
  : device_token_()
  , other_user_ids_()
{}

registerDevice::registerDevice(object_ptr<DeviceToken> &&device_token_, array<int53> &&other_user_ids_)
  : device_token_(std::move(device_token_))
  , other_user_ids_(std::move(other_user_ids_))
{}

const std::int32_t registerDevice::ID;

void registerDevice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "registerDevice");
    s.store_object_field("device_token", static_cast<const BaseObject *>(device_token_.get()));
    { s.store_vector_begin("other_user_ids", other_user_ids_.size()); for (const auto &_value : other_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

registerUser::registerUser()
  : first_name_()
  , last_name_()
{}

registerUser::registerUser(string const &first_name_, string const &last_name_)
  : first_name_(first_name_)
  , last_name_(last_name_)
{}

const std::int32_t registerUser::ID;

void registerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "registerUser");
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_class_end();
  }
}

removeAllFilesFromDownloads::removeAllFilesFromDownloads()
  : only_active_()
  , only_completed_()
  , delete_from_cache_()
{}

removeAllFilesFromDownloads::removeAllFilesFromDownloads(bool only_active_, bool only_completed_, bool delete_from_cache_)
  : only_active_(only_active_)
  , only_completed_(only_completed_)
  , delete_from_cache_(delete_from_cache_)
{}

const std::int32_t removeAllFilesFromDownloads::ID;

void removeAllFilesFromDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeAllFilesFromDownloads");
    s.store_field("only_active", only_active_);
    s.store_field("only_completed", only_completed_);
    s.store_field("delete_from_cache", delete_from_cache_);
    s.store_class_end();
  }
}

removeBackground::removeBackground()
  : background_id_()
{}

removeBackground::removeBackground(int64 background_id_)
  : background_id_(background_id_)
{}

const std::int32_t removeBackground::ID;

void removeBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeBackground");
    s.store_field("background_id", background_id_);
    s.store_class_end();
  }
}

removeChatActionBar::removeChatActionBar()
  : chat_id_()
{}

removeChatActionBar::removeChatActionBar(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t removeChatActionBar::ID;

void removeChatActionBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeChatActionBar");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removeContacts::removeContacts()
  : user_ids_()
{}

removeContacts::removeContacts(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t removeContacts::ID;

void removeContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeContacts");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

removeFavoriteSticker::removeFavoriteSticker()
  : sticker_()
{}

removeFavoriteSticker::removeFavoriteSticker(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t removeFavoriteSticker::ID;

void removeFavoriteSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeFavoriteSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

removeFileFromDownloads::removeFileFromDownloads()
  : file_id_()
  , delete_from_cache_()
{}

removeFileFromDownloads::removeFileFromDownloads(int32 file_id_, bool delete_from_cache_)
  : file_id_(file_id_)
  , delete_from_cache_(delete_from_cache_)
{}

const std::int32_t removeFileFromDownloads::ID;

void removeFileFromDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeFileFromDownloads");
    s.store_field("file_id", file_id_);
    s.store_field("delete_from_cache", delete_from_cache_);
    s.store_class_end();
  }
}

removeNotification::removeNotification()
  : notification_group_id_()
  , notification_id_()
{}

removeNotification::removeNotification(int32 notification_group_id_, int32 notification_id_)
  : notification_group_id_(notification_group_id_)
  , notification_id_(notification_id_)
{}

const std::int32_t removeNotification::ID;

void removeNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeNotification");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_field("notification_id", notification_id_);
    s.store_class_end();
  }
}

removeNotificationGroup::removeNotificationGroup()
  : notification_group_id_()
  , max_notification_id_()
{}

removeNotificationGroup::removeNotificationGroup(int32 notification_group_id_, int32 max_notification_id_)
  : notification_group_id_(notification_group_id_)
  , max_notification_id_(max_notification_id_)
{}

const std::int32_t removeNotificationGroup::ID;

void removeNotificationGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeNotificationGroup");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_field("max_notification_id", max_notification_id_);
    s.store_class_end();
  }
}

removeProxy::removeProxy()
  : proxy_id_()
{}

removeProxy::removeProxy(int32 proxy_id_)
  : proxy_id_(proxy_id_)
{}

const std::int32_t removeProxy::ID;

void removeProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeProxy");
    s.store_field("proxy_id", proxy_id_);
    s.store_class_end();
  }
}

removeRecentHashtag::removeRecentHashtag()
  : hashtag_()
{}

removeRecentHashtag::removeRecentHashtag(string const &hashtag_)
  : hashtag_(hashtag_)
{}

const std::int32_t removeRecentHashtag::ID;

void removeRecentHashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeRecentHashtag");
    s.store_field("hashtag", hashtag_);
    s.store_class_end();
  }
}

removeRecentSticker::removeRecentSticker()
  : is_attached_()
  , sticker_()
{}

removeRecentSticker::removeRecentSticker(bool is_attached_, object_ptr<InputFile> &&sticker_)
  : is_attached_(is_attached_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t removeRecentSticker::ID;

void removeRecentSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeRecentSticker");
    s.store_field("is_attached", is_attached_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

removeRecentlyFoundChat::removeRecentlyFoundChat()
  : chat_id_()
{}

removeRecentlyFoundChat::removeRecentlyFoundChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t removeRecentlyFoundChat::ID;

void removeRecentlyFoundChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeRecentlyFoundChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removeSavedAnimation::removeSavedAnimation()
  : animation_()
{}

removeSavedAnimation::removeSavedAnimation(object_ptr<InputFile> &&animation_)
  : animation_(std::move(animation_))
{}

const std::int32_t removeSavedAnimation::ID;

void removeSavedAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeSavedAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

removeSavedNotificationSound::removeSavedNotificationSound()
  : notification_sound_id_()
{}

removeSavedNotificationSound::removeSavedNotificationSound(int64 notification_sound_id_)
  : notification_sound_id_(notification_sound_id_)
{}

const std::int32_t removeSavedNotificationSound::ID;

void removeSavedNotificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeSavedNotificationSound");
    s.store_field("notification_sound_id", notification_sound_id_);
    s.store_class_end();
  }
}

removeStickerFromSet::removeStickerFromSet()
  : sticker_()
{}

removeStickerFromSet::removeStickerFromSet(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t removeStickerFromSet::ID;

void removeStickerFromSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeStickerFromSet");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

removeTopChat::removeTopChat()
  : category_()
  , chat_id_()
{}

removeTopChat::removeTopChat(object_ptr<TopChatCategory> &&category_, int53 chat_id_)
  : category_(std::move(category_))
  , chat_id_(chat_id_)
{}

const std::int32_t removeTopChat::ID;

void removeTopChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeTopChat");
    s.store_object_field("category", static_cast<const BaseObject *>(category_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

reorderChatFilters::reorderChatFilters()
  : chat_filter_ids_()
{}

reorderChatFilters::reorderChatFilters(array<int32> &&chat_filter_ids_)
  : chat_filter_ids_(std::move(chat_filter_ids_))
{}

const std::int32_t reorderChatFilters::ID;

void reorderChatFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderChatFilters");
    { s.store_vector_begin("chat_filter_ids", chat_filter_ids_.size()); for (const auto &_value : chat_filter_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reorderInstalledStickerSets::reorderInstalledStickerSets()
  : is_masks_()
  , sticker_set_ids_()
{}

reorderInstalledStickerSets::reorderInstalledStickerSets(bool is_masks_, array<int64> &&sticker_set_ids_)
  : is_masks_(is_masks_)
  , sticker_set_ids_(std::move(sticker_set_ids_))
{}

const std::int32_t reorderInstalledStickerSets::ID;

void reorderInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderInstalledStickerSets");
    s.store_field("is_masks", is_masks_);
    { s.store_vector_begin("sticker_set_ids", sticker_set_ids_.size()); for (const auto &_value : sticker_set_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

replacePrimaryChatInviteLink::replacePrimaryChatInviteLink()
  : chat_id_()
{}

replacePrimaryChatInviteLink::replacePrimaryChatInviteLink(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t replacePrimaryChatInviteLink::ID;

void replacePrimaryChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replacePrimaryChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

replaceVideoChatRtmpUrl::replaceVideoChatRtmpUrl()
  : chat_id_()
{}

replaceVideoChatRtmpUrl::replaceVideoChatRtmpUrl(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t replaceVideoChatRtmpUrl::ID;

void replaceVideoChatRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replaceVideoChatRtmpUrl");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

reportChat::reportChat()
  : chat_id_()
  , message_ids_()
  , reason_()
  , text_()
{}

reportChat::reportChat(int53 chat_id_, array<int53> &&message_ids_, object_ptr<ChatReportReason> &&reason_, string const &text_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
  , reason_(std::move(reason_))
  , text_(text_)
{}

const std::int32_t reportChat::ID;

void reportChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChat");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("text", text_);
    s.store_class_end();
  }
}

reportChatPhoto::reportChatPhoto()
  : chat_id_()
  , file_id_()
  , reason_()
  , text_()
{}

reportChatPhoto::reportChatPhoto(int53 chat_id_, int32 file_id_, object_ptr<ChatReportReason> &&reason_, string const &text_)
  : chat_id_(chat_id_)
  , file_id_(file_id_)
  , reason_(std::move(reason_))
  , text_(text_)
{}

const std::int32_t reportChatPhoto::ID;

void reportChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatPhoto");
    s.store_field("chat_id", chat_id_);
    s.store_field("file_id", file_id_);
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("text", text_);
    s.store_class_end();
  }
}

reportSupergroupSpam::reportSupergroupSpam()
  : supergroup_id_()
  , message_ids_()
{}

reportSupergroupSpam::reportSupergroupSpam(int53 supergroup_id_, array<int53> &&message_ids_)
  : supergroup_id_(supergroup_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t reportSupergroupSpam::ID;

void reportSupergroupSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSupergroupSpam");
    s.store_field("supergroup_id", supergroup_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

requestAuthenticationPasswordRecovery::requestAuthenticationPasswordRecovery() {
}

const std::int32_t requestAuthenticationPasswordRecovery::ID;

void requestAuthenticationPasswordRecovery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestAuthenticationPasswordRecovery");
    s.store_class_end();
  }
}

requestPasswordRecovery::requestPasswordRecovery() {
}

const std::int32_t requestPasswordRecovery::ID;

void requestPasswordRecovery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestPasswordRecovery");
    s.store_class_end();
  }
}

requestQrCodeAuthentication::requestQrCodeAuthentication()
  : other_user_ids_()
{}

requestQrCodeAuthentication::requestQrCodeAuthentication(array<int53> &&other_user_ids_)
  : other_user_ids_(std::move(other_user_ids_))
{}

const std::int32_t requestQrCodeAuthentication::ID;

void requestQrCodeAuthentication::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestQrCodeAuthentication");
    { s.store_vector_begin("other_user_ids", other_user_ids_.size()); for (const auto &_value : other_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

resendAuthenticationCode::resendAuthenticationCode() {
}

const std::int32_t resendAuthenticationCode::ID;

void resendAuthenticationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendAuthenticationCode");
    s.store_class_end();
  }
}

resendChangePhoneNumberCode::resendChangePhoneNumberCode() {
}

const std::int32_t resendChangePhoneNumberCode::ID;

void resendChangePhoneNumberCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendChangePhoneNumberCode");
    s.store_class_end();
  }
}

resendEmailAddressVerificationCode::resendEmailAddressVerificationCode() {
}

const std::int32_t resendEmailAddressVerificationCode::ID;

void resendEmailAddressVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendEmailAddressVerificationCode");
    s.store_class_end();
  }
}

resendMessages::resendMessages()
  : chat_id_()
  , message_ids_()
{}

resendMessages::resendMessages(int53 chat_id_, array<int53> &&message_ids_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t resendMessages::ID;

void resendMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

resendPhoneNumberConfirmationCode::resendPhoneNumberConfirmationCode() {
}

const std::int32_t resendPhoneNumberConfirmationCode::ID;

void resendPhoneNumberConfirmationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendPhoneNumberConfirmationCode");
    s.store_class_end();
  }
}

resendPhoneNumberVerificationCode::resendPhoneNumberVerificationCode() {
}

const std::int32_t resendPhoneNumberVerificationCode::ID;

void resendPhoneNumberVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendPhoneNumberVerificationCode");
    s.store_class_end();
  }
}

resendRecoveryEmailAddressCode::resendRecoveryEmailAddressCode() {
}

const std::int32_t resendRecoveryEmailAddressCode::ID;

void resendRecoveryEmailAddressCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendRecoveryEmailAddressCode");
    s.store_class_end();
  }
}

resetAllNotificationSettings::resetAllNotificationSettings() {
}

const std::int32_t resetAllNotificationSettings::ID;

void resetAllNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetAllNotificationSettings");
    s.store_class_end();
  }
}

resetBackgrounds::resetBackgrounds() {
}

const std::int32_t resetBackgrounds::ID;

void resetBackgrounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetBackgrounds");
    s.store_class_end();
  }
}

resetNetworkStatistics::resetNetworkStatistics() {
}

const std::int32_t resetNetworkStatistics::ID;

void resetNetworkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetNetworkStatistics");
    s.store_class_end();
  }
}

resetPassword::resetPassword() {
}

const std::int32_t resetPassword::ID;

void resetPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPassword");
    s.store_class_end();
  }
}

revokeChatInviteLink::revokeChatInviteLink()
  : chat_id_()
  , invite_link_()
{}

revokeChatInviteLink::revokeChatInviteLink(int53 chat_id_, string const &invite_link_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
{}

const std::int32_t revokeChatInviteLink::ID;

void revokeChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revokeChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

revokeGroupCallInviteLink::revokeGroupCallInviteLink()
  : group_call_id_()
{}

revokeGroupCallInviteLink::revokeGroupCallInviteLink(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t revokeGroupCallInviteLink::ID;

void revokeGroupCallInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revokeGroupCallInviteLink");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

saveApplicationLogEvent::saveApplicationLogEvent()
  : type_()
  , chat_id_()
  , data_()
{}

saveApplicationLogEvent::saveApplicationLogEvent(string const &type_, int53 chat_id_, object_ptr<JsonValue> &&data_)
  : type_(type_)
  , chat_id_(chat_id_)
  , data_(std::move(data_))
{}

const std::int32_t saveApplicationLogEvent::ID;

void saveApplicationLogEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "saveApplicationLogEvent");
    s.store_field("type", type_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_class_end();
  }
}

searchBackground::searchBackground()
  : name_()
{}

searchBackground::searchBackground(string const &name_)
  : name_(name_)
{}

const std::int32_t searchBackground::ID;

void searchBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchBackground");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

searchCallMessages::searchCallMessages()
  : from_message_id_()
  , limit_()
  , only_missed_()
{}

searchCallMessages::searchCallMessages(int53 from_message_id_, int32 limit_, bool only_missed_)
  : from_message_id_(from_message_id_)
  , limit_(limit_)
  , only_missed_(only_missed_)
{}

const std::int32_t searchCallMessages::ID;

void searchCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchCallMessages");
    s.store_field("from_message_id", from_message_id_);
    s.store_field("limit", limit_);
    s.store_field("only_missed", only_missed_);
    s.store_class_end();
  }
}

searchChatMembers::searchChatMembers()
  : chat_id_()
  , query_()
  , limit_()
  , filter_()
{}

searchChatMembers::searchChatMembers(int53 chat_id_, string const &query_, int32 limit_, object_ptr<ChatMembersFilter> &&filter_)
  : chat_id_(chat_id_)
  , query_(query_)
  , limit_(limit_)
  , filter_(std::move(filter_))
{}

const std::int32_t searchChatMembers::ID;

void searchChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatMembers");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_class_end();
  }
}

searchChatMessages::searchChatMessages()
  : chat_id_()
  , query_()
  , sender_id_()
  , from_message_id_()
  , offset_()
  , limit_()
  , filter_()
  , message_thread_id_()
{}

searchChatMessages::searchChatMessages(int53 chat_id_, string const &query_, object_ptr<MessageSender> &&sender_id_, int53 from_message_id_, int32 offset_, int32 limit_, object_ptr<SearchMessagesFilter> &&filter_, int53 message_thread_id_)
  : chat_id_(chat_id_)
  , query_(query_)
  , sender_id_(std::move(sender_id_))
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
  , filter_(std::move(filter_))
  , message_thread_id_(message_thread_id_)
{}

const std::int32_t searchChatMessages::ID;

void searchChatMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("message_thread_id", message_thread_id_);
    s.store_class_end();
  }
}

searchChatRecentLocationMessages::searchChatRecentLocationMessages()
  : chat_id_()
  , limit_()
{}

searchChatRecentLocationMessages::searchChatRecentLocationMessages(int53 chat_id_, int32 limit_)
  : chat_id_(chat_id_)
  , limit_(limit_)
{}

const std::int32_t searchChatRecentLocationMessages::ID;

void searchChatRecentLocationMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatRecentLocationMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchChats::searchChats()
  : query_()
  , limit_()
{}

searchChats::searchChats(string const &query_, int32 limit_)
  : query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchChats::ID;

void searchChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChats");
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchChatsNearby::searchChatsNearby()
  : location_()
{}

searchChatsNearby::searchChatsNearby(object_ptr<location> &&location_)
  : location_(std::move(location_))
{}

const std::int32_t searchChatsNearby::ID;

void searchChatsNearby::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatsNearby");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

searchChatsOnServer::searchChatsOnServer()
  : query_()
  , limit_()
{}

searchChatsOnServer::searchChatsOnServer(string const &query_, int32 limit_)
  : query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchChatsOnServer::ID;

void searchChatsOnServer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatsOnServer");
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchContacts::searchContacts()
  : query_()
  , limit_()
{}

searchContacts::searchContacts(string const &query_, int32 limit_)
  : query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchContacts::ID;

void searchContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchContacts");
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchEmojis::searchEmojis()
  : text_()
  , exact_match_()
  , input_language_codes_()
{}

searchEmojis::searchEmojis(string const &text_, bool exact_match_, array<string> &&input_language_codes_)
  : text_(text_)
  , exact_match_(exact_match_)
  , input_language_codes_(std::move(input_language_codes_))
{}

const std::int32_t searchEmojis::ID;

void searchEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchEmojis");
    s.store_field("text", text_);
    s.store_field("exact_match", exact_match_);
    { s.store_vector_begin("input_language_codes", input_language_codes_.size()); for (const auto &_value : input_language_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

searchFileDownloads::searchFileDownloads()
  : query_()
  , only_active_()
  , only_completed_()
  , offset_()
  , limit_()
{}

searchFileDownloads::searchFileDownloads(string const &query_, bool only_active_, bool only_completed_, string const &offset_, int32 limit_)
  : query_(query_)
  , only_active_(only_active_)
  , only_completed_(only_completed_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchFileDownloads::ID;

void searchFileDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchFileDownloads");
    s.store_field("query", query_);
    s.store_field("only_active", only_active_);
    s.store_field("only_completed", only_completed_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchHashtags::searchHashtags()
  : prefix_()
  , limit_()
{}

searchHashtags::searchHashtags(string const &prefix_, int32 limit_)
  : prefix_(prefix_)
  , limit_(limit_)
{}

const std::int32_t searchHashtags::ID;

void searchHashtags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchHashtags");
    s.store_field("prefix", prefix_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchInstalledStickerSets::searchInstalledStickerSets()
  : is_masks_()
  , query_()
  , limit_()
{}

searchInstalledStickerSets::searchInstalledStickerSets(bool is_masks_, string const &query_, int32 limit_)
  : is_masks_(is_masks_)
  , query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchInstalledStickerSets::ID;

void searchInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchInstalledStickerSets");
    s.store_field("is_masks", is_masks_);
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchMessages::searchMessages()
  : chat_list_()
  , query_()
  , offset_date_()
  , offset_chat_id_()
  , offset_message_id_()
  , limit_()
  , filter_()
  , min_date_()
  , max_date_()
{}

searchMessages::searchMessages(object_ptr<ChatList> &&chat_list_, string const &query_, int32 offset_date_, int53 offset_chat_id_, int53 offset_message_id_, int32 limit_, object_ptr<SearchMessagesFilter> &&filter_, int32 min_date_, int32 max_date_)
  : chat_list_(std::move(chat_list_))
  , query_(query_)
  , offset_date_(offset_date_)
  , offset_chat_id_(offset_chat_id_)
  , offset_message_id_(offset_message_id_)
  , limit_(limit_)
  , filter_(std::move(filter_))
  , min_date_(min_date_)
  , max_date_(max_date_)
{}

const std::int32_t searchMessages::ID;

void searchMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchMessages");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("query", query_);
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_chat_id", offset_chat_id_);
    s.store_field("offset_message_id", offset_message_id_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_class_end();
  }
}

searchOutgoingDocumentMessages::searchOutgoingDocumentMessages()
  : query_()
  , limit_()
{}

searchOutgoingDocumentMessages::searchOutgoingDocumentMessages(string const &query_, int32 limit_)
  : query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchOutgoingDocumentMessages::ID;

void searchOutgoingDocumentMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchOutgoingDocumentMessages");
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchPublicChat::searchPublicChat()
  : username_()
{}

searchPublicChat::searchPublicChat(string const &username_)
  : username_(username_)
{}

const std::int32_t searchPublicChat::ID;

void searchPublicChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicChat");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

searchPublicChats::searchPublicChats()
  : query_()
{}

searchPublicChats::searchPublicChats(string const &query_)
  : query_(query_)
{}

const std::int32_t searchPublicChats::ID;

void searchPublicChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicChats");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

searchSecretMessages::searchSecretMessages()
  : chat_id_()
  , query_()
  , offset_()
  , limit_()
  , filter_()
{}

searchSecretMessages::searchSecretMessages(int53 chat_id_, string const &query_, string const &offset_, int32 limit_, object_ptr<SearchMessagesFilter> &&filter_)
  : chat_id_(chat_id_)
  , query_(query_)
  , offset_(offset_)
  , limit_(limit_)
  , filter_(std::move(filter_))
{}

const std::int32_t searchSecretMessages::ID;

void searchSecretMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchSecretMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_class_end();
  }
}

searchStickerSet::searchStickerSet()
  : name_()
{}

searchStickerSet::searchStickerSet(string const &name_)
  : name_(name_)
{}

const std::int32_t searchStickerSet::ID;

void searchStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchStickerSet");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

searchStickerSets::searchStickerSets()
  : query_()
{}

searchStickerSets::searchStickerSets(string const &query_)
  : query_(query_)
{}

const std::int32_t searchStickerSets::ID;

void searchStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchStickerSets");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

searchStickers::searchStickers()
  : emoji_()
  , limit_()
{}

searchStickers::searchStickers(string const &emoji_, int32 limit_)
  : emoji_(emoji_)
  , limit_(limit_)
{}

const std::int32_t searchStickers::ID;

void searchStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchStickers");
    s.store_field("emoji", emoji_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchUserByPhoneNumber::searchUserByPhoneNumber()
  : phone_number_()
{}

searchUserByPhoneNumber::searchUserByPhoneNumber(string const &phone_number_)
  : phone_number_(phone_number_)
{}

const std::int32_t searchUserByPhoneNumber::ID;

void searchUserByPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchUserByPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

sendBotStartMessage::sendBotStartMessage()
  : bot_user_id_()
  , chat_id_()
  , parameter_()
{}

sendBotStartMessage::sendBotStartMessage(int53 bot_user_id_, int53 chat_id_, string const &parameter_)
  : bot_user_id_(bot_user_id_)
  , chat_id_(chat_id_)
  , parameter_(parameter_)
{}

const std::int32_t sendBotStartMessage::ID;

void sendBotStartMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendBotStartMessage");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("parameter", parameter_);
    s.store_class_end();
  }
}

sendCallDebugInformation::sendCallDebugInformation()
  : call_id_()
  , debug_information_()
{}

sendCallDebugInformation::sendCallDebugInformation(int32 call_id_, string const &debug_information_)
  : call_id_(call_id_)
  , debug_information_(debug_information_)
{}

const std::int32_t sendCallDebugInformation::ID;

void sendCallDebugInformation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallDebugInformation");
    s.store_field("call_id", call_id_);
    s.store_field("debug_information", debug_information_);
    s.store_class_end();
  }
}

sendCallLog::sendCallLog()
  : call_id_()
  , log_file_()
{}

sendCallLog::sendCallLog(int32 call_id_, object_ptr<InputFile> &&log_file_)
  : call_id_(call_id_)
  , log_file_(std::move(log_file_))
{}

const std::int32_t sendCallLog::ID;

void sendCallLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallLog");
    s.store_field("call_id", call_id_);
    s.store_object_field("log_file", static_cast<const BaseObject *>(log_file_.get()));
    s.store_class_end();
  }
}

sendCallRating::sendCallRating()
  : call_id_()
  , rating_()
  , comment_()
  , problems_()
{}

sendCallRating::sendCallRating(int32 call_id_, int32 rating_, string const &comment_, array<object_ptr<CallProblem>> &&problems_)
  : call_id_(call_id_)
  , rating_(rating_)
  , comment_(comment_)
  , problems_(std::move(problems_))
{}

const std::int32_t sendCallRating::ID;

void sendCallRating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallRating");
    s.store_field("call_id", call_id_);
    s.store_field("rating", rating_);
    s.store_field("comment", comment_);
    { s.store_vector_begin("problems", problems_.size()); for (const auto &_value : problems_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sendCallSignalingData::sendCallSignalingData()
  : call_id_()
  , data_()
{}

sendCallSignalingData::sendCallSignalingData(int32 call_id_, bytes const &data_)
  : call_id_(call_id_)
  , data_(std::move(data_))
{}

const std::int32_t sendCallSignalingData::ID;

void sendCallSignalingData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallSignalingData");
    s.store_field("call_id", call_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

sendChatAction::sendChatAction()
  : chat_id_()
  , message_thread_id_()
  , action_()
{}

sendChatAction::sendChatAction(int53 chat_id_, int53 message_thread_id_, object_ptr<ChatAction> &&action_)
  : chat_id_(chat_id_)
  , message_thread_id_(message_thread_id_)
  , action_(std::move(action_))
{}

const std::int32_t sendChatAction::ID;

void sendChatAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendChatAction");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_thread_id", message_thread_id_);
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

sendChatScreenshotTakenNotification::sendChatScreenshotTakenNotification()
  : chat_id_()
{}

sendChatScreenshotTakenNotification::sendChatScreenshotTakenNotification(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t sendChatScreenshotTakenNotification::ID;

void sendChatScreenshotTakenNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendChatScreenshotTakenNotification");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

sendCustomRequest::sendCustomRequest()
  : method_()
  , parameters_()
{}

sendCustomRequest::sendCustomRequest(string const &method_, string const &parameters_)
  : method_(method_)
  , parameters_(parameters_)
{}

const std::int32_t sendCustomRequest::ID;

void sendCustomRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCustomRequest");
    s.store_field("method", method_);
    s.store_field("parameters", parameters_);
    s.store_class_end();
  }
}

sendEmailAddressVerificationCode::sendEmailAddressVerificationCode()
  : email_address_()
{}

sendEmailAddressVerificationCode::sendEmailAddressVerificationCode(string const &email_address_)
  : email_address_(email_address_)
{}

const std::int32_t sendEmailAddressVerificationCode::ID;

void sendEmailAddressVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendEmailAddressVerificationCode");
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

sendInlineQueryResultMessage::sendInlineQueryResultMessage()
  : chat_id_()
  , message_thread_id_()
  , reply_to_message_id_()
  , options_()
  , query_id_()
  , result_id_()
  , hide_via_bot_()
{}

sendInlineQueryResultMessage::sendInlineQueryResultMessage(int53 chat_id_, int53 message_thread_id_, int53 reply_to_message_id_, object_ptr<messageSendOptions> &&options_, int64 query_id_, string const &result_id_, bool hide_via_bot_)
  : chat_id_(chat_id_)
  , message_thread_id_(message_thread_id_)
  , reply_to_message_id_(reply_to_message_id_)
  , options_(std::move(options_))
  , query_id_(query_id_)
  , result_id_(result_id_)
  , hide_via_bot_(hide_via_bot_)
{}

const std::int32_t sendInlineQueryResultMessage::ID;

void sendInlineQueryResultMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendInlineQueryResultMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_thread_id", message_thread_id_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_field("query_id", query_id_);
    s.store_field("result_id", result_id_);
    s.store_field("hide_via_bot", hide_via_bot_);
    s.store_class_end();
  }
}

sendMessage::sendMessage()
  : chat_id_()
  , message_thread_id_()
  , reply_to_message_id_()
  , options_()
  , reply_markup_()
  , input_message_content_()
{}

sendMessage::sendMessage(int53 chat_id_, int53 message_thread_id_, int53 reply_to_message_id_, object_ptr<messageSendOptions> &&options_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , message_thread_id_(message_thread_id_)
  , reply_to_message_id_(reply_to_message_id_)
  , options_(std::move(options_))
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t sendMessage::ID;

void sendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_thread_id", message_thread_id_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

sendMessageAlbum::sendMessageAlbum()
  : chat_id_()
  , message_thread_id_()
  , reply_to_message_id_()
  , options_()
  , input_message_contents_()
  , only_preview_()
{}

sendMessageAlbum::sendMessageAlbum(int53 chat_id_, int53 message_thread_id_, int53 reply_to_message_id_, object_ptr<messageSendOptions> &&options_, array<object_ptr<InputMessageContent>> &&input_message_contents_, bool only_preview_)
  : chat_id_(chat_id_)
  , message_thread_id_(message_thread_id_)
  , reply_to_message_id_(reply_to_message_id_)
  , options_(std::move(options_))
  , input_message_contents_(std::move(input_message_contents_))
  , only_preview_(only_preview_)
{}

const std::int32_t sendMessageAlbum::ID;

void sendMessageAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageAlbum");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_thread_id", message_thread_id_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    { s.store_vector_begin("input_message_contents", input_message_contents_.size()); for (const auto &_value : input_message_contents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("only_preview", only_preview_);
    s.store_class_end();
  }
}

sendPassportAuthorizationForm::sendPassportAuthorizationForm()
  : autorization_form_id_()
  , types_()
{}

sendPassportAuthorizationForm::sendPassportAuthorizationForm(int32 autorization_form_id_, array<object_ptr<PassportElementType>> &&types_)
  : autorization_form_id_(autorization_form_id_)
  , types_(std::move(types_))
{}

const std::int32_t sendPassportAuthorizationForm::ID;

void sendPassportAuthorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPassportAuthorizationForm");
    s.store_field("autorization_form_id", autorization_form_id_);
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sendPaymentForm::sendPaymentForm()
  : chat_id_()
  , message_id_()
  , payment_form_id_()
  , order_info_id_()
  , shipping_option_id_()
  , credentials_()
  , tip_amount_()
{}

sendPaymentForm::sendPaymentForm(int53 chat_id_, int53 message_id_, int64 payment_form_id_, string const &order_info_id_, string const &shipping_option_id_, object_ptr<InputCredentials> &&credentials_, int53 tip_amount_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , payment_form_id_(payment_form_id_)
  , order_info_id_(order_info_id_)
  , shipping_option_id_(shipping_option_id_)
  , credentials_(std::move(credentials_))
  , tip_amount_(tip_amount_)
{}

const std::int32_t sendPaymentForm::ID;

void sendPaymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPaymentForm");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("payment_form_id", payment_form_id_);
    s.store_field("order_info_id", order_info_id_);
    s.store_field("shipping_option_id", shipping_option_id_);
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    s.store_field("tip_amount", tip_amount_);
    s.store_class_end();
  }
}

sendPhoneNumberConfirmationCode::sendPhoneNumberConfirmationCode()
  : hash_()
  , phone_number_()
  , settings_()
{}

sendPhoneNumberConfirmationCode::sendPhoneNumberConfirmationCode(string const &hash_, string const &phone_number_, object_ptr<phoneNumberAuthenticationSettings> &&settings_)
  : hash_(hash_)
  , phone_number_(phone_number_)
  , settings_(std::move(settings_))
{}

const std::int32_t sendPhoneNumberConfirmationCode::ID;

void sendPhoneNumberConfirmationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPhoneNumberConfirmationCode");
    s.store_field("hash", hash_);
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

sendPhoneNumberVerificationCode::sendPhoneNumberVerificationCode()
  : phone_number_()
  , settings_()
{}

sendPhoneNumberVerificationCode::sendPhoneNumberVerificationCode(string const &phone_number_, object_ptr<phoneNumberAuthenticationSettings> &&settings_)
  : phone_number_(phone_number_)
  , settings_(std::move(settings_))
{}

const std::int32_t sendPhoneNumberVerificationCode::ID;

void sendPhoneNumberVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPhoneNumberVerificationCode");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

sendWebAppData::sendWebAppData()
  : bot_user_id_()
  , button_text_()
  , data_()
{}

sendWebAppData::sendWebAppData(int53 bot_user_id_, string const &button_text_, string const &data_)
  : bot_user_id_(bot_user_id_)
  , button_text_(button_text_)
  , data_(data_)
{}

const std::int32_t sendWebAppData::ID;

void sendWebAppData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendWebAppData");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("button_text", button_text_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

setAccountTtl::setAccountTtl()
  : ttl_()
{}

setAccountTtl::setAccountTtl(object_ptr<accountTtl> &&ttl_)
  : ttl_(std::move(ttl_))
{}

const std::int32_t setAccountTtl::ID;

void setAccountTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAccountTtl");
    s.store_object_field("ttl", static_cast<const BaseObject *>(ttl_.get()));
    s.store_class_end();
  }
}

setAlarm::setAlarm()
  : seconds_()
{}

setAlarm::setAlarm(double seconds_)
  : seconds_(seconds_)
{}

const std::int32_t setAlarm::ID;

void setAlarm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAlarm");
    s.store_field("seconds", seconds_);
    s.store_class_end();
  }
}

setAuthenticationPhoneNumber::setAuthenticationPhoneNumber()
  : phone_number_()
  , settings_()
{}

setAuthenticationPhoneNumber::setAuthenticationPhoneNumber(string const &phone_number_, object_ptr<phoneNumberAuthenticationSettings> &&settings_)
  : phone_number_(phone_number_)
  , settings_(std::move(settings_))
{}

const std::int32_t setAuthenticationPhoneNumber::ID;

void setAuthenticationPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAuthenticationPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setAutoDownloadSettings::setAutoDownloadSettings()
  : settings_()
  , type_()
{}

setAutoDownloadSettings::setAutoDownloadSettings(object_ptr<autoDownloadSettings> &&settings_, object_ptr<NetworkType> &&type_)
  : settings_(std::move(settings_))
  , type_(std::move(type_))
{}

const std::int32_t setAutoDownloadSettings::ID;

void setAutoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAutoDownloadSettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

setBackground::setBackground()
  : background_()
  , type_()
  , for_dark_theme_()
{}

setBackground::setBackground(object_ptr<InputBackground> &&background_, object_ptr<BackgroundType> &&type_, bool for_dark_theme_)
  : background_(std::move(background_))
  , type_(std::move(type_))
  , for_dark_theme_(for_dark_theme_)
{}

const std::int32_t setBackground::ID;

void setBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBackground");
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("for_dark_theme", for_dark_theme_);
    s.store_class_end();
  }
}

setBio::setBio()
  : bio_()
{}

setBio::setBio(string const &bio_)
  : bio_(bio_)
{}

const std::int32_t setBio::ID;

void setBio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBio");
    s.store_field("bio", bio_);
    s.store_class_end();
  }
}

setBotUpdatesStatus::setBotUpdatesStatus()
  : pending_update_count_()
  , error_message_()
{}

setBotUpdatesStatus::setBotUpdatesStatus(int32 pending_update_count_, string const &error_message_)
  : pending_update_count_(pending_update_count_)
  , error_message_(error_message_)
{}

const std::int32_t setBotUpdatesStatus::ID;

void setBotUpdatesStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotUpdatesStatus");
    s.store_field("pending_update_count", pending_update_count_);
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

setChatAvailableReactions::setChatAvailableReactions()
  : chat_id_()
  , available_reactions_()
{}

setChatAvailableReactions::setChatAvailableReactions(int53 chat_id_, array<string> &&available_reactions_)
  : chat_id_(chat_id_)
  , available_reactions_(std::move(available_reactions_))
{}

const std::int32_t setChatAvailableReactions::ID;

void setChatAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatAvailableReactions");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("available_reactions", available_reactions_.size()); for (const auto &_value : available_reactions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setChatClientData::setChatClientData()
  : chat_id_()
  , client_data_()
{}

setChatClientData::setChatClientData(int53 chat_id_, string const &client_data_)
  : chat_id_(chat_id_)
  , client_data_(client_data_)
{}

const std::int32_t setChatClientData::ID;

void setChatClientData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatClientData");
    s.store_field("chat_id", chat_id_);
    s.store_field("client_data", client_data_);
    s.store_class_end();
  }
}

setChatDescription::setChatDescription()
  : chat_id_()
  , description_()
{}

setChatDescription::setChatDescription(int53 chat_id_, string const &description_)
  : chat_id_(chat_id_)
  , description_(description_)
{}

const std::int32_t setChatDescription::ID;

void setChatDescription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatDescription");
    s.store_field("chat_id", chat_id_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

setChatDiscussionGroup::setChatDiscussionGroup()
  : chat_id_()
  , discussion_chat_id_()
{}

setChatDiscussionGroup::setChatDiscussionGroup(int53 chat_id_, int53 discussion_chat_id_)
  : chat_id_(chat_id_)
  , discussion_chat_id_(discussion_chat_id_)
{}

const std::int32_t setChatDiscussionGroup::ID;

void setChatDiscussionGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatDiscussionGroup");
    s.store_field("chat_id", chat_id_);
    s.store_field("discussion_chat_id", discussion_chat_id_);
    s.store_class_end();
  }
}

setChatDraftMessage::setChatDraftMessage()
  : chat_id_()
  , message_thread_id_()
  , draft_message_()
{}

setChatDraftMessage::setChatDraftMessage(int53 chat_id_, int53 message_thread_id_, object_ptr<draftMessage> &&draft_message_)
  : chat_id_(chat_id_)
  , message_thread_id_(message_thread_id_)
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t setChatDraftMessage::ID;

void setChatDraftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatDraftMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_thread_id", message_thread_id_);
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

setChatLocation::setChatLocation()
  : chat_id_()
  , location_()
{}

setChatLocation::setChatLocation(int53 chat_id_, object_ptr<chatLocation> &&location_)
  : chat_id_(chat_id_)
  , location_(std::move(location_))
{}

const std::int32_t setChatLocation::ID;

void setChatLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatLocation");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

setChatMemberStatus::setChatMemberStatus()
  : chat_id_()
  , member_id_()
  , status_()
{}

setChatMemberStatus::setChatMemberStatus(int53 chat_id_, object_ptr<MessageSender> &&member_id_, object_ptr<ChatMemberStatus> &&status_)
  : chat_id_(chat_id_)
  , member_id_(std::move(member_id_))
  , status_(std::move(status_))
{}

const std::int32_t setChatMemberStatus::ID;

void setChatMemberStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatMemberStatus");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

setChatMessageSender::setChatMessageSender()
  : chat_id_()
  , message_sender_id_()
{}

setChatMessageSender::setChatMessageSender(int53 chat_id_, object_ptr<MessageSender> &&message_sender_id_)
  : chat_id_(chat_id_)
  , message_sender_id_(std::move(message_sender_id_))
{}

const std::int32_t setChatMessageSender::ID;

void setChatMessageSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatMessageSender");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    s.store_class_end();
  }
}

setChatMessageTtl::setChatMessageTtl()
  : chat_id_()
  , ttl_()
{}

setChatMessageTtl::setChatMessageTtl(int53 chat_id_, int32 ttl_)
  : chat_id_(chat_id_)
  , ttl_(ttl_)
{}

const std::int32_t setChatMessageTtl::ID;

void setChatMessageTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatMessageTtl");
    s.store_field("chat_id", chat_id_);
    s.store_field("ttl", ttl_);
    s.store_class_end();
  }
}

setChatNotificationSettings::setChatNotificationSettings()
  : chat_id_()
  , notification_settings_()
{}

setChatNotificationSettings::setChatNotificationSettings(int53 chat_id_, object_ptr<chatNotificationSettings> &&notification_settings_)
  : chat_id_(chat_id_)
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t setChatNotificationSettings::ID;

void setChatNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatNotificationSettings");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

setChatPermissions::setChatPermissions()
  : chat_id_()
  , permissions_()
{}

setChatPermissions::setChatPermissions(int53 chat_id_, object_ptr<chatPermissions> &&permissions_)
  : chat_id_(chat_id_)
  , permissions_(std::move(permissions_))
{}

const std::int32_t setChatPermissions::ID;

void setChatPermissions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatPermissions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_class_end();
  }
}

setChatPhoto::setChatPhoto()
  : chat_id_()
  , photo_()
{}

setChatPhoto::setChatPhoto(int53 chat_id_, object_ptr<InputChatPhoto> &&photo_)
  : chat_id_(chat_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t setChatPhoto::ID;

void setChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatPhoto");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

setChatSlowModeDelay::setChatSlowModeDelay()
  : chat_id_()
  , slow_mode_delay_()
{}

setChatSlowModeDelay::setChatSlowModeDelay(int53 chat_id_, int32 slow_mode_delay_)
  : chat_id_(chat_id_)
  , slow_mode_delay_(slow_mode_delay_)
{}

const std::int32_t setChatSlowModeDelay::ID;

void setChatSlowModeDelay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatSlowModeDelay");
    s.store_field("chat_id", chat_id_);
    s.store_field("slow_mode_delay", slow_mode_delay_);
    s.store_class_end();
  }
}

setChatTheme::setChatTheme()
  : chat_id_()
  , theme_name_()
{}

setChatTheme::setChatTheme(int53 chat_id_, string const &theme_name_)
  : chat_id_(chat_id_)
  , theme_name_(theme_name_)
{}

const std::int32_t setChatTheme::ID;

void setChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatTheme");
    s.store_field("chat_id", chat_id_);
    s.store_field("theme_name", theme_name_);
    s.store_class_end();
  }
}

setChatTitle::setChatTitle()
  : chat_id_()
  , title_()
{}

setChatTitle::setChatTitle(int53 chat_id_, string const &title_)
  : chat_id_(chat_id_)
  , title_(title_)
{}

const std::int32_t setChatTitle::ID;

void setChatTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatTitle");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

setCommands::setCommands()
  : scope_()
  , language_code_()
  , commands_()
{}

setCommands::setCommands(object_ptr<BotCommandScope> &&scope_, string const &language_code_, array<object_ptr<botCommand>> &&commands_)
  : scope_(std::move(scope_))
  , language_code_(language_code_)
  , commands_(std::move(commands_))
{}

const std::int32_t setCommands::ID;

void setCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("language_code", language_code_);
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

setCustomLanguagePack::setCustomLanguagePack()
  : info_()
  , strings_()
{}

setCustomLanguagePack::setCustomLanguagePack(object_ptr<languagePackInfo> &&info_, array<object_ptr<languagePackString>> &&strings_)
  : info_(std::move(info_))
  , strings_(std::move(strings_))
{}

const std::int32_t setCustomLanguagePack::ID;

void setCustomLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCustomLanguagePack");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

setCustomLanguagePackString::setCustomLanguagePackString()
  : language_pack_id_()
  , new_string_()
{}

setCustomLanguagePackString::setCustomLanguagePackString(string const &language_pack_id_, object_ptr<languagePackString> &&new_string_)
  : language_pack_id_(language_pack_id_)
  , new_string_(std::move(new_string_))
{}

const std::int32_t setCustomLanguagePackString::ID;

void setCustomLanguagePackString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCustomLanguagePackString");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_object_field("new_string", static_cast<const BaseObject *>(new_string_.get()));
    s.store_class_end();
  }
}

setDatabaseEncryptionKey::setDatabaseEncryptionKey()
  : new_encryption_key_()
{}

setDatabaseEncryptionKey::setDatabaseEncryptionKey(bytes const &new_encryption_key_)
  : new_encryption_key_(std::move(new_encryption_key_))
{}

const std::int32_t setDatabaseEncryptionKey::ID;

void setDatabaseEncryptionKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDatabaseEncryptionKey");
    s.store_bytes_field("new_encryption_key", new_encryption_key_);
    s.store_class_end();
  }
}

setDefaultChannelAdministratorRights::setDefaultChannelAdministratorRights()
  : default_channel_administrator_rights_()
{}

setDefaultChannelAdministratorRights::setDefaultChannelAdministratorRights(object_ptr<chatAdministratorRights> &&default_channel_administrator_rights_)
  : default_channel_administrator_rights_(std::move(default_channel_administrator_rights_))
{}

const std::int32_t setDefaultChannelAdministratorRights::ID;

void setDefaultChannelAdministratorRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultChannelAdministratorRights");
    s.store_object_field("default_channel_administrator_rights", static_cast<const BaseObject *>(default_channel_administrator_rights_.get()));
    s.store_class_end();
  }
}

setDefaultGroupAdministratorRights::setDefaultGroupAdministratorRights()
  : default_group_administrator_rights_()
{}

setDefaultGroupAdministratorRights::setDefaultGroupAdministratorRights(object_ptr<chatAdministratorRights> &&default_group_administrator_rights_)
  : default_group_administrator_rights_(std::move(default_group_administrator_rights_))
{}

const std::int32_t setDefaultGroupAdministratorRights::ID;

void setDefaultGroupAdministratorRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultGroupAdministratorRights");
    s.store_object_field("default_group_administrator_rights", static_cast<const BaseObject *>(default_group_administrator_rights_.get()));
    s.store_class_end();
  }
}

setFileGenerationProgress::setFileGenerationProgress()
  : generation_id_()
  , expected_size_()
  , local_prefix_size_()
{}

setFileGenerationProgress::setFileGenerationProgress(int64 generation_id_, int32 expected_size_, int32 local_prefix_size_)
  : generation_id_(generation_id_)
  , expected_size_(expected_size_)
  , local_prefix_size_(local_prefix_size_)
{}

const std::int32_t setFileGenerationProgress::ID;

void setFileGenerationProgress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setFileGenerationProgress");
    s.store_field("generation_id", generation_id_);
    s.store_field("expected_size", expected_size_);
    s.store_field("local_prefix_size", local_prefix_size_);
    s.store_class_end();
  }
}

setGameScore::setGameScore()
  : chat_id_()
  , message_id_()
  , edit_message_()
  , user_id_()
  , score_()
  , force_()
{}

setGameScore::setGameScore(int53 chat_id_, int53 message_id_, bool edit_message_, int53 user_id_, int32 score_, bool force_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , edit_message_(edit_message_)
  , user_id_(user_id_)
  , score_(score_)
  , force_(force_)
{}

const std::int32_t setGameScore::ID;

void setGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGameScore");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("edit_message", edit_message_);
    s.store_field("user_id", user_id_);
    s.store_field("score", score_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

setGroupCallParticipantIsSpeaking::setGroupCallParticipantIsSpeaking()
  : group_call_id_()
  , audio_source_()
  , is_speaking_()
{}

setGroupCallParticipantIsSpeaking::setGroupCallParticipantIsSpeaking(int32 group_call_id_, int32 audio_source_, bool is_speaking_)
  : group_call_id_(group_call_id_)
  , audio_source_(audio_source_)
  , is_speaking_(is_speaking_)
{}

const std::int32_t setGroupCallParticipantIsSpeaking::ID;

void setGroupCallParticipantIsSpeaking::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGroupCallParticipantIsSpeaking");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("audio_source", audio_source_);
    s.store_field("is_speaking", is_speaking_);
    s.store_class_end();
  }
}

setGroupCallParticipantVolumeLevel::setGroupCallParticipantVolumeLevel()
  : group_call_id_()
  , participant_id_()
  , volume_level_()
{}

setGroupCallParticipantVolumeLevel::setGroupCallParticipantVolumeLevel(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, int32 volume_level_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , volume_level_(volume_level_)
{}

const std::int32_t setGroupCallParticipantVolumeLevel::ID;

void setGroupCallParticipantVolumeLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGroupCallParticipantVolumeLevel");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("volume_level", volume_level_);
    s.store_class_end();
  }
}

setGroupCallTitle::setGroupCallTitle()
  : group_call_id_()
  , title_()
{}

setGroupCallTitle::setGroupCallTitle(int32 group_call_id_, string const &title_)
  : group_call_id_(group_call_id_)
  , title_(title_)
{}

const std::int32_t setGroupCallTitle::ID;

void setGroupCallTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGroupCallTitle");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

setInactiveSessionTtl::setInactiveSessionTtl()
  : inactive_session_ttl_days_()
{}

setInactiveSessionTtl::setInactiveSessionTtl(int32 inactive_session_ttl_days_)
  : inactive_session_ttl_days_(inactive_session_ttl_days_)
{}

const std::int32_t setInactiveSessionTtl::ID;

void setInactiveSessionTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setInactiveSessionTtl");
    s.store_field("inactive_session_ttl_days", inactive_session_ttl_days_);
    s.store_class_end();
  }
}

setInlineGameScore::setInlineGameScore()
  : inline_message_id_()
  , edit_message_()
  , user_id_()
  , score_()
  , force_()
{}

setInlineGameScore::setInlineGameScore(string const &inline_message_id_, bool edit_message_, int53 user_id_, int32 score_, bool force_)
  : inline_message_id_(inline_message_id_)
  , edit_message_(edit_message_)
  , user_id_(user_id_)
  , score_(score_)
  , force_(force_)
{}

const std::int32_t setInlineGameScore::ID;

void setInlineGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setInlineGameScore");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_field("edit_message", edit_message_);
    s.store_field("user_id", user_id_);
    s.store_field("score", score_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

setLocation::setLocation()
  : location_()
{}

setLocation::setLocation(object_ptr<location> &&location_)
  : location_(std::move(location_))
{}

const std::int32_t setLocation::ID;

void setLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

setLogStream::setLogStream()
  : log_stream_()
{}

setLogStream::setLogStream(object_ptr<LogStream> &&log_stream_)
  : log_stream_(std::move(log_stream_))
{}

const std::int32_t setLogStream::ID;

void setLogStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLogStream");
    s.store_object_field("log_stream", static_cast<const BaseObject *>(log_stream_.get()));
    s.store_class_end();
  }
}

setLogTagVerbosityLevel::setLogTagVerbosityLevel()
  : tag_()
  , new_verbosity_level_()
{}

setLogTagVerbosityLevel::setLogTagVerbosityLevel(string const &tag_, int32 new_verbosity_level_)
  : tag_(tag_)
  , new_verbosity_level_(new_verbosity_level_)
{}

const std::int32_t setLogTagVerbosityLevel::ID;

void setLogTagVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLogTagVerbosityLevel");
    s.store_field("tag", tag_);
    s.store_field("new_verbosity_level", new_verbosity_level_);
    s.store_class_end();
  }
}

setLogVerbosityLevel::setLogVerbosityLevel()
  : new_verbosity_level_()
{}

setLogVerbosityLevel::setLogVerbosityLevel(int32 new_verbosity_level_)
  : new_verbosity_level_(new_verbosity_level_)
{}

const std::int32_t setLogVerbosityLevel::ID;

void setLogVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLogVerbosityLevel");
    s.store_field("new_verbosity_level", new_verbosity_level_);
    s.store_class_end();
  }
}

setMenuButton::setMenuButton()
  : user_id_()
  , menu_button_()
{}

setMenuButton::setMenuButton(int53 user_id_, object_ptr<botMenuButton> &&menu_button_)
  : user_id_(user_id_)
  , menu_button_(std::move(menu_button_))
{}

const std::int32_t setMenuButton::ID;

void setMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMenuButton");
    s.store_field("user_id", user_id_);
    s.store_object_field("menu_button", static_cast<const BaseObject *>(menu_button_.get()));
    s.store_class_end();
  }
}

setMessageReaction::setMessageReaction()
  : chat_id_()
  , message_id_()
  , reaction_()
  , is_big_()
{}

setMessageReaction::setMessageReaction(int53 chat_id_, int53 message_id_, string const &reaction_, bool is_big_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reaction_(reaction_)
  , is_big_(is_big_)
{}

const std::int32_t setMessageReaction::ID;

void setMessageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMessageReaction");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("reaction", reaction_);
    s.store_field("is_big", is_big_);
    s.store_class_end();
  }
}

setName::setName()
  : first_name_()
  , last_name_()
{}

setName::setName(string const &first_name_, string const &last_name_)
  : first_name_(first_name_)
  , last_name_(last_name_)
{}

const std::int32_t setName::ID;

void setName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setName");
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_class_end();
  }
}

setNetworkType::setNetworkType()
  : type_()
{}

setNetworkType::setNetworkType(object_ptr<NetworkType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t setNetworkType::ID;

void setNetworkType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setNetworkType");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

setOption::setOption()
  : name_()
  , value_()
{}

setOption::setOption(string const &name_, object_ptr<OptionValue> &&value_)
  : name_(name_)
  , value_(std::move(value_))
{}

const std::int32_t setOption::ID;

void setOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setOption");
    s.store_field("name", name_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

setPassportElement::setPassportElement()
  : element_()
  , password_()
{}

setPassportElement::setPassportElement(object_ptr<InputPassportElement> &&element_, string const &password_)
  : element_(std::move(element_))
  , password_(password_)
{}

const std::int32_t setPassportElement::ID;

void setPassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPassportElement");
    s.store_object_field("element", static_cast<const BaseObject *>(element_.get()));
    s.store_field("password", password_);
    s.store_class_end();
  }
}

setPassportElementErrors::setPassportElementErrors()
  : user_id_()
  , errors_()
{}

setPassportElementErrors::setPassportElementErrors(int53 user_id_, array<object_ptr<inputPassportElementError>> &&errors_)
  : user_id_(user_id_)
  , errors_(std::move(errors_))
{}

const std::int32_t setPassportElementErrors::ID;

void setPassportElementErrors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPassportElementErrors");
    s.store_field("user_id", user_id_);
    { s.store_vector_begin("errors", errors_.size()); for (const auto &_value : errors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

setPassword::setPassword()
  : old_password_()
  , new_password_()
  , new_hint_()
  , set_recovery_email_address_()
  , new_recovery_email_address_()
{}

setPassword::setPassword(string const &old_password_, string const &new_password_, string const &new_hint_, bool set_recovery_email_address_, string const &new_recovery_email_address_)
  : old_password_(old_password_)
  , new_password_(new_password_)
  , new_hint_(new_hint_)
  , set_recovery_email_address_(set_recovery_email_address_)
  , new_recovery_email_address_(new_recovery_email_address_)
{}

const std::int32_t setPassword::ID;

void setPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPassword");
    s.store_field("old_password", old_password_);
    s.store_field("new_password", new_password_);
    s.store_field("new_hint", new_hint_);
    s.store_field("set_recovery_email_address", set_recovery_email_address_);
    s.store_field("new_recovery_email_address", new_recovery_email_address_);
    s.store_class_end();
  }
}

setPinnedChats::setPinnedChats()
  : chat_list_()
  , chat_ids_()
{}

setPinnedChats::setPinnedChats(object_ptr<ChatList> &&chat_list_, array<int53> &&chat_ids_)
  : chat_list_(std::move(chat_list_))
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t setPinnedChats::ID;

void setPinnedChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPinnedChats");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setPollAnswer::setPollAnswer()
  : chat_id_()
  , message_id_()
  , option_ids_()
{}

setPollAnswer::setPollAnswer(int53 chat_id_, int53 message_id_, array<int32> &&option_ids_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_ids_(std::move(option_ids_))
{}

const std::int32_t setPollAnswer::ID;

void setPollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPollAnswer");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("option_ids", option_ids_.size()); for (const auto &_value : option_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setProfilePhoto::setProfilePhoto()
  : photo_()
{}

setProfilePhoto::setProfilePhoto(object_ptr<InputChatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t setProfilePhoto::ID;

void setProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setProfilePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

setRecoveryEmailAddress::setRecoveryEmailAddress()
  : password_()
  , new_recovery_email_address_()
{}

setRecoveryEmailAddress::setRecoveryEmailAddress(string const &password_, string const &new_recovery_email_address_)
  : password_(password_)
  , new_recovery_email_address_(new_recovery_email_address_)
{}

const std::int32_t setRecoveryEmailAddress::ID;

void setRecoveryEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setRecoveryEmailAddress");
    s.store_field("password", password_);
    s.store_field("new_recovery_email_address", new_recovery_email_address_);
    s.store_class_end();
  }
}

setScopeNotificationSettings::setScopeNotificationSettings()
  : scope_()
  , notification_settings_()
{}

setScopeNotificationSettings::setScopeNotificationSettings(object_ptr<NotificationSettingsScope> &&scope_, object_ptr<scopeNotificationSettings> &&notification_settings_)
  : scope_(std::move(scope_))
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t setScopeNotificationSettings::ID;

void setScopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setScopeNotificationSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

setStickerPositionInSet::setStickerPositionInSet()
  : sticker_()
  , position_()
{}

setStickerPositionInSet::setStickerPositionInSet(object_ptr<InputFile> &&sticker_, int32 position_)
  : sticker_(std::move(sticker_))
  , position_(position_)
{}

const std::int32_t setStickerPositionInSet::ID;

void setStickerPositionInSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerPositionInSet");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("position", position_);
    s.store_class_end();
  }
}

setStickerSetThumbnail::setStickerSetThumbnail()
  : user_id_()
  , name_()
  , thumbnail_()
{}

setStickerSetThumbnail::setStickerSetThumbnail(int53 user_id_, string const &name_, object_ptr<InputFile> &&thumbnail_)
  : user_id_(user_id_)
  , name_(name_)
  , thumbnail_(std::move(thumbnail_))
{}

const std::int32_t setStickerSetThumbnail::ID;

void setStickerSetThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerSetThumbnail");
    s.store_field("user_id", user_id_);
    s.store_field("name", name_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_class_end();
  }
}

setSupergroupStickerSet::setSupergroupStickerSet()
  : supergroup_id_()
  , sticker_set_id_()
{}

setSupergroupStickerSet::setSupergroupStickerSet(int53 supergroup_id_, int64 sticker_set_id_)
  : supergroup_id_(supergroup_id_)
  , sticker_set_id_(sticker_set_id_)
{}

const std::int32_t setSupergroupStickerSet::ID;

void setSupergroupStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupStickerSet");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("sticker_set_id", sticker_set_id_);
    s.store_class_end();
  }
}

setSupergroupUsername::setSupergroupUsername()
  : supergroup_id_()
  , username_()
{}

setSupergroupUsername::setSupergroupUsername(int53 supergroup_id_, string const &username_)
  : supergroup_id_(supergroup_id_)
  , username_(username_)
{}

const std::int32_t setSupergroupUsername::ID;

void setSupergroupUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupUsername");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("username", username_);
    s.store_class_end();
  }
}

setTdlibParameters::setTdlibParameters()
  : parameters_()
{}

setTdlibParameters::setTdlibParameters(object_ptr<tdlibParameters> &&parameters_)
  : parameters_(std::move(parameters_))
{}

const std::int32_t setTdlibParameters::ID;

void setTdlibParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setTdlibParameters");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

setUserPrivacySettingRules::setUserPrivacySettingRules()
  : setting_()
  , rules_()
{}

setUserPrivacySettingRules::setUserPrivacySettingRules(object_ptr<UserPrivacySetting> &&setting_, object_ptr<userPrivacySettingRules> &&rules_)
  : setting_(std::move(setting_))
  , rules_(std::move(rules_))
{}

const std::int32_t setUserPrivacySettingRules::ID;

void setUserPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUserPrivacySettingRules");
    s.store_object_field("setting", static_cast<const BaseObject *>(setting_.get()));
    s.store_object_field("rules", static_cast<const BaseObject *>(rules_.get()));
    s.store_class_end();
  }
}

setUsername::setUsername()
  : username_()
{}

setUsername::setUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t setUsername::ID;

void setUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

setVideoChatDefaultParticipant::setVideoChatDefaultParticipant()
  : chat_id_()
  , default_participant_id_()
{}

setVideoChatDefaultParticipant::setVideoChatDefaultParticipant(int53 chat_id_, object_ptr<MessageSender> &&default_participant_id_)
  : chat_id_(chat_id_)
  , default_participant_id_(std::move(default_participant_id_))
{}

const std::int32_t setVideoChatDefaultParticipant::ID;

void setVideoChatDefaultParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setVideoChatDefaultParticipant");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("default_participant_id", static_cast<const BaseObject *>(default_participant_id_.get()));
    s.store_class_end();
  }
}

sharePhoneNumber::sharePhoneNumber()
  : user_id_()
{}

sharePhoneNumber::sharePhoneNumber(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t sharePhoneNumber::ID;

void sharePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sharePhoneNumber");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

startGroupCallRecording::startGroupCallRecording()
  : group_call_id_()
  , title_()
  , record_video_()
  , use_portrait_orientation_()
{}

startGroupCallRecording::startGroupCallRecording(int32 group_call_id_, string const &title_, bool record_video_, bool use_portrait_orientation_)
  : group_call_id_(group_call_id_)
  , title_(title_)
  , record_video_(record_video_)
  , use_portrait_orientation_(use_portrait_orientation_)
{}

const std::int32_t startGroupCallRecording::ID;

void startGroupCallRecording::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startGroupCallRecording");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("title", title_);
    s.store_field("record_video", record_video_);
    s.store_field("use_portrait_orientation", use_portrait_orientation_);
    s.store_class_end();
  }
}

startGroupCallScreenSharing::startGroupCallScreenSharing()
  : group_call_id_()
  , audio_source_id_()
  , payload_()
{}

startGroupCallScreenSharing::startGroupCallScreenSharing(int32 group_call_id_, int32 audio_source_id_, string const &payload_)
  : group_call_id_(group_call_id_)
  , audio_source_id_(audio_source_id_)
  , payload_(payload_)
{}

const std::int32_t startGroupCallScreenSharing::ID;

void startGroupCallScreenSharing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startGroupCallScreenSharing");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("audio_source_id", audio_source_id_);
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

startScheduledGroupCall::startScheduledGroupCall()
  : group_call_id_()
{}

startScheduledGroupCall::startScheduledGroupCall(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t startScheduledGroupCall::ID;

void startScheduledGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startScheduledGroupCall");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

stopPoll::stopPoll()
  : chat_id_()
  , message_id_()
  , reply_markup_()
{}

stopPoll::stopPoll(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t stopPoll::ID;

void stopPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stopPoll");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

synchronizeLanguagePack::synchronizeLanguagePack()
  : language_pack_id_()
{}

synchronizeLanguagePack::synchronizeLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t synchronizeLanguagePack::ID;

void synchronizeLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "synchronizeLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

terminateAllOtherSessions::terminateAllOtherSessions() {
}

const std::int32_t terminateAllOtherSessions::ID;

void terminateAllOtherSessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "terminateAllOtherSessions");
    s.store_class_end();
  }
}

terminateSession::terminateSession()
  : session_id_()
{}

terminateSession::terminateSession(int64 session_id_)
  : session_id_(session_id_)
{}

const std::int32_t terminateSession::ID;

void terminateSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "terminateSession");
    s.store_field("session_id", session_id_);
    s.store_class_end();
  }
}

testCallBytes::testCallBytes()
  : x_()
{}

testCallBytes::testCallBytes(bytes const &x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallBytes::ID;

void testCallBytes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallBytes");
    s.store_bytes_field("x", x_);
    s.store_class_end();
  }
}

testCallEmpty::testCallEmpty() {
}

const std::int32_t testCallEmpty::ID;

void testCallEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallEmpty");
    s.store_class_end();
  }
}

testCallString::testCallString()
  : x_()
{}

testCallString::testCallString(string const &x_)
  : x_(x_)
{}

const std::int32_t testCallString::ID;

void testCallString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallString");
    s.store_field("x", x_);
    s.store_class_end();
  }
}

testCallVectorInt::testCallVectorInt()
  : x_()
{}

testCallVectorInt::testCallVectorInt(array<int32> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorInt::ID;

void testCallVectorInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorInt");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

testCallVectorIntObject::testCallVectorIntObject()
  : x_()
{}

testCallVectorIntObject::testCallVectorIntObject(array<object_ptr<testInt>> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorIntObject::ID;

void testCallVectorIntObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorIntObject");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

testCallVectorString::testCallVectorString()
  : x_()
{}

testCallVectorString::testCallVectorString(array<string> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorString::ID;

void testCallVectorString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorString");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

testCallVectorStringObject::testCallVectorStringObject()
  : x_()
{}

testCallVectorStringObject::testCallVectorStringObject(array<object_ptr<testString>> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorStringObject::ID;

void testCallVectorStringObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorStringObject");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

testGetDifference::testGetDifference() {
}

const std::int32_t testGetDifference::ID;

void testGetDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testGetDifference");
    s.store_class_end();
  }
}

testNetwork::testNetwork() {
}

const std::int32_t testNetwork::ID;

void testNetwork::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testNetwork");
    s.store_class_end();
  }
}

testProxy::testProxy()
  : server_()
  , port_()
  , type_()
  , dc_id_()
  , timeout_()
{}

testProxy::testProxy(string const &server_, int32 port_, object_ptr<ProxyType> &&type_, int32 dc_id_, double timeout_)
  : server_(server_)
  , port_(port_)
  , type_(std::move(type_))
  , dc_id_(dc_id_)
  , timeout_(timeout_)
{}

const std::int32_t testProxy::ID;

void testProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testProxy");
    s.store_field("server", server_);
    s.store_field("port", port_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("dc_id", dc_id_);
    s.store_field("timeout", timeout_);
    s.store_class_end();
  }
}

testReturnError::testReturnError()
  : error_()
{}

testReturnError::testReturnError(object_ptr<error> &&error_)
  : error_(std::move(error_))
{}

const std::int32_t testReturnError::ID;

void testReturnError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testReturnError");
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

testSquareInt::testSquareInt()
  : x_()
{}

testSquareInt::testSquareInt(int32 x_)
  : x_(x_)
{}

const std::int32_t testSquareInt::ID;

void testSquareInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testSquareInt");
    s.store_field("x", x_);
    s.store_class_end();
  }
}

testUseUpdate::testUseUpdate() {
}

const std::int32_t testUseUpdate::ID;

void testUseUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testUseUpdate");
    s.store_class_end();
  }
}

toggleAllDownloadsArePaused::toggleAllDownloadsArePaused()
  : are_paused_()
{}

toggleAllDownloadsArePaused::toggleAllDownloadsArePaused(bool are_paused_)
  : are_paused_(are_paused_)
{}

const std::int32_t toggleAllDownloadsArePaused::ID;

void toggleAllDownloadsArePaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleAllDownloadsArePaused");
    s.store_field("are_paused", are_paused_);
    s.store_class_end();
  }
}

toggleBotIsAddedToAttachmentMenu::toggleBotIsAddedToAttachmentMenu()
  : bot_user_id_()
  , is_added_()
{}

toggleBotIsAddedToAttachmentMenu::toggleBotIsAddedToAttachmentMenu(int53 bot_user_id_, bool is_added_)
  : bot_user_id_(bot_user_id_)
  , is_added_(is_added_)
{}

const std::int32_t toggleBotIsAddedToAttachmentMenu::ID;

void toggleBotIsAddedToAttachmentMenu::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleBotIsAddedToAttachmentMenu");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("is_added", is_added_);
    s.store_class_end();
  }
}

toggleChatDefaultDisableNotification::toggleChatDefaultDisableNotification()
  : chat_id_()
  , default_disable_notification_()
{}

toggleChatDefaultDisableNotification::toggleChatDefaultDisableNotification(int53 chat_id_, bool default_disable_notification_)
  : chat_id_(chat_id_)
  , default_disable_notification_(default_disable_notification_)
{}

const std::int32_t toggleChatDefaultDisableNotification::ID;

void toggleChatDefaultDisableNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatDefaultDisableNotification");
    s.store_field("chat_id", chat_id_);
    s.store_field("default_disable_notification", default_disable_notification_);
    s.store_class_end();
  }
}

toggleChatHasProtectedContent::toggleChatHasProtectedContent()
  : chat_id_()
  , has_protected_content_()
{}

toggleChatHasProtectedContent::toggleChatHasProtectedContent(int53 chat_id_, bool has_protected_content_)
  : chat_id_(chat_id_)
  , has_protected_content_(has_protected_content_)
{}

const std::int32_t toggleChatHasProtectedContent::ID;

void toggleChatHasProtectedContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatHasProtectedContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("has_protected_content", has_protected_content_);
    s.store_class_end();
  }
}

toggleChatIsMarkedAsUnread::toggleChatIsMarkedAsUnread()
  : chat_id_()
  , is_marked_as_unread_()
{}

toggleChatIsMarkedAsUnread::toggleChatIsMarkedAsUnread(int53 chat_id_, bool is_marked_as_unread_)
  : chat_id_(chat_id_)
  , is_marked_as_unread_(is_marked_as_unread_)
{}

const std::int32_t toggleChatIsMarkedAsUnread::ID;

void toggleChatIsMarkedAsUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatIsMarkedAsUnread");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_class_end();
  }
}

toggleChatIsPinned::toggleChatIsPinned()
  : chat_list_()
  , chat_id_()
  , is_pinned_()
{}

toggleChatIsPinned::toggleChatIsPinned(object_ptr<ChatList> &&chat_list_, int53 chat_id_, bool is_pinned_)
  : chat_list_(std::move(chat_list_))
  , chat_id_(chat_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t toggleChatIsPinned::ID;

void toggleChatIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatIsPinned");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

toggleDownloadIsPaused::toggleDownloadIsPaused()
  : file_id_()
  , is_paused_()
{}

toggleDownloadIsPaused::toggleDownloadIsPaused(int32 file_id_, bool is_paused_)
  : file_id_(file_id_)
  , is_paused_(is_paused_)
{}

const std::int32_t toggleDownloadIsPaused::ID;

void toggleDownloadIsPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleDownloadIsPaused");
    s.store_field("file_id", file_id_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

toggleGroupCallEnabledStartNotification::toggleGroupCallEnabledStartNotification()
  : group_call_id_()
  , enabled_start_notification_()
{}

toggleGroupCallEnabledStartNotification::toggleGroupCallEnabledStartNotification(int32 group_call_id_, bool enabled_start_notification_)
  : group_call_id_(group_call_id_)
  , enabled_start_notification_(enabled_start_notification_)
{}

const std::int32_t toggleGroupCallEnabledStartNotification::ID;

void toggleGroupCallEnabledStartNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallEnabledStartNotification");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("enabled_start_notification", enabled_start_notification_);
    s.store_class_end();
  }
}

toggleGroupCallIsMyVideoEnabled::toggleGroupCallIsMyVideoEnabled()
  : group_call_id_()
  , is_my_video_enabled_()
{}

toggleGroupCallIsMyVideoEnabled::toggleGroupCallIsMyVideoEnabled(int32 group_call_id_, bool is_my_video_enabled_)
  : group_call_id_(group_call_id_)
  , is_my_video_enabled_(is_my_video_enabled_)
{}

const std::int32_t toggleGroupCallIsMyVideoEnabled::ID;

void toggleGroupCallIsMyVideoEnabled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallIsMyVideoEnabled");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("is_my_video_enabled", is_my_video_enabled_);
    s.store_class_end();
  }
}

toggleGroupCallIsMyVideoPaused::toggleGroupCallIsMyVideoPaused()
  : group_call_id_()
  , is_my_video_paused_()
{}

toggleGroupCallIsMyVideoPaused::toggleGroupCallIsMyVideoPaused(int32 group_call_id_, bool is_my_video_paused_)
  : group_call_id_(group_call_id_)
  , is_my_video_paused_(is_my_video_paused_)
{}

const std::int32_t toggleGroupCallIsMyVideoPaused::ID;

void toggleGroupCallIsMyVideoPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallIsMyVideoPaused");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("is_my_video_paused", is_my_video_paused_);
    s.store_class_end();
  }
}

toggleGroupCallMuteNewParticipants::toggleGroupCallMuteNewParticipants()
  : group_call_id_()
  , mute_new_participants_()
{}

toggleGroupCallMuteNewParticipants::toggleGroupCallMuteNewParticipants(int32 group_call_id_, bool mute_new_participants_)
  : group_call_id_(group_call_id_)
  , mute_new_participants_(mute_new_participants_)
{}

const std::int32_t toggleGroupCallMuteNewParticipants::ID;

void toggleGroupCallMuteNewParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallMuteNewParticipants");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("mute_new_participants", mute_new_participants_);
    s.store_class_end();
  }
}

toggleGroupCallParticipantIsHandRaised::toggleGroupCallParticipantIsHandRaised()
  : group_call_id_()
  , participant_id_()
  , is_hand_raised_()
{}

toggleGroupCallParticipantIsHandRaised::toggleGroupCallParticipantIsHandRaised(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, bool is_hand_raised_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , is_hand_raised_(is_hand_raised_)
{}

const std::int32_t toggleGroupCallParticipantIsHandRaised::ID;

void toggleGroupCallParticipantIsHandRaised::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallParticipantIsHandRaised");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_hand_raised", is_hand_raised_);
    s.store_class_end();
  }
}

toggleGroupCallParticipantIsMuted::toggleGroupCallParticipantIsMuted()
  : group_call_id_()
  , participant_id_()
  , is_muted_()
{}

toggleGroupCallParticipantIsMuted::toggleGroupCallParticipantIsMuted(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, bool is_muted_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , is_muted_(is_muted_)
{}

const std::int32_t toggleGroupCallParticipantIsMuted::ID;

void toggleGroupCallParticipantIsMuted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallParticipantIsMuted");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_muted", is_muted_);
    s.store_class_end();
  }
}

toggleGroupCallScreenSharingIsPaused::toggleGroupCallScreenSharingIsPaused()
  : group_call_id_()
  , is_paused_()
{}

toggleGroupCallScreenSharingIsPaused::toggleGroupCallScreenSharingIsPaused(int32 group_call_id_, bool is_paused_)
  : group_call_id_(group_call_id_)
  , is_paused_(is_paused_)
{}

const std::int32_t toggleGroupCallScreenSharingIsPaused::ID;

void toggleGroupCallScreenSharingIsPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallScreenSharingIsPaused");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

toggleMessageSenderIsBlocked::toggleMessageSenderIsBlocked()
  : sender_id_()
  , is_blocked_()
{}

toggleMessageSenderIsBlocked::toggleMessageSenderIsBlocked(object_ptr<MessageSender> &&sender_id_, bool is_blocked_)
  : sender_id_(std::move(sender_id_))
  , is_blocked_(is_blocked_)
{}

const std::int32_t toggleMessageSenderIsBlocked::ID;

void toggleMessageSenderIsBlocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleMessageSenderIsBlocked");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("is_blocked", is_blocked_);
    s.store_class_end();
  }
}

toggleSessionCanAcceptCalls::toggleSessionCanAcceptCalls()
  : session_id_()
  , can_accept_calls_()
{}

toggleSessionCanAcceptCalls::toggleSessionCanAcceptCalls(int64 session_id_, bool can_accept_calls_)
  : session_id_(session_id_)
  , can_accept_calls_(can_accept_calls_)
{}

const std::int32_t toggleSessionCanAcceptCalls::ID;

void toggleSessionCanAcceptCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSessionCanAcceptCalls");
    s.store_field("session_id", session_id_);
    s.store_field("can_accept_calls", can_accept_calls_);
    s.store_class_end();
  }
}

toggleSessionCanAcceptSecretChats::toggleSessionCanAcceptSecretChats()
  : session_id_()
  , can_accept_secret_chats_()
{}

toggleSessionCanAcceptSecretChats::toggleSessionCanAcceptSecretChats(int64 session_id_, bool can_accept_secret_chats_)
  : session_id_(session_id_)
  , can_accept_secret_chats_(can_accept_secret_chats_)
{}

const std::int32_t toggleSessionCanAcceptSecretChats::ID;

void toggleSessionCanAcceptSecretChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSessionCanAcceptSecretChats");
    s.store_field("session_id", session_id_);
    s.store_field("can_accept_secret_chats", can_accept_secret_chats_);
    s.store_class_end();
  }
}

toggleSupergroupIsAllHistoryAvailable::toggleSupergroupIsAllHistoryAvailable()
  : supergroup_id_()
  , is_all_history_available_()
{}

toggleSupergroupIsAllHistoryAvailable::toggleSupergroupIsAllHistoryAvailable(int53 supergroup_id_, bool is_all_history_available_)
  : supergroup_id_(supergroup_id_)
  , is_all_history_available_(is_all_history_available_)
{}

const std::int32_t toggleSupergroupIsAllHistoryAvailable::ID;

void toggleSupergroupIsAllHistoryAvailable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupIsAllHistoryAvailable");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("is_all_history_available", is_all_history_available_);
    s.store_class_end();
  }
}

toggleSupergroupIsBroadcastGroup::toggleSupergroupIsBroadcastGroup()
  : supergroup_id_()
{}

toggleSupergroupIsBroadcastGroup::toggleSupergroupIsBroadcastGroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t toggleSupergroupIsBroadcastGroup::ID;

void toggleSupergroupIsBroadcastGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupIsBroadcastGroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

toggleSupergroupSignMessages::toggleSupergroupSignMessages()
  : supergroup_id_()
  , sign_messages_()
{}

toggleSupergroupSignMessages::toggleSupergroupSignMessages(int53 supergroup_id_, bool sign_messages_)
  : supergroup_id_(supergroup_id_)
  , sign_messages_(sign_messages_)
{}

const std::int32_t toggleSupergroupSignMessages::ID;

void toggleSupergroupSignMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupSignMessages");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("sign_messages", sign_messages_);
    s.store_class_end();
  }
}

transferChatOwnership::transferChatOwnership()
  : chat_id_()
  , user_id_()
  , password_()
{}

transferChatOwnership::transferChatOwnership(int53 chat_id_, int53 user_id_, string const &password_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
  , password_(password_)
{}

const std::int32_t transferChatOwnership::ID;

void transferChatOwnership::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "transferChatOwnership");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("password", password_);
    s.store_class_end();
  }
}

translateText::translateText()
  : text_()
  , from_language_code_()
  , to_language_code_()
{}

translateText::translateText(string const &text_, string const &from_language_code_, string const &to_language_code_)
  : text_(text_)
  , from_language_code_(from_language_code_)
  , to_language_code_(to_language_code_)
{}

const std::int32_t translateText::ID;

void translateText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "translateText");
    s.store_field("text", text_);
    s.store_field("from_language_code", from_language_code_);
    s.store_field("to_language_code", to_language_code_);
    s.store_class_end();
  }
}

unpinAllChatMessages::unpinAllChatMessages()
  : chat_id_()
{}

unpinAllChatMessages::unpinAllChatMessages(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t unpinAllChatMessages::ID;

void unpinAllChatMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unpinAllChatMessages");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

unpinChatMessage::unpinChatMessage()
  : chat_id_()
  , message_id_()
{}

unpinChatMessage::unpinChatMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t unpinChatMessage::ID;

void unpinChatMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unpinChatMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

upgradeBasicGroupChatToSupergroupChat::upgradeBasicGroupChatToSupergroupChat()
  : chat_id_()
{}

upgradeBasicGroupChatToSupergroupChat::upgradeBasicGroupChatToSupergroupChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t upgradeBasicGroupChatToSupergroupChat::ID;

void upgradeBasicGroupChatToSupergroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradeBasicGroupChatToSupergroupChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

uploadFile::uploadFile()
  : file_()
  , file_type_()
  , priority_()
{}

uploadFile::uploadFile(object_ptr<InputFile> &&file_, object_ptr<FileType> &&file_type_, int32 priority_)
  : file_(std::move(file_))
  , file_type_(std::move(file_type_))
  , priority_(priority_)
{}

const std::int32_t uploadFile::ID;

void uploadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "uploadFile");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_field("priority", priority_);
    s.store_class_end();
  }
}

uploadStickerFile::uploadStickerFile()
  : user_id_()
  , sticker_()
{}

uploadStickerFile::uploadStickerFile(int53 user_id_, object_ptr<inputSticker> &&sticker_)
  : user_id_(user_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t uploadStickerFile::ID;

void uploadStickerFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "uploadStickerFile");
    s.store_field("user_id", user_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

validateOrderInfo::validateOrderInfo()
  : chat_id_()
  , message_id_()
  , order_info_()
  , allow_save_()
{}

validateOrderInfo::validateOrderInfo(int53 chat_id_, int53 message_id_, object_ptr<orderInfo> &&order_info_, bool allow_save_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , order_info_(std::move(order_info_))
  , allow_save_(allow_save_)
{}

const std::int32_t validateOrderInfo::ID;

void validateOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "validateOrderInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_field("allow_save", allow_save_);
    s.store_class_end();
  }
}

viewMessages::viewMessages()
  : chat_id_()
  , message_thread_id_()
  , message_ids_()
  , force_read_()
{}

viewMessages::viewMessages(int53 chat_id_, int53 message_thread_id_, array<int53> &&message_ids_, bool force_read_)
  : chat_id_(chat_id_)
  , message_thread_id_(message_thread_id_)
  , message_ids_(std::move(message_ids_))
  , force_read_(force_read_)
{}

const std::int32_t viewMessages::ID;

void viewMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_thread_id", message_thread_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("force_read", force_read_);
    s.store_class_end();
  }
}

viewTrendingStickerSets::viewTrendingStickerSets()
  : sticker_set_ids_()
{}

viewTrendingStickerSets::viewTrendingStickerSets(array<int64> &&sticker_set_ids_)
  : sticker_set_ids_(std::move(sticker_set_ids_))
{}

const std::int32_t viewTrendingStickerSets::ID;

void viewTrendingStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewTrendingStickerSets");
    { s.store_vector_begin("sticker_set_ids", sticker_set_ids_.size()); for (const auto &_value : sticker_set_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

writeGeneratedFilePart::writeGeneratedFilePart()
  : generation_id_()
  , offset_()
  , data_()
{}

writeGeneratedFilePart::writeGeneratedFilePart(int64 generation_id_, int32 offset_, bytes const &data_)
  : generation_id_(generation_id_)
  , offset_(offset_)
  , data_(std::move(data_))
{}

const std::int32_t writeGeneratedFilePart::ID;

void writeGeneratedFilePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "writeGeneratedFilePart");
    s.store_field("generation_id", generation_id_);
    s.store_field("offset", offset_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
