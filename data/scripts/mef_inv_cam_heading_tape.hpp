

//heading tape
class MEF_INV_CAM_HEADING_TAPE
{
	idd = IDD_INV_CAM_HEADING_TAPE;
	
	duration = 999999;   //how long the resource stays on the screen
	enableSimulation = true;
	movingEnable = true;

	onLoad = "MEF_INV_CAM_HUD = (_this select 0)";

	//generic text
	class INV_CAM_LABEL : RscText
	{
		
		idc = IDC_GENERIC;
		type = CT_STATIC;
		style = ST_CENTER;			
		x = .1;
		y = .1;
		w = MEF_INV_CAM_W;
		h = MEF_INV_CAM_H;
		
		colorBackground[] = {0, 0, 0, 0};
		colorText[] = MEF_COLOR_WHITE;
		font = MEF_INV_CAM_MAIN_FONT;
		SizeEx = MEF_INV_CAM_FONT_SIZE;	
		text = "";	
	};
	
	//Line
	class INV_CAM_LINE : RscText
	{
		idc = IDC_GENERIC;
		type = CT_STATIC;
		style = ST_LINE;
		x = 0.1;
		y = 0.1;
		w = 0.0;
		h = 0.01;
		colorText[] = MEF_COLOR_WHITE;
		colorBackground[] = {0, 0, 0, 0};
	};
	
	class Controls
	{
		//tape settings
		class TAPE_SETTINGS : INV_CAM_LABEL
		{
			idc = IDC_TAPE_SETTINGS;
			x=0.44;
			y=0.85;
			w=0.114;
			h=0.05;

			colorText[] = MEF_COLOR_WHITE;
			colorBackground[] = {0, 0, 0, 1};
			sizeEx=0.035;
			text = "Mils Grid";
		};	
	
		//grid
		class CENTER_LINE : INV_CAM_LINE
		{
			idc = IDC_CENTER_LINE;
			x = 0.5;
			y = 0.0;
			h = 1.0;
			colorText[] = MEF_COLOR_RED;
		};
		class GRID_10001 : CENTER_LINE
		{
			idc = IDC_GRID_10001;
			x = -0.75;
			colorText[] = MEF_COLOR_WHITE;
		};
		class GRID_10002 : GRID_10001
		{
			idc = IDC_GRID_10002;
			x = -0.5;
			colorText[] = MEF_COLOR_WHITE;
		};
		class GRID_10003 : GRID_10001
		{
			idc = IDC_GRID_10003;
			x = -0.25;
		};
		class GRID_10004 : GRID_10001
		{
			idc = IDC_GRID_10004;
			x = 0;
		};
		class GRID_10005 : GRID_10001
		{
			idc = IDC_GRID_10005;
			x = 0.25;
		};
		class GRID_10006 : GRID_10001
		{
			idc = IDC_GRID_10006;
			x = 0.75;
		};
		class GRID_10007 : GRID_10001
		{
			idc = IDC_GRID_10007;
			x = 1.0;
		};
		class GRID_10008 : GRID_10001
		{
			idc = IDC_GRID_10008;
			x = 1.25;
		};
		class GRID_10009 : GRID_10001
		{
			idc = IDC_GRID_10009;
			x = 1.5;
		};
		class GRID_10010 : GRID_10001
		{
			idc = IDC_GRID_10010;
			x = 1.75;
		};		
		
		/*
		class GRID_10008 : GRID_10002 {idc = IDC_GRID_10008;};
		class GRID_10009 : GRID_10002 {idc = IDC_GRID_10009;};
		class GRID_10010 : GRID_10002 {idc = IDC_GRID_10010;};
		class GRID_10011 : GRID_10002 {idc = IDC_GRID_10011;};
		class GRID_10012 : GRID_10002 {idc = IDC_GRID_10012;};
		class GRID_10013 : GRID_10002 {idc = IDC_GRID_10013;};
		class GRID_10014 : GRID_10002 {idc = IDC_GRID_10014;};
		class GRID_10015 : GRID_10002 {idc = IDC_GRID_10015;};
		class GRID_10016 : GRID_10002 {idc = IDC_GRID_10016;};
		class GRID_10017 : GRID_10002 {idc = IDC_GRID_10017;};
		class GRID_10018 : GRID_10002 {idc = IDC_GRID_10018;};
		class GRID_10019 : GRID_10002 {idc = IDC_GRID_10019;};
		class GRID_10020 : GRID_10002 {idc = IDC_GRID_10020;};
		class GRID_10021 : GRID_10002 {idc = IDC_GRID_10021;};
		class GRID_10022 : GRID_10002 {idc = IDC_GRID_10022;};
		*/
		
