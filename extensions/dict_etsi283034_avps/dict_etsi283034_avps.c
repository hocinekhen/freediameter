/*
* Copyright (c) 2017 Sprint
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/****************
 Generated By: fdtool enhancements to diafuzzer
 License: same as freeDiameter
****************/


/* 
 * Dictionary definitions of objects specified in etsi283034_avps.
 */
#include <freeDiameter/extension.h>

#define PROTO_VER "unspecified"
#define GEN_DATE  1506697184.91

const char *etsi283034_avps_proto_ver = PROTO_VER;
const double etsi283034_avps_gen_date = GEN_DATE;

/* The content of this file follows the same structure as dict_base_proto.c */

#define CHECK_dict_new( _type, _data, _parent, _ref )                                     \
{                                                                                         \
    int _ret = fd_dict_new( fd_g_config->cnf_dict, (_type), (_data), (_parent), (_ref) ); \
    if ( _ret != 0 && _ret != EEXIST )                                                    \
       return _ret;                                                                       \
}

#define CHECK_dict_search( _type, _criteria, _what, _result )		\
    CHECK_FCT(  fd_dict_search( fd_g_config->cnf_dict, (_type), (_criteria), (_what), (_result), ENOENT) );

struct local_rules_definition {
    struct dict_avp_request avp_vendor_plus_name;
    enum rule_position	position;
    int 			min;
    int			max;
};

#define RULE_ORDER( _position ) ((((_position) == RULE_FIXED_HEAD) || ((_position) == RULE_FIXED_TAIL)) ? 1 : 0 )

/* Attention! This version of the macro uses AVP_BY_NAME_AND_VENDOR, in contrast to most other copies! */
#define PARSE_loc_rules( _rulearray, _parent) {                                                         \
        int __ar;                                                                                       \
        for (__ar=0; __ar < sizeof(_rulearray) / sizeof((_rulearray)[0]); __ar++) {                     \
                struct dict_rule_data __data = { NULL,                                                  \
                        (_rulearray)[__ar].position,                                                    \
                        0,                                                                              \
                        (_rulearray)[__ar].min,                                                         \
                        (_rulearray)[__ar].max};                                                        \
                __data.rule_order = RULE_ORDER(__data.rule_position);                                   \
                CHECK_FCT(  fd_dict_search(                                                             \
                        fd_g_config->cnf_dict,                                                          \
                        DICT_AVP,                                                                       \
                        AVP_BY_NAME_AND_VENDOR,                                                         \
                        &(_rulearray)[__ar].avp_vendor_plus_name,                                       \
                        &__data.rule_avp, 0 ) );                                                        \
                if ( !__data.rule_avp ) {                                                               \
                        TRACE_DEBUG(INFO, "AVP Not found: '%s'", (_rulearray)[__ar].avp_vendor_plus_name.avp_name);             \
                        return ENOENT;                                                                  \
                }                                                                                       \
                {                                                                                       \
                         int _ret = fd_dict_new( fd_g_config->cnf_dict, DICT_RULE, &(__data), (_parent), NULL ); \
                         if ( _ret != 0 && _ret != EEXIST )      {                                      \
                                TRACE_DEBUG(INFO, "Error on rule with AVP '%s'",                        \
                                            (_rulearray)[__ar].avp_vendor_plus_name.avp_name);          \
                                return EINVAL;                                                          \
                         }                                                                              \
                }                                                                                       \
        }                                                                                               \
}

#define CHECK_vendor_new( _data ) { \
        struct dict_object * vendor_found; \
        if (fd_dict_search(fd_g_config->cnf_dict,DICT_VENDOR,VENDOR_BY_ID,&_data.vendor_id,&vendor_found,ENOENT) == ENOENT) { \
                CHECK_FCT(fd_dict_new(fd_g_config->cnf_dict, DICT_VENDOR, &_data, NULL, NULL)); \
        } \
}

#define enumval_def_u32( _val_, _str_ )		\
    { _str_, 		{ .u32 = _val_ }}

#define enumval_def_os( _len_, _val_, _str_ )				\
    { _str_, 		{ .os = { .data = (unsigned char *)_val_, .len = _len_ }}}


