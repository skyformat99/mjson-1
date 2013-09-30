/* Generated by re2c 0.13.6 on Sun Sep 22 13:50:24 2013 */
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
#include <memory.h>

#include "mjson.h"

/* mjson: - no {} needed around the whole file
- "=" is allowed instead of ":"
- quotes around the key are optional
- commas after values are optional 
- and c-style comments allowed */

#define TOK_NONE                   0
#define TOK_IDENTIFIER             1
#define TOK_NOESC_STRING           2
#define TOK_STRING                 3
#define TOK_OCT_NUMBER             4
#define TOK_HEX_NUMBER             5
#define TOK_DEC_NUMBER             6
#define TOK_FLOAT_NUMBER           7
#define TOK_COMMA                  8
#define TOK_COLON                  9
#define TOK_EQUAL                 10
#define TOK_LEFT_BRACKET          11
#define TOK_RIGHT_BRACKET         12
#define TOK_LEFT_CURVE_BRACKET    13
#define TOK_RIGHT_CURVE_BRACKET   14
#define TOK_FALSE                 15
#define TOK_TRUE                  16
#define TOK_NULL                  17
#define TOK_WHITESPACE            18
#define TOK_INVALID               19

#define TRUE  1
#define FALSE 0
#define return_val_if_fail(cond, val) if (!(cond)) return (val)
#define return_if_fail(cond) if (!(cond)) return
#define INT64_T_FORMAT "lld"
#define MAX_UTF8_CHAR_LEN 6

typedef unsigned int  uint;
typedef unsigned char uchar;

#define BJSON_ID_NULL            0
#define BJSON_ID_FALSE           1
#define BJSON_ID_EMPTY_STRING    2
#define BJSON_ID_TRUE            3

#define BJSON_ID_UINT8           4
#define BJSON_ID_UINT16          5
#define BJSON_ID_UINT32          6
#define BJSON_ID_UINT64          7

#define BJSON_ID_SINT8           8
#define BJSON_ID_SINT16          9
#define BJSON_ID_SINT32         10
#define BJSON_ID_SINT64         11

#define BJSON_ID_FLOAT32        12
#define BJSON_ID_FLOAT64        13

#define BJSON_ID_UTF8_STRING8   16
#define BJSON_ID_UTF8_STRING16  17
#define BJSON_ID_UTF8_STRING32  18
#define BJSON_ID_UTF8_STRING64  19

#define BJSON_ID_BINARY8        20
#define BJSON_ID_BINARY16       21
#define BJSON_ID_BINARY32       22
#define BJSON_ID_BINARY64       23

#define BJSON_ID_ARRAY8         32
#define BJSON_ID_ARRAY16        33
#define BJSON_ID_ARRAY32        34
#define BJSON_ID_ARRAY64        35

#define BJSON_ID_DICT8          36
#define BJSON_ID_DICT16         37
#define BJSON_ID_DICT32         38
#define BJSON_ID_DICT64         39

static void unicode_cp_to_utf8(uint32_t uni_cp, char* utf8char/*[6]*/, size_t* charlen)
{
    uint32_t first, i;
    
    if (uni_cp < 0x80)
    {
        first   = 0;
        *charlen = 1;
    }
    else if (uni_cp < 0x800)
    {
        first   = 0xc0;
        *charlen = 2;
    }
    else if (uni_cp < 0x10000)
    {
        first   = 0xe0;
        *charlen = 3;
    }
    else if (uni_cp < 0x200000)
    {
        first   = 0xf0;
        *charlen = 4;
    }
    else if (uni_cp < 0x4000000)
    {
        first   = 0xf8;
        *charlen = 5;
    }
    else
    {
        first   = 0xfc;
        *charlen = 6;
    }

    for (i = *charlen - 1; i > 0; --i)
    {
        utf8char[i] = (uni_cp & 0x3f) | 0x80;
        uni_cp >>= 6;
    }
    utf8char[0] = uni_cp | first;
}