		//numbers
		class NUMBER_11000 : INV_CAM_LABEL
		{
			idc = IDC_NUMBER_11000;
			x=0.458;
			y=0.893;
			w=0.085;
			h=0.05;
			sizeEx=0.035;
			text = "";
		};
		class NUMBER_11005 : NUMBER_11000 {idc = IDC_NUMBER_11005;};
		class NUMBER_11010 : NUMBER_11000 {idc = IDC_NUMBER_11010;};
		class NUMBER_11015 : NUMBER_11000 {idc = IDC_NUMBER_11015;};
		class NUMBER_11020 : NUMBER_11000 {idc = IDC_NUMBER_11020;};
		class NUMBER_11025 : NUMBER_11000 {idc = IDC_NUMBER_11025;};
		class NUMBER_11030 : NUMBER_11000 {idc = IDC_NUMBER_11030;};
		class NUMBER_11035 : NUMBER_11000 {idc = IDC_NUMBER_11035;};
		class NUMBER_11040 : NUMBER_11000 {idc = IDC_NUMBER_11040;};
		class NUMBER_11045 : NUMBER_11000 {idc = IDC_NUMBER_11045;};
		class NUMBER_11050 : NUMBER_11000 {idc = IDC_NUMBER_11050;};
		class NUMBER_11055 : NUMBER_11000 {idc = IDC_NUMBER_11055;};
		class NUMBER_11060 : NUMBER_11000 {idc = IDC_NUMBER_11060;};
		class NUMBER_11065 : NUMBER_11000 {idc = IDC_NUMBER_11065;};
		class NUMBER_11070 : NUMBER_11000 {idc = IDC_NUMBER_11070;};
		class NUMBER_11075 : NUMBER_11000 {idc = IDC_NUMBER_11075;};
		class NUMBER_11080 : NUMBER_11000 {idc = IDC_NUMBER_11080;};
		class NUMBER_11085 : NUMBER_11000 {idc = IDC_NUMBER_11085;};
		class NUMBER_11090 : NUMBER_11000 {idc = IDC_NUMBER_11090;};
		class NUMBER_11095 : NUMBER_11000 {idc = IDC_NUMBER_11095;};
		class NUMBER_11100 : NUMBER_11000 {idc = IDC_NUMBER_11100;};
		class NUMBER_11105 : NUMBER_11000 {idc = IDC_NUMBER_11105;};
		class NUMBER_11110 : NUMBER_11000 {idc = IDC_NUMBER_11110;};
		class NUMBER_11115 : NUMBER_11000 {idc = IDC_NUMBER_11115;};
		class NUMBER_11120 : NUMBER_11000 {idc = IDC_NUMBER_11120;};
		class NUMBER_11125 : NUMBER_11000 {idc = IDC_NUMBER_11125;};
		class NUMBER_11130 : NUMBER_11000 {idc = IDC_NUMBER_11130;};
		class NUMBER_11135 : NUMBER_11000 {idc = IDC_NUMBER_11135;};
		class NUMBER_11140 : NUMBER_11000 {idc = IDC_NUMBER_11140;};
		class NUMBER_11145 : NUMBER_11000 {idc = IDC_NUMBER_11145;};
		class NUMBER_11150 : NUMBER_11000 {idc = IDC_NUMBER_11150;};
		class NUMBER_11155 : NUMBER_11000 {idc = IDC_NUMBER_11155;};
		class NUMBER_11160 : NUMBER_11000 {idc = IDC_NUMBER_11160;};
		class NUMBER_11165 : NUMBER_11000 {idc = IDC_NUMBER_11165;};
		class NUMBER_11170 : NUMBER_11000 {idc = IDC_NUMBER_11170;};
		class NUMBER_11175 : NUMBER_11000 {idc = IDC_NUMBER_11175;};
		class NUMBER_11180 : NUMBER_11000 {idc = IDC_NUMBER_11180;};
		class NUMBER_11185 : NUMBER_11000 {idc = IDC_NUMBER_11185;};
		class NUMBER_11190 : NUMBER_11000 {idc = IDC_NUMBER_11190;};
		class NUMBER_11195 : NUMBER_11000 {idc = IDC_NUMBER_11195;};
		class NUMBER_11200 : NUMBER_11000 {idc = IDC_NUMBER_11200;};
		class NUMBER_11205 : NUMBER_11000 {idc = IDC_NUMBER_11205;};
		class NUMBER_11210 : NUMBER_11000 {idc = IDC_NUMBER_11210;};
		class NUMBER_11215 : NUMBER_11000 {idc = IDC_NUMBER_11215;};
		class NUMBER_11220 : NUMBER_11000 {idc = IDC_NUMBER_11220;};
		class NUMBER_11225 : NUMBER_11000 {idc = IDC_NUMBER_11225;};
		class NUMBER_11230 : NUMBER_11000 {idc = IDC_NUMBER_11230;};
		class NUMBER_11235 : NUMBER_11000 {idc = IDC_NUMBER_11235;};
		class NUMBER_11240 : NUMBER_11000 {idc = IDC_NUMBER_11240;};
		class NUMBER_11245 : NUMBER_11000 {idc = IDC_NUMBER_11245;};
		class NUMBER_11250 : NUMBER_11000 {idc = IDC_NUMBER_11250;};
		class NUMBER_11255 : NUMBER_11000 {idc = IDC_NUMBER_11255;};
		class NUMBER_11260 : NUMBER_11000 {idc = IDC_NUMBER_11260;};
		class NUMBER_11265 : NUMBER_11000 {idc = IDC_NUMBER_11265;};
		class NUMBER_11270 : NUMBER_11000 {idc = IDC_NUMBER_11270;};
		class NUMBER_11275 : NUMBER_11000 {idc = IDC_NUMBER_11275;};
		class NUMBER_11280 : NUMBER_11000 {idc = IDC_NUMBER_11280;};
		class NUMBER_11285 : NUMBER_11000 {idc = IDC_NUMBER_11285;};
		class NUMBER_11290 : NUMBER_11000 {idc = IDC_NUMBER_11290;};
		class NUMBER_11295 : NUMBER_11000 {idc = IDC_NUMBER_11295;};


