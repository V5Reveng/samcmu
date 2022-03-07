#include <stdarg.h>
#include <stdio.h>

#include "api.h"

typedef void (*void_fn_ptr)(void);

struct __attribute__((packed)) ApiTable {
	int (*system_version)(void);
	int (*stdlib_version)(void);
	void_fn_ptr _unknown2;
	void_fn_ptr _unknown3;
	void_fn_ptr _unknown4;
	void_fn_ptr _unknown5;
	void_fn_ptr _unknown6;
	void_fn_ptr _unknown7;
	void_fn_ptr _unknown8;
	void_fn_ptr _unknown9;

	void_fn_ptr _unknown10;
	void_fn_ptr _unknown11;
	void_fn_ptr _unknown12;
	void_fn_ptr _unknown13;
	void_fn_ptr _unknown14;
	void_fn_ptr _unknown15;
	void_fn_ptr _unknown16;
	void_fn_ptr _unknown17;
	void_fn_ptr _unknown18;
	void_fn_ptr _unknown19;

	void_fn_ptr _unknown20;
	void_fn_ptr _unknown21;
	void_fn_ptr _unknown22;
	void_fn_ptr _unknown23;
	void_fn_ptr _unknown24;
	void_fn_ptr _unknown25;
	void_fn_ptr _unknown26;
	void_fn_ptr _unknown27;
	void_fn_ptr _unknown28;
	void_fn_ptr _unknown29;

	void_fn_ptr _unknown30;
	void_fn_ptr _unknown31;
	void_fn_ptr _unknown32;
	void_fn_ptr _unknown33;
	void_fn_ptr _unknown34;
	void_fn_ptr _unknown35;
	void_fn_ptr _unknown36;
	void_fn_ptr _unknown37;
	void_fn_ptr _unknown38;
	void_fn_ptr _unknown39;

	void_fn_ptr _unknown40;
	void_fn_ptr _unknown41;
	void_fn_ptr _unknown42;
	void_fn_ptr _unknown43;
	void_fn_ptr _unknown44;
	void_fn_ptr _unknown45;
	void_fn_ptr _unknown46;
	void_fn_ptr _unknown47;
	void_fn_ptr _unknown48;
	void_fn_ptr _unknown49;

	void_fn_ptr _unknown50;
	void_fn_ptr _unknown51;
	void_fn_ptr _unknown52;
	void_fn_ptr _unknown53;
	void_fn_ptr _unknown54;
	void_fn_ptr _unknown55;
	void_fn_ptr _unknown56;
	void_fn_ptr _unknown57;
	void_fn_ptr _unknown58;
	void_fn_ptr _unknown59;

	void_fn_ptr _unknown60;
	void_fn_ptr _unknown61;
	void_fn_ptr _unknown62;
	void_fn_ptr _unknown63;
	void_fn_ptr _unknown64;
	void_fn_ptr _unknown65;
	void_fn_ptr _unknown66;
	void_fn_ptr _unknown67;
	void_fn_ptr _unknown68;
	void_fn_ptr _unknown69;

	int (*get_system_millis)(void);
	void_fn_ptr _unknown71;
	void_fn_ptr _unknown72;
	void_fn_ptr _unknown73;
	void_fn_ptr _unknown74;
	void_fn_ptr _unknown75;
	void (*_exit)(void) __attribute__((noreturn));
	void_fn_ptr _unknown77;
	void_fn_ptr _unknown78;
	void_fn_ptr _unknown79;

	void_fn_ptr _unknown80;
	void_fn_ptr _unknown81;
	void_fn_ptr _unknown82;
	void_fn_ptr _unknown83;
	void_fn_ptr _unknown84;
	void_fn_ptr _unknown85;
	void_fn_ptr _unknown86;
	void_fn_ptr _unknown87;
	void_fn_ptr _unknown88;
	void_fn_ptr _unknown89;