static void mjson_next_token(mjson_parser_t* context)
{
#define YYREADINPUT(c) (c>=e?0:*c)
#define YYCTYPE        char
#define YYCURSOR       c
#define YYMARKER       m



    const char* c = context->next;
    const char* e = context->end;
    const char* m = NULL;
    const char* s;
    int token = TOK_NONE;

    assert(context);
    return_if_fail(context->next != NULL);

    while (TRUE)
    {
        s = c;


        {
            YYCTYPE yych;
            unsigned int yyaccept = 0;

            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '<') {
                if (yych <= '"') {
                    if (yych <= '\f') {
                        if (yych <= 0x00) goto yy31;
                        if (yych <= 0x08) goto yy33;
                        if (yych >= '\v') goto yy33;
                    } else {
                        if (yych <= 0x1F) {
                            if (yych >= 0x0E) goto yy33;
                        } else {
                            if (yych <= ' ') goto yy2;
                            if (yych <= '!') goto yy33;
                            goto yy30;
                        }
                    }
                } else {
                    if (yych <= '.') {
                        if (yych <= '+') {
                            if (yych <= '*') goto yy33;
                            goto yy22;
                        } else {
                            if (yych <= ',') goto yy18;
                            if (yych <= '-') goto yy22;
                            goto yy24;
                        }
                    } else {
                        if (yych <= '0') {
                            if (yych <= '/') goto yy4;
                            goto yy20;
                        } else {
                            if (yych <= '9') goto yy23;
                            if (yych <= ':') goto yy14;
                            goto yy33;
                        }
                    }
                }
            } else {
                if (yych <= 'e') {
                    if (yych <= '\\') {
                        if (yych <= '@') {
                            if (yych <= '=') goto yy16;
                            goto yy33;
                        } else {
                            if (yych <= 'Z') goto yy29;
                            if (yych <= '[') goto yy10;
                            goto yy33;
                        }
                    } else {
                        if (yych <= '^') {
                            if (yych <= ']') goto yy12;
                            goto yy33;
                        } else {
                            if (yych == '`') goto yy33;
                            goto yy29;
                        }
                    }
                } else {
                    if (yych <= 't') {
                        if (yych <= 'm') {
                            if (yych <= 'f') goto yy27;
                            goto yy29;
                        } else {
                            if (yych <= 'n') goto yy28;
                            if (yych <= 's') goto yy29;
                            goto yy25;
                        }
                    } else {
                        if (yych <= '{') {
                            if (yych <= 'z') goto yy29;
                            goto yy6;
                        } else {
                            if (yych == '}') goto yy8;
                            goto yy33;
                        }
                    }
                }
            }
yy2:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            goto yy126;
yy3:
            {
                continue; 
            }
yy4:
            yyaccept = 0;
            ++YYCURSOR;
            YYMARKER = YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych == '*') goto yy108;
            if (yych == '/') goto yy110;
yy5:
            {
                context->token = TOK_INVALID;
                return;
            }
yy6:
            ++YYCURSOR;
            {
                token = TOK_LEFT_CURVE_BRACKET;
                goto done;
            }
yy8:
            ++YYCURSOR;
            {
                token = TOK_RIGHT_CURVE_BRACKET;
                goto done;
            }
yy10:
            ++YYCURSOR;
            {
                token = TOK_LEFT_BRACKET;
                goto done;
            }
yy12:
            ++YYCURSOR;
            {
                token = TOK_RIGHT_BRACKET;
                goto done;
            }
yy14:
            ++YYCURSOR;
            {
                token = TOK_COLON;
                goto done;
            }
yy16:
            ++YYCURSOR;
            {
                token = TOK_EQUAL;
                goto done;
            }
yy18:
            ++YYCURSOR;
            {
                token = TOK_COMMA;
                goto done;
            }
yy20:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 'X') {
                if (yych <= '/') {
                    if (yych == '.') goto yy100;
                } else {
                    if (yych <= '9') goto yy100;
                    if (yych <= '@') goto yy21;
                    if (yych <= 'W') goto yy100;
                    goto yy104;
                }
            } else {
                if (yych <= '`') {
                    if (yych <= 'Z') goto yy100;
                    if (yych == '_') goto yy100;
                } else {
                    if (yych == 'x') goto yy104;
                    if (yych <= 'z') goto yy100;
                }
            }
