/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef {{apiName|upper}}_MESSAGES_H_INCLUDE_GUARD
#define {{apiName|upper}}_MESSAGES_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR "{{idString}}"

#ifdef MK_TOOLS_BUILD
    extern const char** {{apiName}}_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*{{apiName}}_ServiceInstanceNamePtr)
#else
    #define SERVICE_INSTANCE_NAME "{{serviceName}}"
#endif


// todo: This will need to depend on the particular protocol, but the exact size is not easy to
//       calculate right now, so in the meantime, pick a reasonably large size.  Once interface
//       type support has been added, this will be replaced by a more appropriate size.
{#- Message size hack carried over from original C ifgen.  Will be fixed soon as this was one of
 # the motivating factors for refactoring ifgen #}
{%- if apiName in [ "le_secStore", "secStoreGlobal", "secStoreAdmin", "le_fs" ] %}
#define _MAX_MSG_SIZE 8500
{%- elif apiName == "le_cfg" %}
#define _MAX_MSG_SIZE 1600
{%- else %}
#define _MAX_MSG_SIZE 1100
{%- endif %}

// Define the message type for communicating between client and server
typedef struct
{
    uint32_t id;
    uint8_t buffer[_MAX_MSG_SIZE];
}
_Message_t;
{% for function in functions %}
#define _MSGID_{{apiName}}_{{function.name}} {{loop.index0}}
{%- endfor %}


#endif // {{apiName|upper}}_MESSAGES_H_INCLUDE_GUARD