	void_fn_ptr _unknown90;
	void_fn_ptr _unknown91;
	void_fn_ptr _unknown92;
	void_fn_ptr _unknown93;
	void_fn_ptr _unknown94;
	void_fn_ptr _unknown95;
	void_fn_ptr _unknown96;
	void_fn_ptr _unknown97;
	void_fn_ptr _unknown98;
	void_fn_ptr _unknown99;

	void_fn_ptr _unknown100;
	void_fn_ptr _unknown101;
	void_fn_ptr _unknown102;
	void_fn_ptr _unknown103;
	void_fn_ptr _unknown104;
	bool (*controller_get)(enum v5_ControllerId id, enum v5_ControllerButton button);
	bool (*controller_connection_status)(enum v5_ControllerId id);
	void_fn_ptr _unknown107;
	void_fn_ptr _unknown108;
	void_fn_ptr _unknown109;

	void_fn_ptr _unknown110;
	void_fn_ptr _unknown111;
	void_fn_ptr _unknown112;
	void_fn_ptr _unknown113;
	void_fn_ptr _unknown114;
	void_fn_ptr _unknown115;
	void_fn_ptr _unknown116;
	void_fn_ptr _unknown117;
	void_fn_ptr _unknown118;
	void_fn_ptr _unknown119;

	void_fn_ptr _unknown120;
	void_fn_ptr _unknown121;
	void_fn_ptr _unknown122;
	void_fn_ptr _unknown123;
	void_fn_ptr _unknown124;
	void_fn_ptr _unknown125;
	void_fn_ptr _unknown126;
	void_fn_ptr _unknown127;
	void_fn_ptr _unknown128;
	void_fn_ptr _unknown129;

	void_fn_ptr _unknown130;
	void_fn_ptr _unknown131;
	void_fn_ptr _unknown132;
	void_fn_ptr _unknown133;
	void_fn_ptr _unknown134;
	void_fn_ptr _unknown135;
	void_fn_ptr _unknown136;
	void_fn_ptr _unknown137;
	void_fn_ptr _unknown138;
	void_fn_ptr _unknown139;

	void_fn_ptr _unknown140;
	void_fn_ptr _unknown141;
	void_fn_ptr _unknown142;
	void_fn_ptr _unknown143;
	void_fn_ptr _unknown144;
	void_fn_ptr _unknown145;
	void_fn_ptr _unknown146;
	void_fn_ptr _unknown147;
	void_fn_ptr _unknown148;
	void_fn_ptr _unknown149;

	void_fn_ptr _unknown150;
	void_fn_ptr _unknown151;
	void_fn_ptr _unknown152;
	void_fn_ptr _unknown153;
	void_fn_ptr _unknown154;
	void_fn_ptr _unknown155;
	void_fn_ptr _unknown156;
	void_fn_ptr _unknown157;
	void_fn_ptr _unknown158;
	void_fn_ptr _unknown159;

	void_fn_ptr _unknown160;
	void_fn_ptr _unknown161;
	void_fn_ptr _unknown162;
	void_fn_ptr _unknown163;
	void_fn_ptr _unknown164;
	void_fn_ptr _unknown165;
	void_fn_ptr _unknown166;
	void_fn_ptr _unknown167;
	void_fn_ptr _unknown168;
	void_fn_ptr _unknown169;

	void_fn_ptr _unknown170;
	void_fn_ptr _unknown171;
	void_fn_ptr _unknown172;
	void_fn_ptr _unknown173;
	void_fn_ptr _unknown174;
	void_fn_ptr _unknown175;
	void_fn_ptr _unknown176;
	void_fn_ptr _unknown177;
	void_fn_ptr _unknown178;
	void_fn_ptr _unknown179;