yy21:
            {
                token = TOK_DEC_NUMBER;
                goto done;
            }
yy22:
            yyaccept = 0;
            ++YYCURSOR;
            YYMARKER = YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '/') {
                if (yych == '.') goto yy95;
                goto yy5;
            } else {
                if (yych <= '0') goto yy92;
                if (yych <= '9') goto yy93;
                goto yy5;
            }
yy23:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            goto yy71;
yy24:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '/') goto yy5;
            if (yych <= '9') goto yy63;
            goto yy5;
yy25:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych == 'r') goto yy59;
            goto yy49;
yy26:
            {
                token = TOK_IDENTIFIER;
                goto done;
            }
yy27:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych == 'a') goto yy54;
            goto yy49;
yy28:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych == 'u') goto yy50;
            goto yy49;
yy29:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            goto yy49;
yy30:
            yyaccept = 0;
            ++YYCURSOR;
            YYMARKER = YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 0x00) goto yy5;
            goto yy35;
yy31:
            ++YYCURSOR;
            { 
                context->token = TOK_NONE;
                return;
            }
yy33:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            goto yy5;
yy34:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
yy35:
            if (yych <= '"') {
                if (yych <= 0x00) goto yy36;
                if (yych <= '!') goto yy34;
                goto yy38;
            } else {
                if (yych == '\\') goto yy37;
                goto yy34;
            }
yy36:
            YYCURSOR = YYMARKER;
            if (yyaccept <= 2) {
                if (yyaccept <= 1) {
                    if (yyaccept == 0) {
                        goto yy5;
                    } else {
                        goto yy65;
                    }
                } else {
                    goto yy74;
                }
            } else {
                if (yyaccept == 3) {
                    goto yy21;
                } else {
                    goto yy120;
                }
            }
yy37:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 'e') {
                if (yych <= '/') {
                    if (yych == '"') goto yy41;
                    if (yych <= '.') goto yy36;
                    goto yy41;
                } else {
                    if (yych <= '\\') {
                        if (yych <= '[') goto yy36;
                        goto yy41;
                    } else {
                        if (yych == 'b') goto yy41;
                        goto yy36;
                    }
                }
            } else {
                if (yych <= 'q') {
                    if (yych <= 'f') goto yy41;
                    if (yych == 'n') goto yy41;
                    goto yy36;
                } else {
                    if (yych <= 's') {
                        if (yych <= 'r') goto yy41;
                        goto yy36;
                    } else {
                        if (yych <= 't') goto yy41;
                        if (yych <= 'u') goto yy40;
                        goto yy36;
                    }
                }
            }
yy38:
            ++YYCURSOR;
            {
                token = TOK_NOESC_STRING;
                goto done;
            }
yy40:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '@') {
                if (yych <= '/') goto yy36;
                if (yych <= '9') goto yy45;
                goto yy36;
            } else {
                if (yych <= 'F') goto yy45;
                if (yych <= '`') goto yy36;
                if (yych <= 'f') goto yy45;
                goto yy36;
            }
yy41:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '"') {
                if (yych <= 0x00) goto yy36;
                if (yych <= '!') goto yy41;
            } else {
                if (yych == '\\') goto yy37;
                goto yy41;
            }
            ++YYCURSOR;
            {
                token = TOK_STRING;
                goto done;
            }
yy45:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '@') {
                if (yych <= '/') goto yy36;
                if (yych >= ':') goto yy36;
            } else {
                if (yych <= 'F') goto yy46;
                if (yych <= '`') goto yy36;
                if (yych >= 'g') goto yy36;
            }
yy46:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '@') {
                if (yych <= '/') goto yy36;
                if (yych >= ':') goto yy36;
            } else {
                if (yych <= 'F') goto yy47;
                if (yych <= '`') goto yy36;
                if (yych >= 'g') goto yy36;
            }
