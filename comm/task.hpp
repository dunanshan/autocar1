/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#include <lcm/lcm_coretypes.h>

#ifndef __comm_task_hpp__
#define __comm_task_hpp__

#include <string>
#include "comm/point.hpp"
#include "comm/point.hpp"

namespace comm
{

/// user request service info
class task
{
    public:
        int32_t    userID;

        comm::point on;

        comm::point off;

        std::string detail;

    public:
        /**
         * Encode a message into binary form.
         *
         * @param buf The output buffer.
         * @param offset Encoding starts at thie byte offset into @p buf.
         * @param maxlen Maximum number of bytes to write.  This should generally be
         *  equal to getEncodedSize().
         * @return The number of bytes encoded, or <0 on error.
         */
        inline int encode(void *buf, int offset, int maxlen) const;

        /**
         * Check how many bytes are required to encode this message.
         */
        inline int getEncodedSize() const;

        /**
         * Decode a message from binary form into this instance.
         *
         * @param buf The buffer containing the encoded message.
         * @param offset The byte offset into @p buf where the encoded message starts.
         * @param maxlen The maximum number of bytes to reqad while decoding.
         * @return The number of bytes decoded, or <0 if an error occured.
         */
        inline int decode(const void *buf, int offset, int maxlen);

        /**
         * Retrieve the 64-bit fingerprint identifying the structure of the message.
         * Note that the fingerprint is the same for all instances of the same
         * message type, and is a fingerprint on the message type definition, not on
         * the message contents.
         */
        inline static int64_t getHash();

        /**
         * Returns "task"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int task::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = (int64_t)getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int task::decode(const void *buf, int offset, int maxlen)
{
    int pos = 0, thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int task::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t task::getHash()
{
    static int64_t hash = _computeHash(NULL);
    return hash;
}

const char* task::getTypeName()
{
    return "task";
}

int task::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->userID, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->on._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->off._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    char* detail_cstr = (char*) this->detail.c_str();
    tlen = __string_encode_array(buf, offset + pos, maxlen - pos, &detail_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int task::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->userID, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->on._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->off._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    int32_t __detail_len__;
    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &__detail_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__detail_len__ > maxlen - pos) return -1;
    this->detail.assign(((const char*)buf) + offset + pos, __detail_len__ - 1);
    pos += __detail_len__;

    return pos;
}

int task::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += this->on._getEncodedSizeNoHash();
    enc_size += this->off._getEncodedSizeNoHash();
    enc_size += this->detail.size() + 4 + 1;
    return enc_size;
}

uint64_t task::_computeHash(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for(fp = p; fp != NULL; fp = fp->parent)
        if(fp->v == task::getHash)
            return 0;
    const __lcm_hash_ptr cp = { p, (void*)task::getHash };

    uint64_t hash = 0xa0dd379db50dc4ceLL +
         comm::point::_computeHash(&cp) +
         comm::point::_computeHash(&cp);

    return (hash<<1) + ((hash>>63)&1);
}

}

#endif