	void_fn_ptr _unknown180;
	void_fn_ptr _unknown181;
	void_fn_ptr _unknown182;
	void_fn_ptr _unknown183;
	void_fn_ptr _unknown184;
	void_fn_ptr _unknown185;
	void_fn_ptr _unknown186;
	void_fn_ptr _unknown187;
	void_fn_ptr _unknown188;
	void_fn_ptr _unknown189;

	void_fn_ptr _unknown190;
	void_fn_ptr _unknown191;
	void_fn_ptr _unknown192;
	void_fn_ptr _unknown193;
	void_fn_ptr _unknown194;
	void_fn_ptr _unknown195;
	void_fn_ptr _unknown196;
	void_fn_ptr _unknown197;
	void_fn_ptr _unknown198;
	void_fn_ptr _unknown199;

	void_fn_ptr _unknown200;
	void_fn_ptr _unknown201;
	void_fn_ptr _unknown202;
	void_fn_ptr _unknown203;
	void_fn_ptr _unknown204;
	void_fn_ptr _unknown205;
	void_fn_ptr _unknown206;
	void_fn_ptr _unknown207;
	void_fn_ptr _unknown208;
	void_fn_ptr _unknown209;

	void_fn_ptr _unknown210;
	void_fn_ptr _unknown211;
	void_fn_ptr _unknown212;
	void_fn_ptr _unknown213;
	void_fn_ptr _unknown214;
	void_fn_ptr _unknown215;
	void_fn_ptr _unknown216;
	void_fn_ptr _unknown217;
	void_fn_ptr _unknown218;
	void_fn_ptr _unknown219;

	void_fn_ptr _unknown220;
	void_fn_ptr _unknown221;
	void_fn_ptr _unknown222;
	void_fn_ptr _unknown223;
	void_fn_ptr _unknown224;
	void_fn_ptr _unknown225;
	void_fn_ptr _unknown226;
	void_fn_ptr _unknown227;
	void_fn_ptr _unknown228;
	void_fn_ptr _unknown229;

	void_fn_ptr _unknown230;
	void_fn_ptr _unknown231;
	void_fn_ptr _unknown232;
	void_fn_ptr _unknown233;
	void_fn_ptr _unknown234;
	void_fn_ptr _unknown235;
	void_fn_ptr _unknown236;
	void_fn_ptr _unknown237;
	void_fn_ptr _unknown238;
	void_fn_ptr _unknown239;

	void_fn_ptr _unknown240;
	void_fn_ptr _unknown241;
	void_fn_ptr _unknown242;
	void_fn_ptr _unknown243;
	void_fn_ptr _unknown244;
	void_fn_ptr _unknown245;
	void_fn_ptr _unknown246;
	void_fn_ptr _unknown247;
	void_fn_ptr _unknown248;
	void_fn_ptr _unknown249;

	void_fn_ptr _unknown250;
	void_fn_ptr _unknown251;
	void_fn_ptr _unknown252;
	void_fn_ptr _unknown253;
	void_fn_ptr _unknown254;
	void_fn_ptr _unknown255;
	void_fn_ptr _unknown256;
	void_fn_ptr _unknown257;
	void_fn_ptr _unknown258;
	void_fn_ptr _unknown259;

	void_fn_ptr _unknown260;
	void_fn_ptr _unknown261;
	void_fn_ptr _unknown262;
	void_fn_ptr _unknown263;
	void_fn_ptr _unknown264;
	void_fn_ptr _unknown265;
	void_fn_ptr _unknown266;
	void_fn_ptr _unknown267;
	void_fn_ptr _unknown268;
	void_fn_ptr _unknown269;

	void_fn_ptr _unknown270;
	void_fn_ptr _unknown271;
	void_fn_ptr _unknown272;
	void_fn_ptr _unknown273;
	void_fn_ptr _unknown274;
	void_fn_ptr _unknown275;
	void_fn_ptr _unknown276;
	void_fn_ptr _unknown277;
	void_fn_ptr _unknown278;
	void_fn_ptr _unknown279;