yy47:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '@') {
                if (yych <= '/') goto yy36;
                if (yych <= '9') goto yy41;
                goto yy36;
            } else {
                if (yych <= 'F') goto yy41;
                if (yych <= '`') goto yy36;
                if (yych <= 'f') goto yy41;
                goto yy36;
            }
yy48:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
yy49:
            if (yych <= 'Z') {
                if (yych <= '/') goto yy26;
                if (yych <= '9') goto yy48;
                if (yych <= '@') goto yy26;
                goto yy48;
            } else {
                if (yych <= '_') {
                    if (yych <= '^') goto yy26;
                    goto yy48;
                } else {
                    if (yych <= '`') goto yy26;
                    if (yych <= 'z') goto yy48;
                    goto yy26;
                }
            }
yy50:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych != 'l') goto yy49;
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych != 'l') goto yy49;
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 'Z') {
                if (yych <= '/') goto yy53;
                if (yych <= '9') goto yy48;
                if (yych >= 'A') goto yy48;
            } else {
                if (yych <= '_') {
                    if (yych >= '_') goto yy48;
                } else {
                    if (yych <= '`') goto yy53;
                    if (yych <= 'z') goto yy48;
                }
            }
yy53:
            {
                token = TOK_NULL;
                goto done;
            }
yy54:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych != 'l') goto yy49;
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych != 's') goto yy49;
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych != 'e') goto yy49;
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 'Z') {
                if (yych <= '/') goto yy58;
                if (yych <= '9') goto yy48;
                if (yych >= 'A') goto yy48;
            } else {
                if (yych <= '_') {
                    if (yych >= '_') goto yy48;
                } else {
                    if (yych <= '`') goto yy58;
                    if (yych <= 'z') goto yy48;
                }
            }
yy58:
            {
                token = TOK_FALSE;
                goto done;
            }
yy59:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych != 'u') goto yy49;
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych != 'e') goto yy49;
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 'Z') {
                if (yych <= '/') goto yy62;
                if (yych <= '9') goto yy48;
                if (yych >= 'A') goto yy48;
            } else {
                if (yych <= '_') {
                    if (yych >= '_') goto yy48;
                } else {
                    if (yych <= '`') goto yy62;
                    if (yych <= 'z') goto yy48;
                }
            }
yy62:
            {
                token = TOK_TRUE;
                goto done;
            }
yy63:
            yyaccept = 1;
            ++YYCURSOR;
            YYMARKER = YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 'D') {
                if (yych <= '/') goto yy65;
                if (yych <= '9') goto yy63;
            } else {
                if (yych <= 'E') goto yy66;
                if (yych == 'e') goto yy66;
            }
yy65:
            {
                token = TOK_FLOAT_NUMBER;
                goto done;
            }
yy66:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= ',') {
                if (yych != '+') goto yy36;
            } else {
                if (yych <= '-') goto yy67;
                if (yych <= '/') goto yy36;
                if (yych <= '9') goto yy68;
                goto yy36;
            }
yy67:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '/') goto yy36;
            if (yych >= ':') goto yy36;
yy68:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '/') goto yy65;
            if (yych <= '9') goto yy68;
            goto yy65;
yy70:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
yy71:
            if (yych <= 'E') {
                if (yych <= '/') {
                    if (yych == '.') goto yy76;
                    goto yy21;
                } else {
                    if (yych <= '9') goto yy70;
                    if (yych <= '@') goto yy21;
                    if (yych >= 'E') goto yy75;
                }
            } else {
                if (yych <= '`') {
                    if (yych <= 'Z') goto yy72;
                    if (yych != '_') goto yy21;
                } else {
                    if (yych == 'e') goto yy75;
                    if (yych >= '{') goto yy21;
                }
            }
yy72:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 'Z') {
                if (yych <= '/') goto yy74;
                if (yych <= '9') goto yy72;
                if (yych >= 'A') goto yy72;
            } else {
                if (yych <= '_') {
                    if (yych >= '_') goto yy72;
                } else {
                    if (yych <= '`') goto yy74;
                    if (yych <= 'z') goto yy72;
                }
            }