static int dict_etsi283034_avps_load_defs(char * conffile)
{
   TRACE_ENTRY("%p", conffile);
	/* Application Section */
	{
		/* Create the vendors */		{
			struct dict_vendor_data vendor_data = { 13019, "ETSI" };
			CHECK_dict_new(DICT_VENDOR, &vendor_data, NULL, NULL)
		}
	}


   /* AVP section */
   {
		struct dict_object * Address_type;
		struct dict_object * UTF8String_type;
		struct dict_object * DiameterIdentity_type;
		struct dict_object * DiameterURI_type;
		struct dict_object * Time_type;
		struct dict_object * IPFilterRule_type;

		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "Address", &Address_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "UTF8String", &UTF8String_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "DiameterIdentity", &DiameterIdentity_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "DiameterURI", &DiameterURI_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "Time", &Time_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "IPFilterRule", &IPFilterRule_type);
		/* Address-Realm */
		{
			struct dict_avp_data data = {
				301,	/* Code */
				13019,	/* Vendor */
				"Address-Realm",	/* Name */
				AVP_FLAG_VENDOR | AVP_FLAG_MANDATORY,	/* Fixed flags */
				AVP_FLAG_VENDOR | AVP_FLAG_MANDATORY,	/* Fixed flag values */
				AVP_TYPE_OCTETSTRING	/* base type of data */
			};
			CHECK_dict_new( DICT_AVP, &data, NULL, NULL);
		};
		/* Logical-Access-Id */
		{
			struct dict_avp_data data = {
				302,	/* Code */
				13019,	/* Vendor */
				"Logical-Access-Id",	/* Name */
				AVP_FLAG_VENDOR,	/* Fixed flags */
				AVP_FLAG_VENDOR,	/* Fixed flag values */
				AVP_TYPE_OCTETSTRING	/* base type of data */
			};
			CHECK_dict_new( DICT_AVP, &data, NULL, NULL);
		};
		/* Physical-Access-Id */
		{
			struct dict_avp_data data = {
				303,	/* Code */
				13019,	/* Vendor */
				"Physical-Access-Id",	/* Name */
				AVP_FLAG_VENDOR,	/* Fixed flags */
				AVP_FLAG_VENDOR,	/* Fixed flag values */
				AVP_TYPE_OCTETSTRING	/* base type of data */
			};
			CHECK_dict_new( DICT_AVP, &data, UTF8String_type, NULL);
		};
		/* Line-Identifier */
		{
			struct dict_avp_data data = {
				500,	/* Code */
				13019,	/* Vendor */
				"Line-Identifier",	/* Name */
				AVP_FLAG_VENDOR | AVP_FLAG_MANDATORY,	/* Fixed flags */
				AVP_FLAG_VENDOR,	/* Fixed flag values */
				AVP_TYPE_OCTETSTRING	/* base type of data */
			};
			CHECK_dict_new( DICT_AVP, &data, UTF8String_type, NULL);
		};
		/* Reservation-Priority */
		{
			struct dict_avp_data data = {
				458,	/* Code */
				13019,	/* Vendor */
				"Reservation-Priority",	/* Name */
				AVP_FLAG_VENDOR | AVP_FLAG_MANDATORY,	/* Fixed flags */
				AVP_FLAG_VENDOR,	/* Fixed flag values */
				AVP_TYPE_INTEGER32	/* base type of data */
			};
			struct dict_object        *type;
			struct dict_type_data     tdata = { AVP_TYPE_INTEGER32, "ETSI/Enumerated(Reservation-Priority)", NULL, NULL, NULL };
			struct dict_enumval_data        t_1 = { "PRIORITY_ONE", { .i32=1 }};
			struct dict_enumval_data        t_2 = { "PRIORITY_TWO", { .i32=2 }};
			struct dict_enumval_data        t_3 = { "PRIORITY_THREE", { .i32=3 }};
			struct dict_enumval_data        t_4 = { "PRIORITY_FOUR", { .i32=4 }};
			struct dict_enumval_data        t_5 = { "PRIORITY_FIVE", { .i32=5 }};
			struct dict_enumval_data        t_6 = { "PRIORITY_SIX", { .i32=6 }};
			struct dict_enumval_data        t_7 = { "PRIORITY_SEVEN", { .i32=7 }};
			/* Create the Enumerated type, and then the AVP */
			CHECK_dict_new( DICT_TYPE, &tdata, NULL, &type);
			CHECK_dict_new( DICT_ENUMVAL, &t_1, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_2, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_3, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_4, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_5, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_6, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_7, type, NULL);
			CHECK_dict_new( DICT_AVP, &data, type, NULL);
		};

	
   }

   /* Commands section */
   {

   }

   return 0;
}

static int dict_etsi283034_avps_load_rules(char * conffile)
{
   /* Grouped AVP section */
   {

   }	

   /* Commands section */
   {

   }

   LOG_D( "Extension 'Dictionary definitions for etsi283034_avps (None)' initialized");
   return 0;
}

int dict_entry(char * conffile)
{
	dict_etsi283034_avps_load_defs(conffile);
	return dict_etsi283034_avps_load_rules(conffile);
}

const char* dict_etsi283034_avps_proto_ver(char * conffile) {
	return etsi283034_avps_proto_ver;
}

const double dict_etsi283034_avps_gen_ts(char * conffile) {
	return etsi283034_avps_gen_date;
}

EXTENSION_ENTRY2("dict_etsi283034_avps", dict_etsi283034_avps_load_defs, dict_etsi283034_avps_load_rules);