	void_fn_ptr _unknown280;
	void_fn_ptr _unknown281;
	void_fn_ptr _unknown282;
	void_fn_ptr _unknown283;
	void_fn_ptr _unknown284;
	void_fn_ptr _unknown285;
	void_fn_ptr _unknown286;
	void_fn_ptr _unknown287;
	void_fn_ptr _unknown288;
	void_fn_ptr _unknown289;

	void_fn_ptr _unknown290;
	void_fn_ptr _unknown291;
	void_fn_ptr _unknown292;
	void_fn_ptr _unknown293;
	void_fn_ptr _unknown294;
	void_fn_ptr _unknown295;
	void_fn_ptr _unknown296;
	void_fn_ptr _unknown297;
	void_fn_ptr _unknown298;
	void_fn_ptr _unknown299;

	void_fn_ptr _unknown300;
	void_fn_ptr _unknown301;
	void_fn_ptr _unknown302;
	void_fn_ptr _unknown303;
	void_fn_ptr _unknown304;
	void_fn_ptr _unknown305;
	void_fn_ptr _unknown306;
	void_fn_ptr _unknown307;
	void_fn_ptr _unknown308;
	void_fn_ptr _unknown309;

	void_fn_ptr _unknown310;
	void_fn_ptr _unknown311;
	void_fn_ptr _unknown312;
	void_fn_ptr _unknown313;
	void_fn_ptr _unknown314;
	void_fn_ptr _unknown315;
	void_fn_ptr _unknown316;
	void_fn_ptr _unknown317;
	void_fn_ptr _unknown318;
	void_fn_ptr _unknown319;

	void_fn_ptr _unknown320;
	void_fn_ptr _unknown321;
	void_fn_ptr _unknown322;
	void_fn_ptr _unknown323;
	void_fn_ptr _unknown324;
	void_fn_ptr _unknown325;
	void_fn_ptr _unknown326;
	void_fn_ptr _unknown327;
	void_fn_ptr _unknown328;
	void_fn_ptr _unknown329;

	void_fn_ptr _unknown330;
	void_fn_ptr _unknown331;
	void_fn_ptr _unknown332;
	void_fn_ptr _unknown333;
	void_fn_ptr _unknown334;
	void_fn_ptr _unknown335;
	void_fn_ptr _unknown336;
	void_fn_ptr _unknown337;
	void_fn_ptr _unknown338;
	void_fn_ptr _unknown339;

	void_fn_ptr _unknown340;
	void_fn_ptr _unknown341;
	void_fn_ptr _unknown342;
	void_fn_ptr _unknown343;
	void_fn_ptr _unknown344;
	void_fn_ptr _unknown345;
	void_fn_ptr _unknown346;
	void_fn_ptr _unknown347;
	void_fn_ptr _unknown348;
	void_fn_ptr _unknown349;

	void_fn_ptr _unknown350;
	void_fn_ptr _unknown351;
	void_fn_ptr _unknown352;
	void_fn_ptr _unknown353;
	void_fn_ptr _unknown354;
	void_fn_ptr _unknown355;
	void_fn_ptr _unknown356;
	void_fn_ptr _unknown357;
	void_fn_ptr _unknown358;
	void_fn_ptr _unknown359;

	void_fn_ptr _unknown360;
	void_fn_ptr _unknown361;
	void_fn_ptr _unknown362;
	void_fn_ptr _unknown363;
	void_fn_ptr _unknown364;
	void_fn_ptr _unknown365;
	void_fn_ptr _unknown366;
	void_fn_ptr _unknown367;
	void_fn_ptr _unknown368;
	void_fn_ptr _unknown369;

	void_fn_ptr _unknown370;
	void_fn_ptr _unknown371;
	void_fn_ptr _unknown372;
	void_fn_ptr _unknown373;
	void_fn_ptr _unknown374;
	void_fn_ptr _unknown375;
	void_fn_ptr _unknown376;
	void_fn_ptr _unknown377;
	void_fn_ptr _unknown378;
	void_fn_ptr _unknown379;