yy74:
            {
                context->token = TOK_INVALID;
                return;
            }
yy75:
            yyaccept = 2;
            ++YYCURSOR;
            YYMARKER = YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '9') {
                if (yych <= ',') {
                    if (yych == '+') goto yy87;
                    goto yy74;
                } else {
                    if (yych <= '-') goto yy87;
                    if (yych <= '/') goto yy74;
                    goto yy88;
                }
            } else {
                if (yych <= '^') {
                    if (yych <= '@') goto yy74;
                    if (yych <= 'Z') goto yy72;
                    goto yy74;
                } else {
                    if (yych == '`') goto yy74;
                    if (yych <= 'z') goto yy72;
                    goto yy74;
                }
            }
yy76:
            yyaccept = 1;
            ++YYCURSOR;
            YYMARKER = YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych == 'E') goto yy79;
            if (yych == 'e') goto yy79;
            goto yy78;
yy77:
            yyaccept = 1;
            ++YYCURSOR;
            YYMARKER = YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
yy78:
            if (yych <= 'D') {
                if (yych <= '/') goto yy65;
                if (yych <= '9') goto yy77;
                goto yy65;
            } else {
                if (yych <= 'E') goto yy83;
                if (yych == 'e') goto yy83;
                goto yy65;
            }
yy79:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= ',') {
                if (yych != '+') goto yy36;
            } else {
                if (yych <= '-') goto yy80;
                if (yych <= '/') goto yy36;
                if (yych <= '9') goto yy81;
                goto yy36;
            }
yy80:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '/') goto yy36;
            if (yych >= ':') goto yy36;
yy81:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '/') goto yy65;
            if (yych <= '9') goto yy81;
            goto yy65;
yy83:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= ',') {
                if (yych != '+') goto yy36;
            } else {
                if (yych <= '-') goto yy84;
                if (yych <= '/') goto yy36;
                if (yych <= '9') goto yy85;
                goto yy36;
            }
yy84:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '/') goto yy36;
            if (yych >= ':') goto yy36;
yy85:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '/') goto yy65;
            if (yych <= '9') goto yy85;
            goto yy65;
yy87:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '/') goto yy36;
            if (yych <= '9') goto yy90;
            goto yy36;
yy88:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 'Z') {
                if (yych <= '/') goto yy65;
                if (yych <= '9') goto yy88;
                if (yych <= '@') goto yy65;
                goto yy72;
            } else {
                if (yych <= '_') {
                    if (yych <= '^') goto yy65;
                    goto yy72;
                } else {
                    if (yych <= '`') goto yy65;
                    if (yych <= 'z') goto yy72;
                    goto yy65;
                }
            }
yy90:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '/') goto yy65;
            if (yych <= '9') goto yy90;
            goto yy65;
yy92:
            yyaccept = 3;
            ++YYCURSOR;
            YYMARKER = YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '9') {
                if (yych == '.') goto yy76;
                if (yych <= '/') goto yy21;
                goto yy97;
            } else {
                if (yych <= 'E') {
                    if (yych <= 'D') goto yy21;
                    goto yy96;
                } else {
                    if (yych == 'e') goto yy96;
                    goto yy21;
                }
            }
yy93:
            yyaccept = 3;
            ++YYCURSOR;
            YYMARKER = YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '9') {
                if (yych == '.') goto yy76;
                if (yych <= '/') goto yy21;
                goto yy93;
            } else {
                if (yych <= 'E') {
                    if (yych <= 'D') goto yy21;
                    goto yy96;
                } else {
                    if (yych == 'e') goto yy96;
                    goto yy21;
                }
            }
yy95:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '/') goto yy36;
            if (yych <= '9') goto yy63;
            goto yy36;
yy96:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= ',') {
                if (yych == '+') goto yy87;
                goto yy36;
            } else {
                if (yych <= '-') goto yy87;
                if (yych <= '/') goto yy36;
                if (yych <= '9') goto yy90;
                goto yy36;
            }