		//heading tape tic marks
		//major  h=0.035;
		//minor  h=0.025;
		//inc  h=0.015;
		class LINE_12000 : INV_CAM_LINE
		{
			idc = IDC_LINE_12000;
			x=0.5;
			y=0.934;
			h=0.035;
		};
		class LINE_12001 : LINE_12000 {idc = IDC_LINE_12001;};
		class LINE_12002 : LINE_12000 {idc = IDC_LINE_12002;};
		class LINE_12003 : LINE_12000 {idc = IDC_LINE_12003;};
		class LINE_12004 : LINE_12000 {idc = IDC_LINE_12004;};
		class LINE_12005 : LINE_12000 {idc = IDC_LINE_12005;};
		class LINE_12006 : LINE_12000 {idc = IDC_LINE_12006;};
		class LINE_12007 : LINE_12000 {idc = IDC_LINE_12007;};
		class LINE_12008 : LINE_12000 {idc = IDC_LINE_12008;};
		class LINE_12009 : LINE_12000 {idc = IDC_LINE_12009;};
		class LINE_12010 : LINE_12000 {idc = IDC_LINE_12010;};
		class LINE_12011 : LINE_12000 {idc = IDC_LINE_12011;};
		class LINE_12012 : LINE_12000 {idc = IDC_LINE_12012;};
		class LINE_12013 : LINE_12000 {idc = IDC_LINE_12013;};
		class LINE_12014 : LINE_12000 {idc = IDC_LINE_12014;};
		class LINE_12015 : LINE_12000 {idc = IDC_LINE_12015;};
		class LINE_12016 : LINE_12000 {idc = IDC_LINE_12016;};
		class LINE_12017 : LINE_12000 {idc = IDC_LINE_12017;};
		class LINE_12018 : LINE_12000 {idc = IDC_LINE_12018;};
		class LINE_12019 : LINE_12000 {idc = IDC_LINE_12019;};
		class LINE_12020 : LINE_12000 {idc = IDC_LINE_12020;};
		class LINE_12021 : LINE_12000 {idc = IDC_LINE_12021;};
		class LINE_12022 : LINE_12000 {idc = IDC_LINE_12022;};
		class LINE_12023 : LINE_12000 {idc = IDC_LINE_12023;};
		class LINE_12024 : LINE_12000 {idc = IDC_LINE_12024;};
		class LINE_12025 : LINE_12000 {idc = IDC_LINE_12025;};
		class LINE_12026 : LINE_12000 {idc = IDC_LINE_12026;};
		class LINE_12027 : LINE_12000 {idc = IDC_LINE_12027;};
		class LINE_12028 : LINE_12000 {idc = IDC_LINE_12028;};
		class LINE_12029 : LINE_12000 {idc = IDC_LINE_12029;};
		class LINE_12030 : LINE_12000 {idc = IDC_LINE_12030;};
		class LINE_12031 : LINE_12000 {idc = IDC_LINE_12031;};
		class LINE_12032 : LINE_12000 {idc = IDC_LINE_12032;};
		class LINE_12033 : LINE_12000 {idc = IDC_LINE_12033;};
		class LINE_12034 : LINE_12000 {idc = IDC_LINE_12034;};
		class LINE_12035 : LINE_12000 {idc = IDC_LINE_12035;};
		class LINE_12036 : LINE_12000 {idc = IDC_LINE_12036;};
		class LINE_12037 : LINE_12000 {idc = IDC_LINE_12037;};
		class LINE_12038 : LINE_12000 {idc = IDC_LINE_12038;};
		class LINE_12039 : LINE_12000 {idc = IDC_LINE_12039;};
		class LINE_12040 : LINE_12000 {idc = IDC_LINE_12040;};
		class LINE_12041 : LINE_12000 {idc = IDC_LINE_12041;};
		class LINE_12042 : LINE_12000 {idc = IDC_LINE_12042;};
		class LINE_12043 : LINE_12000 {idc = IDC_LINE_12043;};
		class LINE_12044 : LINE_12000 {idc = IDC_LINE_12044;};
		class LINE_12045 : LINE_12000 {idc = IDC_LINE_12045;};
		class LINE_12046 : LINE_12000 {idc = IDC_LINE_12046;};
		class LINE_12047 : LINE_12000 {idc = IDC_LINE_12047;};
		class LINE_12048 : LINE_12000 {idc = IDC_LINE_12048;};
		class LINE_12049 : LINE_12000 {idc = IDC_LINE_12049;};
		class LINE_12050 : LINE_12000 {idc = IDC_LINE_12050;};
		class LINE_12051 : LINE_12000 {idc = IDC_LINE_12051;};
		class LINE_12052 : LINE_12000 {idc = IDC_LINE_12052;};
		class LINE_12053 : LINE_12000 {idc = IDC_LINE_12053;};
		class LINE_12054 : LINE_12000 {idc = IDC_LINE_12054;};
		class LINE_12055 : LINE_12000 {idc = IDC_LINE_12055;};
		class LINE_12056 : LINE_12000 {idc = IDC_LINE_12056;};
		class LINE_12057 : LINE_12000 {idc = IDC_LINE_12057;};
		class LINE_12058 : LINE_12000 {idc = IDC_LINE_12058;};
		class LINE_12059 : LINE_12000 {idc = IDC_LINE_12059;};
		class LINE_12060 : LINE_12000 {idc = IDC_LINE_12060;};
		class LINE_12061 : LINE_12000 {idc = IDC_LINE_12061;};
		class LINE_12062 : LINE_12000 {idc = IDC_LINE_12062;};
		class LINE_12063 : LINE_12000 {idc = IDC_LINE_12063;};
		class LINE_12064 : LINE_12000 {idc = IDC_LINE_12064;};
		class LINE_12065 : LINE_12000 {idc = IDC_LINE_12065;};
		class LINE_12066 : LINE_12000 {idc = IDC_LINE_12066;};
		class LINE_12067 : LINE_12000 {idc = IDC_LINE_12067;};
		class LINE_12068 : LINE_12000 {idc = IDC_LINE_12068;};
		class LINE_12069 : LINE_12000 {idc = IDC_LINE_12069;};
		class LINE_12070 : LINE_12000 {idc = IDC_LINE_12070;};
		class LINE_12071 : LINE_12000 {idc = IDC_LINE_12071;};
		class LINE_12072 : LINE_12000 {idc = IDC_LINE_12072;};
		class LINE_12073 : LINE_12000 {idc = IDC_LINE_12073;};
		class LINE_12074 : LINE_12000 {idc = IDC_LINE_12074;};
		class LINE_12075 : LINE_12000 {idc = IDC_LINE_12075;};
		class LINE_12076 : LINE_12000 {idc = IDC_LINE_12076;};
		class LINE_12077 : LINE_12000 {idc = IDC_LINE_12077;};
		class LINE_12078 : LINE_12000 {idc = IDC_LINE_12078;};
		class LINE_12079 : LINE_12000 {idc = IDC_LINE_12079;};
		class LINE_12080 : LINE_12000 {idc = IDC_LINE_12080;};
		class LINE_12081 : LINE_12000 {idc = IDC_LINE_12081;};
		class LINE_12082 : LINE_12000 {idc = IDC_LINE_12082;};
		class LINE_12083 : LINE_12000 {idc = IDC_LINE_12083;};
		class LINE_12084 : LINE_12000 {idc = IDC_LINE_12084;};
		class LINE_12085 : LINE_12000 {idc = IDC_LINE_12085;};
		class LINE_12086 : LINE_12000 {idc = IDC_LINE_12086;};
		class LINE_12087 : LINE_12000 {idc = IDC_LINE_12087;};
		class LINE_12088 : LINE_12000 {idc = IDC_LINE_12088;};
		class LINE_12089 : LINE_12000 {idc = IDC_LINE_12089;};
		class LINE_12090 : LINE_12000 {idc = IDC_LINE_12090;};
		class LINE_12091 : LINE_12000 {idc = IDC_LINE_12091;};
		class LINE_12092 : LINE_12000 {idc = IDC_LINE_12092;};
		class LINE_12093 : LINE_12000 {idc = IDC_LINE_12093;};
		class LINE_12094 : LINE_12000 {idc = IDC_LINE_12094;};
		class LINE_12095 : LINE_12000 {idc = IDC_LINE_12095;};
		class LINE_12096 : LINE_12000 {idc = IDC_LINE_12096;};
		class LINE_12097 : LINE_12000 {idc = IDC_LINE_12097;};
		class LINE_12098 : LINE_12000 {idc = IDC_LINE_12098;};
		class LINE_12099 : LINE_12000 {idc = IDC_LINE_12099;};
		class LINE_12100 : LINE_12000 {idc = IDC_LINE_12100;};
		class LINE_12101 : LINE_12000 {idc = IDC_LINE_12101;};
		class LINE_12102 : LINE_12000 {idc = IDC_LINE_12102;};
		class LINE_12103 : LINE_12000 {idc = IDC_LINE_12103;};
		class LINE_12104 : LINE_12000 {idc = IDC_LINE_12104;};
		class LINE_12105 : LINE_12000 {idc = IDC_LINE_12105;};
		class LINE_12106 : LINE_12000 {idc = IDC_LINE_12106;};
		class LINE_12107 : LINE_12000 {idc = IDC_LINE_12107;};
		class LINE_12108 : LINE_12000 {idc = IDC_LINE_12108;};
		class LINE_12109 : LINE_12000 {idc = IDC_LINE_12109;};
		class LINE_12110 : LINE_12000 {idc = IDC_LINE_12110;};
		class LINE_12111 : LINE_12000 {idc = IDC_LINE_12111;};
		class LINE_12112 : LINE_12000 {idc = IDC_LINE_12112;};
		class LINE_12113 : LINE_12000 {idc = IDC_LINE_12113;};
		class LINE_12114 : LINE_12000 {idc = IDC_LINE_12114;};
		class LINE_12115 : LINE_12000 {idc = IDC_LINE_12115;};
		class LINE_12116 : LINE_12000 {idc = IDC_LINE_12116;};
		class LINE_12117 : LINE_12000 {idc = IDC_LINE_12117;};
		class LINE_12118 : LINE_12000 {idc = IDC_LINE_12118;};
		class LINE_12119 : LINE_12000 {idc = IDC_LINE_12119;};
		class LINE_12120 : LINE_12000 {idc = IDC_LINE_12120;};
		class LINE_12121 : LINE_12000 {idc = IDC_LINE_12121;};
		class LINE_12122 : LINE_12000 {idc = IDC_LINE_12122;};
		class LINE_12123 : LINE_12000 {idc = IDC_LINE_12123;};
		class LINE_12124 : LINE_12000 {idc = IDC_LINE_12124;};
		class LINE_12125 : LINE_12000 {idc = IDC_LINE_12125;};
		class LINE_12126 : LINE_12000 {idc = IDC_LINE_12126;};
		class LINE_12127 : LINE_12000 {idc = IDC_LINE_12127;};
		class LINE_12128 : LINE_12000 {idc = IDC_LINE_12128;};
		class LINE_12129 : LINE_12000 {idc = IDC_LINE_12129;};
		class LINE_12130 : LINE_12000 {idc = IDC_LINE_12130;};
		class LINE_12131 : LINE_12000 {idc = IDC_LINE_12131;};
		class LINE_12132 : LINE_12000 {idc = IDC_LINE_12132;};
		class LINE_12133 : LINE_12000 {idc = IDC_LINE_12133;};
		class LINE_12134 : LINE_12000 {idc = IDC_LINE_12134;};
		class LINE_12135 : LINE_12000 {idc = IDC_LINE_12135;};
		class LINE_12136 : LINE_12000 {idc = IDC_LINE_12136;};
		class LINE_12137 : LINE_12000 {idc = IDC_LINE_12137;};
		class LINE_12138 : LINE_12000 {idc = IDC_LINE_12138;};
		class LINE_12139 : LINE_12000 {idc = IDC_LINE_12139;};
		class LINE_12140 : LINE_12000 {idc = IDC_LINE_12140;};
		class LINE_12141 : LINE_12000 {idc = IDC_LINE_12141;};
		class LINE_12142 : LINE_12000 {idc = IDC_LINE_12142;};
		class LINE_12143 : LINE_12000 {idc = IDC_LINE_12143;};
		class LINE_12144 : LINE_12000 {idc = IDC_LINE_12144;};
		class LINE_12145 : LINE_12000 {idc = IDC_LINE_12145;};
		class LINE_12146 : LINE_12000 {idc = IDC_LINE_12146;};
		class LINE_12147 : LINE_12000 {idc = IDC_LINE_12147;};
		class LINE_12148 : LINE_12000 {idc = IDC_LINE_12148;};
		class LINE_12149 : LINE_12000 {idc = IDC_LINE_12149;};
		class LINE_12150 : LINE_12000 {idc = IDC_LINE_12150;};
		class LINE_12151 : LINE_12000 {idc = IDC_LINE_12151;};
		class LINE_12152 : LINE_12000 {idc = IDC_LINE_12152;};
		class LINE_12153 : LINE_12000 {idc = IDC_LINE_12153;};
		class LINE_12154 : LINE_12000 {idc = IDC_LINE_12154;};
		class LINE_12155 : LINE_12000 {idc = IDC_LINE_12155;};
		class LINE_12156 : LINE_12000 {idc = IDC_LINE_12156;};
		class LINE_12157 : LINE_12000 {idc = IDC_LINE_12157;};
		class LINE_12158 : LINE_12000 {idc = IDC_LINE_12158;};
		class LINE_12159 : LINE_12000 {idc = IDC_LINE_12159;};
		class LINE_12160 : LINE_12000 {idc = IDC_LINE_12160;};
		class LINE_12161 : LINE_12000 {idc = IDC_LINE_12161;};
		class LINE_12162 : LINE_12000 {idc = IDC_LINE_12162;};
		class LINE_12163 : LINE_12000 {idc = IDC_LINE_12163;};
		class LINE_12164 : LINE_12000 {idc = IDC_LINE_12164;};
		class LINE_12165 : LINE_12000 {idc = IDC_LINE_12165;};
		class LINE_12166 : LINE_12000 {idc = IDC_LINE_12166;};
		class LINE_12167 : LINE_12000 {idc = IDC_LINE_12167;};
		class LINE_12168 : LINE_12000 {idc = IDC_LINE_12168;};
		class LINE_12169 : LINE_12000 {idc = IDC_LINE_12169;};
		class LINE_12170 : LINE_12000 {idc = IDC_LINE_12170;};
		class LINE_12171 : LINE_12000 {idc = IDC_LINE_12171;};
		class LINE_12172 : LINE_12000 {idc = IDC_LINE_12172;};
		class LINE_12173 : LINE_12000 {idc = IDC_LINE_12173;};
		class LINE_12174 : LINE_12000 {idc = IDC_LINE_12174;};
		class LINE_12175 : LINE_12000 {idc = IDC_LINE_12175;};
		class LINE_12176 : LINE_12000 {idc = IDC_LINE_12176;};
		class LINE_12177 : LINE_12000 {idc = IDC_LINE_12177;};
		class LINE_12178 : LINE_12000 {idc = IDC_LINE_12178;};
		class LINE_12179 : LINE_12000 {idc = IDC_LINE_12179;};
		class LINE_12180 : LINE_12000 {idc = IDC_LINE_12180;};
		class LINE_12181 : LINE_12000 {idc = IDC_LINE_12181;};
		class LINE_12182 : LINE_12000 {idc = IDC_LINE_12182;};
		class LINE_12183 : LINE_12000 {idc = IDC_LINE_12183;};
		class LINE_12184 : LINE_12000 {idc = IDC_LINE_12184;};
		class LINE_12185 : LINE_12000 {idc = IDC_LINE_12185;};
		class LINE_12186 : LINE_12000 {idc = IDC_LINE_12186;};
		class LINE_12187 : LINE_12000 {idc = IDC_LINE_12187;};
		class LINE_12188 : LINE_12000 {idc = IDC_LINE_12188;};
		class LINE_12189 : LINE_12000 {idc = IDC_LINE_12189;};
		class LINE_12190 : LINE_12000 {idc = IDC_LINE_12190;};
		class LINE_12191 : LINE_12000 {idc = IDC_LINE_12191;};
		class LINE_12192 : LINE_12000 {idc = IDC_LINE_12192;};
		class LINE_12193 : LINE_12000 {idc = IDC_LINE_12193;};
		class LINE_12194 : LINE_12000 {idc = IDC_LINE_12194;};
		class LINE_12195 : LINE_12000 {idc = IDC_LINE_12195;};
		class LINE_12196 : LINE_12000 {idc = IDC_LINE_12196;};
		class LINE_12197 : LINE_12000 {idc = IDC_LINE_12197;};
		class LINE_12198 : LINE_12000 {idc = IDC_LINE_12198;};
		class LINE_12199 : LINE_12000 {idc = IDC_LINE_12199;};
		class LINE_12200 : LINE_12000 {idc = IDC_LINE_12200;};
		class LINE_12201 : LINE_12000 {idc = IDC_LINE_12201;};
		class LINE_12202 : LINE_12000 {idc = IDC_LINE_12202;};
		class LINE_12203 : LINE_12000 {idc = IDC_LINE_12203;};
		class LINE_12204 : LINE_12000 {idc = IDC_LINE_12204;};
		class LINE_12205 : LINE_12000 {idc = IDC_LINE_12205;};
		class LINE_12206 : LINE_12000 {idc = IDC_LINE_12206;};
		class LINE_12207 : LINE_12000 {idc = IDC_LINE_12207;};
		class LINE_12208 : LINE_12000 {idc = IDC_LINE_12208;};
		class LINE_12209 : LINE_12000 {idc = IDC_LINE_12209;};
		class LINE_12210 : LINE_12000 {idc = IDC_LINE_12210;};
		class LINE_12211 : LINE_12000 {idc = IDC_LINE_12211;};
		class LINE_12212 : LINE_12000 {idc = IDC_LINE_12212;};
		class LINE_12213 : LINE_12000 {idc = IDC_LINE_12213;};
		class LINE_12214 : LINE_12000 {idc = IDC_LINE_12214;};
		class LINE_12215 : LINE_12000 {idc = IDC_LINE_12215;};
		class LINE_12216 : LINE_12000 {idc = IDC_LINE_12216;};
		class LINE_12217 : LINE_12000 {idc = IDC_LINE_12217;};
		class LINE_12218 : LINE_12000 {idc = IDC_LINE_12218;};
		class LINE_12219 : LINE_12000 {idc = IDC_LINE_12219;};
		class LINE_12220 : LINE_12000 {idc = IDC_LINE_12220;};
		class LINE_12221 : LINE_12000 {idc = IDC_LINE_12221;};
		class LINE_12222 : LINE_12000 {idc = IDC_LINE_12222;};
		class LINE_12223 : LINE_12000 {idc = IDC_LINE_12223;};
		class LINE_12224 : LINE_12000 {idc = IDC_LINE_12224;};
		class LINE_12225 : LINE_12000 {idc = IDC_LINE_12225;};
		class LINE_12226 : LINE_12000 {idc = IDC_LINE_12226;};
		class LINE_12227 : LINE_12000 {idc = IDC_LINE_12227;};
		class LINE_12228 : LINE_12000 {idc = IDC_LINE_12228;};
		class LINE_12229 : LINE_12000 {idc = IDC_LINE_12229;};
		class LINE_12230 : LINE_12000 {idc = IDC_LINE_12230;};
		class LINE_12231 : LINE_12000 {idc = IDC_LINE_12231;};
		class LINE_12232 : LINE_12000 {idc = IDC_LINE_12232;};
		class LINE_12233 : LINE_12000 {idc = IDC_LINE_12233;};
		class LINE_12234 : LINE_12000 {idc = IDC_LINE_12234;};
		class LINE_12235 : LINE_12000 {idc = IDC_LINE_12235;};
		class LINE_12236 : LINE_12000 {idc = IDC_LINE_12236;};
		class LINE_12237 : LINE_12000 {idc = IDC_LINE_12237;};
		class LINE_12238 : LINE_12000 {idc = IDC_LINE_12238;};
		class LINE_12239 : LINE_12000 {idc = IDC_LINE_12239;};
		class LINE_12240 : LINE_12000 {idc = IDC_LINE_12240;};
		class LINE_12241 : LINE_12000 {idc = IDC_LINE_12241;};
		class LINE_12242 : LINE_12000 {idc = IDC_LINE_12242;};
		class LINE_12243 : LINE_12000 {idc = IDC_LINE_12243;};
		class LINE_12244 : LINE_12000 {idc = IDC_LINE_12244;};
		class LINE_12245 : LINE_12000 {idc = IDC_LINE_12245;};
		class LINE_12246 : LINE_12000 {idc = IDC_LINE_12246;};
		class LINE_12247 : LINE_12000 {idc = IDC_LINE_12247;};
		class LINE_12248 : LINE_12000 {idc = IDC_LINE_12248;};
		class LINE_12249 : LINE_12000 {idc = IDC_LINE_12249;};
		class LINE_12250 : LINE_12000 {idc = IDC_LINE_12250;};
		class LINE_12251 : LINE_12000 {idc = IDC_LINE_12251;};
		class LINE_12252 : LINE_12000 {idc = IDC_LINE_12252;};
		class LINE_12253 : LINE_12000 {idc = IDC_LINE_12253;};
		class LINE_12254 : LINE_12000 {idc = IDC_LINE_12254;};
		class LINE_12255 : LINE_12000 {idc = IDC_LINE_12255;};
		class LINE_12256 : LINE_12000 {idc = IDC_LINE_12256;};
		class LINE_12257 : LINE_12000 {idc = IDC_LINE_12257;};
		class LINE_12258 : LINE_12000 {idc = IDC_LINE_12258;};
		class LINE_12259 : LINE_12000 {idc = IDC_LINE_12259;};
		class LINE_12260 : LINE_12000 {idc = IDC_LINE_12260;};
		class LINE_12261 : LINE_12000 {idc = IDC_LINE_12261;};
		class LINE_12262 : LINE_12000 {idc = IDC_LINE_12262;};
		class LINE_12263 : LINE_12000 {idc = IDC_LINE_12263;};
		class LINE_12264 : LINE_12000 {idc = IDC_LINE_12264;};
		class LINE_12265 : LINE_12000 {idc = IDC_LINE_12265;};
		class LINE_12266 : LINE_12000 {idc = IDC_LINE_12266;};
		class LINE_12267 : LINE_12000 {idc = IDC_LINE_12267;};
		class LINE_12268 : LINE_12000 {idc = IDC_LINE_12268;};
		class LINE_12269 : LINE_12000 {idc = IDC_LINE_12269;};
		class LINE_12270 : LINE_12000 {idc = IDC_LINE_12270;};
		class LINE_12271 : LINE_12000 {idc = IDC_LINE_12271;};
		class LINE_12272 : LINE_12000 {idc = IDC_LINE_12272;};
		class LINE_12273 : LINE_12000 {idc = IDC_LINE_12273;};
		class LINE_12274 : LINE_12000 {idc = IDC_LINE_12274;};
		class LINE_12275 : LINE_12000 {idc = IDC_LINE_12275;};
		class LINE_12276 : LINE_12000 {idc = IDC_LINE_12276;};
		class LINE_12277 : LINE_12000 {idc = IDC_LINE_12277;};
		class LINE_12278 : LINE_12000 {idc = IDC_LINE_12278;};
		class LINE_12279 : LINE_12000 {idc = IDC_LINE_12279;};
		class LINE_12280 : LINE_12000 {idc = IDC_LINE_12280;};
		class LINE_12281 : LINE_12000 {idc = IDC_LINE_12281;};
		class LINE_12282 : LINE_12000 {idc = IDC_LINE_12282;};
		class LINE_12283 : LINE_12000 {idc = IDC_LINE_12283;};
		class LINE_12284 : LINE_12000 {idc = IDC_LINE_12284;};
		class LINE_12285 : LINE_12000 {idc = IDC_LINE_12285;};
		class LINE_12286 : LINE_12000 {idc = IDC_LINE_12286;};
		class LINE_12287 : LINE_12000 {idc = IDC_LINE_12287;};
		class LINE_12288 : LINE_12000 {idc = IDC_LINE_12288;};
		class LINE_12289 : LINE_12000 {idc = IDC_LINE_12289;};
		class LINE_12290 : LINE_12000 {idc = IDC_LINE_12290;};
		class LINE_12291 : LINE_12000 {idc = IDC_LINE_12291;};
		class LINE_12292 : LINE_12000 {idc = IDC_LINE_12292;};
		class LINE_12293 : LINE_12000 {idc = IDC_LINE_12293;};
		class LINE_12294 : LINE_12000 {idc = IDC_LINE_12294;};
		class LINE_12295 : LINE_12000 {idc = IDC_LINE_12295;};
		class LINE_12296 : LINE_12000 {idc = IDC_LINE_12296;};
		class LINE_12297 : LINE_12000 {idc = IDC_LINE_12297;};
		class LINE_12298 : LINE_12000 {idc = IDC_LINE_12298;};
		class LINE_12299 : LINE_12000 {idc = IDC_LINE_12299;};
		class LINE_12300 : LINE_12000 {idc = IDC_LINE_12300;};

	};
	
	class controlsBackground
	{
		class BOTTOM_BAR : INV_CAM_LABEL
		{
			idc = IDC_BOTTOM_BAR;
			x=-1.0;
			y=0.9;
			w=3.0;
			h=0.1;
			text = "";
			colorBackground[] = {0, 0, 0, 1};
		};	
	};
};
	

	
	
	
	
	
	
	
	
	
	
	
	