	void_fn_ptr _unknown380;
	void_fn_ptr _unknown381;
	void_fn_ptr _unknown382;
	void_fn_ptr _unknown383;
	void_fn_ptr _unknown384;
	void_fn_ptr _unknown385;
	void_fn_ptr _unknown386;
	void_fn_ptr _unknown387;
	void_fn_ptr _unknown388;
	void_fn_ptr _unknown389;

	void_fn_ptr _unknown390;
	void_fn_ptr _unknown391;
	void_fn_ptr _unknown392;
	void_fn_ptr _unknown393;
	void_fn_ptr _unknown394;
	void_fn_ptr _unknown395;
	void_fn_ptr _unknown396;
	void_fn_ptr _unknown397;
	void_fn_ptr _unknown398;
	void_fn_ptr _unknown399;

	void_fn_ptr _unknown400;
	void_fn_ptr _unknown401;
	void (*display_erase)(void);
	void_fn_ptr _unknown403;
	void_fn_ptr _unknown404;
	void_fn_ptr _unknown405;
	void_fn_ptr _unknown406;
	void_fn_ptr _unknown407;
	void_fn_ptr _unknown408;
	void_fn_ptr _unknown409;

	void_fn_ptr _unknown410;
	void (*display_rect_clear)(int x0, int y0, int x1, int y1);
	void (*display_rect_fill)(int x0, int y0, int x1, int y1);
	void_fn_ptr _unknown413;
	void_fn_ptr _unknown414;
	void_fn_ptr _unknown415;
	void (*display_printf)(int x, int y, int always_1, char const* fmt, ...) __attribute__((format(printf, 4, 5)));
	void (*display_vprintf)(int line, char const* fmt, va_list args);
	void_fn_ptr _unknown418;
	void_fn_ptr _unknown419;

	void_fn_ptr _unknown420;
	void_fn_ptr _unknown421;
};

extern struct ApiTable __sysapi_func_table_start;

void v5_exit(void) {
	__sysapi_func_table_start._exit();
}

int v5_controller_get(enum v5_ControllerId id, enum v5_ControllerButton button) {
	return __sysapi_func_table_start.controller_get(id, button);
}

int v5_controller_connection_status(enum v5_ControllerId id) {
	return __sysapi_func_table_start.controller_connection_status(id);
}

int v5_get_system_millis(void) {
	return __sysapi_func_table_start.get_system_millis();
}

void v5_display_erase(void) {
	__sysapi_func_table_start.display_erase();
}

void v5_display_rect_clear(int x0, int y0, int x1, int y1) {
	__sysapi_func_table_start.display_rect_clear(x0, y0 + V5_SCREEN_HEADER_HEIGHT, x1, y1 + V5_SCREEN_HEADER_HEIGHT);
}

void v5_display_rect_fill(int x0, int y0, int x1, int y1) {
	__sysapi_func_table_start.display_rect_fill(x0, y0 + V5_SCREEN_HEADER_HEIGHT, x1, y1 + V5_SCREEN_HEADER_HEIGHT);
}

void v5_display_printf(int line, char const* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	__sysapi_func_table_start.display_vprintf(line, fmt, args);
	va_end(args);
}

void v5_display_print_slice(int line, char const* base, unsigned int len) {
	// The V5 printf function does not support %.* (dynamic precision), so we have to generate the format string. Not too difficult.
	char buf[20] = "%.";
	int const amount = snprintf(buf + 2, 15, "%u", len);
	buf[amount + 2] = 's';
	buf[amount + 3] = '\0';
	v5_display_printf(line, buf, base);
}

int v5_system_version(void) {
	return __sysapi_func_table_start.system_version();
}

int v5_stdlib_version(void) {
	return __sysapi_func_table_start.stdlib_version();
}