yy97:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '9') {
                if (yych == '.') goto yy76;
                if (yych <= '/') goto yy36;
                goto yy97;
            } else {
                if (yych <= 'E') {
                    if (yych <= 'D') goto yy36;
                    goto yy96;
                } else {
                    if (yych == 'e') goto yy96;
                    goto yy36;
                }
            }
yy99:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
yy100:
            if (yych <= 'E') {
                if (yych <= '7') {
                    if (yych == '.') goto yy76;
                    if (yych >= '0') goto yy99;
                } else {
                    if (yych <= '9') goto yy102;
                    if (yych <= '@') goto yy101;
                    if (yych <= 'D') goto yy72;
                    goto yy75;
                }
            } else {
                if (yych <= '`') {
                    if (yych <= 'Z') goto yy72;
                    if (yych == '_') goto yy72;
                } else {
                    if (yych == 'e') goto yy75;
                    if (yych <= 'z') goto yy72;
                }
            }
yy101:
            {
                token = TOK_OCT_NUMBER;
                goto done;
            }
yy102:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 'E') {
                if (yych <= '/') {
                    if (yych == '.') goto yy76;
                    goto yy74;
                } else {
                    if (yych <= '9') goto yy102;
                    if (yych <= '@') goto yy74;
                    if (yych <= 'D') goto yy72;
                    goto yy75;
                }
            } else {
                if (yych <= '`') {
                    if (yych <= 'Z') goto yy72;
                    if (yych == '_') goto yy72;
                    goto yy74;
                } else {
                    if (yych == 'e') goto yy75;
                    if (yych <= 'z') goto yy72;
                    goto yy74;
                }
            }
yy104:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 'Z') {
                if (yych <= '/') goto yy74;
                if (yych <= '9') goto yy106;
                if (yych <= '@') goto yy74;
                goto yy106;
            } else {
                if (yych <= '_') {
                    if (yych <= '^') goto yy74;
                    goto yy106;
                } else {
                    if (yych <= '`') goto yy74;
                    if (yych <= 'z') goto yy106;
                    goto yy74;
                }
            }
yy105:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
yy106:
            if (yych <= 'Z') {
                if (yych <= '9') {
                    if (yych >= '0') goto yy105;
                } else {
                    if (yych <= '@') goto yy107;
                    if (yych <= 'F') goto yy105;
                    goto yy72;
                }
            } else {
                if (yych <= '`') {
                    if (yych == '_') goto yy72;
                } else {
                    if (yych <= 'f') goto yy105;
                    if (yych <= 'z') goto yy72;
                }
            }
yy107:
            {
                token = TOK_HEX_NUMBER;
                goto done;
            }
yy108:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 0x00) goto yy36;
            if (yych == '*') goto yy114;
            goto yy108;
yy110:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 0x00) goto yy36;
            if (yych != '\n') goto yy110;
            ++YYCURSOR;
            {
                continue; 
            }
yy114:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych == '*') goto yy117;
            if (yych == '/') goto yy119;
            goto yy116;
yy115:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
yy116:
            if (yych <= 0x00) goto yy36;
            if (yych == '*') goto yy122;
            goto yy115;
yy117:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '*') {
                if (yych <= 0x00) goto yy36;
                if (yych <= ')') goto yy115;
                goto yy117;
            } else {
                if (yych == '/') goto yy121;
                goto yy115;
            }
yy119:
            ++YYCURSOR;
yy120:
            {
                continue; 
            }
yy121:
            yyaccept = 4;
            ++YYCURSOR;
            YYMARKER = YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= 0x00) goto yy120;
            if (yych != '*') goto yy115;
yy122:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '*') {
                if (yych <= 0x00) goto yy36;
                if (yych <= ')') goto yy115;
            } else {
                if (yych == '/') goto yy119;
                goto yy115;
            }
yy123:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
            if (yych <= '*') {
                if (yych <= 0x00) goto yy36;
                if (yych <= ')') goto yy115;
                goto yy123;
            } else {
                if (yych == '/') goto yy121;
                goto yy115;
            }
yy125:
            ++YYCURSOR;
            yych = YYREADINPUT(YYCURSOR);
yy126:
            if (yych <= '\f') {
                if (yych <= 0x08) goto yy3;
                if (yych <= '\n') goto yy125;
                goto yy3;
            } else {
                if (yych <= '\r') goto yy125;
                if (yych == ' ') goto yy125;
                goto yy3;
            }
        }

    }

done:
    context->token = token;
    context->start = s;
    context->next  = c;

#undef YYREADINPUT
#undef YYCTYPE           
#undef YYCURSOR          
#undef YYMARKER          
}

static int parse_value_list (mjson_parser_t *context);
static int parse_key_value_pair(mjson_parser_t *context, int stop_token);

int mjson_parse(const char *json_data, size_t json_data_size, void* bjson_data, size_t bjson_data_size)
{
    mjson_parser_t c = {
        TOK_NONE, 0,
        json_data, json_data + json_data_size,
        (uint8_t*)bjson_data, (uint8_t*)bjson_data + bjson_data_size
    };
    int stop_token = TOK_NONE;

    mjson_next_token(&c);
    
    if (c.token == TOK_LEFT_BRACKET)
    {
        mjson_next_token(&c);
        if (!parse_value_list(&c))
            return 0;
    }
    else
    {
        if (c.token == TOK_LEFT_CURVE_BRACKET)
        {
            stop_token = TOK_RIGHT_CURVE_BRACKET;
            mjson_next_token(&c);
        }

        if (!parse_key_value_pair(&c, stop_token))
            return 0;
    }

    if (c.token != TOK_NONE)
        return 0;

    return 1;
}

static int parse_number(mjson_parser_t *context)
{
    int              num_parsed;
    uint8_t          bjson_id;
    const char*      format;
    bjson_entry32_t* bdata;

    switch(context->token)
    {
        case TOK_OCT_NUMBER:
            bjson_id = BJSON_ID_SINT32;
            format   = "%o";
            break;
        case TOK_HEX_NUMBER:
            bjson_id = BJSON_ID_SINT32;
            format   = "%x";
            break;
        case TOK_DEC_NUMBER:
            bjson_id = BJSON_ID_SINT32;
            format   = "%d";
            break;
        case TOK_FLOAT_NUMBER:
            bjson_id = BJSON_ID_FLOAT32;
            format   = "%f";
            break;
        default:
            assert(!"unknown token");
    }

    if (context->bjson_limit - context->bjson < sizeof(bjson_entry32_t)) return 0;
    
    bdata           = (bjson_entry32_t*)context->bjson;
    bdata->id       = bjson_id;
    context->bjson += sizeof(bjson_entry32_t);

    num_parsed = sscanf(context->start, format, &bdata->val_u32);
    assert(num_parsed == 1);

    mjson_next_token(context);
    return 1;
}

static int parse_identifier(mjson_parser_t *context)
{
    bjson_entry32_t* bdata;
    size_t           str_len;

    str_len = context->next - context->start;

    if (context->bjson_limit - context->bjson < sizeof(uint8_t) + str_len) return 0;
    
    bdata          = (bjson_entry32_t*)context->bjson;
    bdata->id      = BJSON_ID_UTF8_STRING32;
    bdata->val_u32 = str_len;

    context->bjson += sizeof(bjson_entry32_t);

    memcpy(context->bjson, context->start, str_len);
    context->bjson += str_len;

    mjson_next_token(context);
    return 1;
}

static int parse_string(mjson_parser_t *context)
{
    bjson_entry32_t* bdata;
    size_t           str_len;

    str_len = context->next - context->start - 2;

    if (context->bjson_limit - context->bjson < sizeof(uint8_t) + str_len) return 0;
    
    bdata          = (bjson_entry32_t*)context->bjson;
    bdata->id      = BJSON_ID_UTF8_STRING32;
    bdata->val_u32 = str_len;

    context->bjson += sizeof(bjson_entry32_t);

    memcpy(context->bjson, context->start + 1, str_len);
    context->bjson += str_len;

    mjson_next_token(context);
    return 1;
}

static int parse_escaped_string(mjson_parser_t *context)
{
    assert(!"implemented");
    mjson_next_token(context);
    return 1;
}

static int parse_value(mjson_parser_t *context)
{
    assert(context);
 
    switch (context->token)
    {
        case TOK_NULL:
            if (context->bjson_limit - context->bjson < sizeof(uint8_t)) return 0;
            *(uint8_t*)context->bjson = BJSON_ID_NULL;
            context->bjson += sizeof(uint8_t);
            mjson_next_token(context);
            break;
        case TOK_FALSE:
            if (context->bjson_limit - context->bjson < sizeof(uint8_t)) return 0;
            *(uint8_t*)context->bjson = BJSON_ID_FALSE;
            context->bjson += sizeof(uint8_t);
            mjson_next_token(context);
            break;
        case TOK_TRUE:
            if (context->bjson_limit - context->bjson < sizeof(uint8_t)) return 0;
            context->bjson += sizeof(uint8_t);
            *(uint8_t*)context->bjson = BJSON_ID_TRUE;
            mjson_next_token(context);
            break;
        case TOK_OCT_NUMBER:
        case TOK_HEX_NUMBER:
        case TOK_DEC_NUMBER:
        case TOK_FLOAT_NUMBER:
            if (!parse_number(context))
                return 0;
            break;
        case TOK_NOESC_STRING:
            if (!parse_string(context))
                return 0;
            break;
        case TOK_STRING:
            if (!parse_escaped_string(context))
                return 0;
            break;
        case TOK_LEFT_CURVE_BRACKET:
            mjson_next_token(context);
            if (!parse_key_value_pair(context, TOK_RIGHT_CURVE_BRACKET))
                return 0;
            break;
        case TOK_LEFT_BRACKET:
            mjson_next_token(context);
            if (!parse_value_list(context))
                return 0;
            break;
        default:
            return 0;
    }

    return 1;
}

static int parse_value_list(mjson_parser_t *context)
{
    bjson_entry32_t* array;
    uint8_t*         data_start;
    int              expect_separator;

    assert(context);

    if (context->bjson_limit - context->bjson < sizeof(bjson_entry32_t)) return 0;

    array     = (bjson_entry32_t*)context->bjson;
    array->id = BJSON_ID_ARRAY32;

    context->bjson += sizeof(bjson_entry32_t);
    data_start      = context->bjson;

    expect_separator = FALSE;

    while (context->token != TOK_RIGHT_BRACKET)
    {
        if (expect_separator && context->token == TOK_COMMA)
            mjson_next_token(context);
        else
            expect_separator = TRUE;

        if (!parse_value(context))
            return 0;
    }

    array->val_u32 = context->bjson - data_start;

    mjson_next_token(context);

    return 1;
}

static int parse_key_value_pair(mjson_parser_t* context, int stop_token)
{
    bjson_entry32_t* dictionary;
    uint8_t*         data_start;
    int              expect_separator;
 
    assert(context);

    if (context->bjson_limit - context->bjson < sizeof(bjson_entry32_t)) return 0;

    dictionary     = (bjson_entry32_t*)context->bjson;
    dictionary->id = BJSON_ID_DICT32;

    context->bjson += sizeof(bjson_entry32_t);
    data_start      = context->bjson;
    
    expect_separator = FALSE;
    while (context->token != stop_token)
    {
        if (expect_separator && context->token == TOK_COMMA)
            mjson_next_token(context);
        else
            expect_separator = TRUE;

        switch (context->token)
        {
            case TOK_IDENTIFIER:
                if (!parse_identifier(context))
                    return 0;
                break;        
            case TOK_NOESC_STRING:
                if (!parse_string(context))
                    return 0;
                break;        
            default:
                return 0;
        }

        if (context->token != TOK_COLON && context->token != TOK_EQUAL)
            return 0;

        mjson_next_token(context);

        if (!parse_value(context))
            return 0;
    }

    dictionary->val_u32 = context->bjson - data_start;
    
    mjson_next_token(context);

    return 1;
}