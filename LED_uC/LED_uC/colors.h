/*
 * colors.h
 *
 * Created: 28.12.2018 01:08:12
 *  Author: ppisk
 */ 


#ifndef COLORS_H_
#define COLORS_H_

#include <avr/pgmspace.h>


const uint8_t __flash COLORS[256][3] = {
							//  R    G    B
							{   0,   0,   0 }, //  0	Black	(system)
							{ 128,   0,   0 }, //  1	Maroon	(system)
							{   0, 128,   0 }, //  2	Green	(system)
							{ 128, 128,   0 }, //  3	Olive	(system)
							{   0,   0, 128 }, //  4	Navy	(system)
							{ 128,   0, 128 }, //  5	Purple	(system)
							{   0, 128, 128 }, //  6	Teal	(system)
							{ 192, 192, 192 }, //  7	Silver	(system)
							{ 128, 128, 128 }, //  8	Grey	(system)
							{ 255,   0,   0 }, //  9	Red		(system)
							{   0, 255,   0 }, // 10	Lime	(system)
							{ 255, 255,   0 }, // 11	Yellow	(system)
							{   0,   0, 255 }, // 12	Blue	(system)
							{ 255,   0, 255 }, // 13	Fuchsia	(system)
							{   0, 255, 255 }, // 14	Aqua	(system)
							{ 255, 255, 255 }, // 15	White	(system)
							{   0,   0,   0 }, // 16	Grey0
							{   0,   0,  95 }, // 17	NavyBlue
							{   0,   0, 135 }, // 18	DarkBlue
							{   0,   0, 175 }, // 19	Blue3
							{   0,   0, 215 }, // 20	Blue2
							{   0,   0, 255 }, // 21	Blue1
							{   0,  95,   0 }, // 22	DarkGreen
							{   0,  95,  95 }, // 23	DeepSkyBlue4
							{   0,  95, 135 }, // 24	DeepSkyBlue4
							{   0,  95, 175 }, // 25	DeepSkyBlue4
							{   0,  95, 215 }, // 26	DodgerBlue3
							{   0,  95, 255 }, // 27	DodgerBlue2
							{   0, 135,   0 }, // 28	Green4
							{   0, 135,  95 }, // 29	SpringGreen4
							{   0, 135, 135 }, // 30	Turquoise4
							{   0, 135, 175 }, // 31	DeepSkyBlue3
							{   0, 135, 215 }, // 32	DeepSkyBlue3
							{   0, 135, 255 }, // 33	DodgerBlue1
							{   0, 175,   0 }, // 34	Green3
							{   0, 175,  95 }, // 35	SpringGreen3
							{   0, 175, 135 }, // 36	DarkCyan
							{   0, 175, 175 }, // 37	LightSeaGreen
							{   0, 175, 215 }, // 38	DeepSkyBlue2
							{   0, 175, 255 }, // 39	DeepSkyBlue1
							{   0, 215,   0 }, // 40	Green3
							{   0, 215,  95 }, // 41	SpringGreen3
							{   0, 215, 135 }, // 42	SpringGreen2
							{   0, 215, 175 }, // 43	Cyan3
							{   0, 215, 215 }, // 44	DarkTurquoise
							{   0, 215, 255 }, // 45	Turquoise2
							{   0, 255,   0 }, // 46	Green1
							{   0, 255,  95 }, // 47	SpringGreen2
							{   0, 255, 135 }, // 48	SpringGreen1
							{   0, 255, 175 }, // 49	MediumSpringGreen
							{   0, 255, 215 }, // 50	Cyan2
							{   0, 255, 255 }, // 51	Cyan1
							{  95,   0,   0 }, // 52	DarkRed
							{  95,   0,  95 }, // 53	DeepPink4
							{  95,   0, 135 }, // 54	Purple4
							{  95,   0, 175 }, // 55	Purple4
							{  95,   0, 215 }, // 56	Purple3
							{  95,   0, 255 }, // 57	BlueViolet
							{  95,  95,   0 }, // 58	Orange4
							{  95,  95,  95 }, // 59	Grey37
							{  95,  95, 135 }, // 60	MediumPurple4
							{  95,  95, 175 }, // 61	SlateBlue3
							{  95,  95, 215 }, // 62	SlateBlue3
							{  95,  95, 255 }, // 63	RoyalBlue1
							{  95, 135,   0 }, // 64	Chartreuse4
							{  95, 135,  95 }, // 65	DarkSeaGreen4
							{  95, 135, 135 }, // 66	PaleTurquoise4
							{  95, 135, 175 }, // 67	SteelBlue
							{  95, 135, 215 }, // 68	SteelBlue3
							{  95, 135, 255 }, // 69	CornflowerBlue
							{  95, 175,   0 }, // 70	Chartreuse3
							{  95, 175,  95 }, // 71	DarkSeaGreen4
							{  95, 175, 135 }, // 72	CadetBlue
							{  95, 175, 175 }, // 73	CadetBlue
							{  95, 175, 215 }, // 74	SkyBlue3
							{  95, 175, 255 }, // 75	SteelBlue1
							{  95, 215,   0 }, // 76	Chartreuse3
							{  95, 215,  95 }, // 77	PaleGreen3
							{  95, 215, 135 }, // 78	SeaGreen3
							{  95, 215, 175 }, // 79	Aquamarine3
							{  95, 215, 215 }, // 80	MediumTurquoise
							{  95, 215, 255 }, // 81	SteelBlue1
							{  95, 255,   0 }, // 82	Chartreuse2
							{  95, 255,  95 }, // 83	SeaGreen2
							{  95, 255, 135 }, // 84	SeaGreen1
							{  95, 255, 175 }, // 85	SeaGreen1
							{  95, 255, 215 }, // 86	Aquamarine1
							{  95, 255, 255 }, // 87	DarkSlateGray2
							{ 135,   0,   0 }, // 88	DarkRed
							{ 135,   0,  95 }, // 89	DeepPink4
							{ 135,   0, 135 }, // 90	DarkMagenta
							{ 135,   0, 175 }, // 91	DarkMagenta
							{ 135,   0, 215 }, // 92	DarkViolet
							{ 135,   0, 255 }, // 93	Purple
							{ 135,  95,   0 }, // 94	Orange4
							{ 135,  95,  95 }, // 95	LightPink4
							{ 135,  95, 135 }, // 96	Plum4
							{ 135,  95, 175 }, // 97	MediumPurple3
							{ 135,  95, 215 }, // 98	MediumPurple3
							{ 135,  95, 255 }, // 99	SlateBlue1
							{ 135, 135,   0 }, //100	Yellow4
							{ 135, 135,  95 }, //101	Wheat4
							{ 135, 135, 135 }, //102	Grey53
							{ 135, 135, 175 }, //103	LightSlateGrey
							{ 135, 135, 215 }, //104	MediumPurple
							{ 135, 135, 255 }, //105	LightSlateBlue
							{ 135, 175,   0 }, //106	Yellow4
							{ 135, 175,  95 }, //107	DarkOliveGreen3
							{ 135, 175, 135 }, //108	DarkSeaGreen
							{ 135, 175, 175 }, //109	LightSkyBlue3
							{ 135, 175, 215 }, //110	LightSkyBlue3
							{ 135, 175, 255 }, //111	SkyBlue2
							{ 135, 215,   0 }, //112	Chartreuse2
							{ 135, 215,  95 }, //113	DarkOliveGreen3
							{ 135, 215, 135 }, //114	PaleGreen3
							{ 135, 215, 175 }, //115	DarkSeaGreen3
							{ 135, 215, 215 }, //116	DarkSlateGray3
							{ 135, 215, 255 }, //117	SkyBlue1
							{ 135, 255,   0 }, //118	Chartreuse1
							{ 135, 255,  95 }, //119	LightGreen
							{ 135, 255, 135 }, //120	LightGreen
							{ 135, 255, 175 }, //121	PaleGreen1
							{ 135, 255, 215 }, //122	Aquamarine1
							{ 135, 255, 255 }, //123	DarkSlateGray1
							{ 175,   0,   0 }, //124	Red3
							{ 175,   0,  95 }, //125	DeepPink4
							{ 175,   0, 135 }, //126	MediumVioletRed
							{ 175,   0, 175 }, //127	Magenta3
							{ 175,   0, 215 }, //128	DarkViolet
							{ 175,   0, 255 }, //129	Purple
							{ 175,  95,   0 }, //130	DarkOrange3
							{ 175,  95,  95 }, //131	IndianRed
							{ 175,  95, 135 }, //132	HotPink3
							{ 175,  95, 175 }, //133	MediumOrchid3
							{ 175,  95, 215 }, //134	MediumOrchid
							{ 175,  95, 255 }, //135	MediumPurple2
							{ 175, 135,   0 }, //136	DarkGoldenrod
							{ 175, 135,  95 }, //137	LightSalmon3
							{ 175, 135, 135 }, //138	RosyBrown
							{ 175, 135, 175 }, //139	Grey63
							{ 175, 135, 215 }, //140	MediumPurple2
							{ 175, 135, 255 }, //141	MediumPurple1
							{ 175, 175,   0 }, //142	Gold3
							{ 175, 175,  95 }, //143	DarkKhaki
							{ 175, 175, 135 }, //144	NavajoWhite3
							{ 175, 175, 175 }, //145	Grey69
							{ 175, 175, 215 }, //146	LightSteelBlue3
							{ 175, 175, 255 }, //147	LightSteelBlue
							{ 175, 215,   0 }, //148	Yellow3
							{ 175, 215,  95 }, //149	DarkOliveGreen3
							{ 175, 215, 135 }, //150	DarkSeaGreen3
							{ 175, 215, 175 }, //151	DarkSeaGreen2
							{ 175, 215, 215 }, //152	LightCyan3
							{ 175, 215, 255 }, //153	LightSkyBlue1
							{ 175, 255,   0 }, //154	GreenYellow
							{ 175, 255,  95 }, //155	DarkOliveGreen2
							{ 175, 255, 135 }, //156	PaleGreen1
							{ 175, 255, 175 }, //157	DarkSeaGreen2
							{ 175, 255, 215 }, //158	DarkSeaGreen1
							{ 175, 255, 255 }, //159	PaleTurquoise1
							{ 215,   0,   0 }, //160	Red3
							{ 215,   0,  95 }, //161	DeepPink3
							{ 215,   0, 135 }, //162	DeepPink3
							{ 215,   0, 175 }, //163	Magenta3
							{ 215,   0, 215 }, //164	Magenta3
							{ 215,   0, 255 }, //165	Magenta2
							{ 215,  95,   0 }, //166	DarkOrange3
							{ 215,  95,  95 }, //167	IndianRed
							{ 215,  95, 135 }, //168	HotPink3
							{ 215,  95, 175 }, //169	HotPink2
							{ 215,  95, 215 }, //170	Orchid
							{ 215,  95, 255 }, //171	MediumOrchid1
							{ 215, 135,   0 }, //172	Orange3
							{ 215, 135,  95 }, //173	LightSalmon3
							{ 215, 135, 135 }, //174	LightPink3
							{ 215, 135, 175 }, //175	Pink3
							{ 215, 135, 215 }, //176	Plum3
							{ 215, 135, 255 }, //177	Violet
							{ 215, 175,   0 }, //178	Gold3
							{ 215, 175,  95 }, //179	LightGoldenrod3
							{ 215, 175, 135 }, //180	Tan
							{ 215, 175, 175 }, //181	MistyRose3
							{ 215, 175, 215 }, //182	Thistle3
							{ 215, 175, 255 }, //183	Plum2
							{ 215, 215,   0 }, //184	Yellow3
							{ 215, 215,  95 }, //185	Khaki3
							{ 215, 215, 135 }, //186	LightGoldenrod2
							{ 215, 215, 175 }, //187	LightYellow3
							{ 215, 215, 215 }, //188	Grey84
							{ 215, 215, 255 }, //189	LightSteelBlue1
							{ 215, 255,   0 }, //190	Yellow2
							{ 215, 255,  95 }, //191	DarkOliveGreen1
							{ 215, 255, 135 }, //192	DarkOliveGreen1
							{ 215, 255, 175 }, //193	DarkSeaGreen1
							{ 215, 255, 215 }, //194	Honeydew2
							{ 215, 255, 255 }, //195	LightCyan1
							{ 255,   0,   0 }, //196	Red1
							{ 255,   0,  95 }, //197	DeepPink2
							{ 255,   0, 135 }, //198	DeepPink1
							{ 255,   0, 175 }, //199	DeepPink1
							{ 255,   0, 215 }, //200	Magenta2
							{ 255,   0, 255 }, //201	Magenta1
							{ 255,  95,   0 }, //202	OrangeRed1
							{ 255,  95,  95 }, //203	IndianRed1
							{ 255,  95, 135 }, //204	IndianRed1
							{ 255,  95, 175 }, //205	HotPink
							{ 255,  95, 215 }, //206	HotPink
							{ 255,  95, 255 }, //207	MediumOrchid1
							{ 255, 135,   0 }, //208	DarkOrange
							{ 255, 135,  95 }, //209	Salmon1
							{ 255, 135, 135 }, //210	LightCoral
							{ 255, 135, 175 }, //211	PaleVioletRed1
							{ 255, 135, 215 }, //212	Orchid2
							{ 255, 135, 255 }, //213	Orchid1
							{ 255, 175,   0 }, //214	Orange1
							{ 255, 175,  95 }, //215	SandyBrown
							{ 255, 175, 135 }, //216	LightSalmon1
							{ 255, 175, 175 }, //217	LightPink1
							{ 255, 175, 215 }, //218	Pink1
							{ 255, 175, 255 }, //219	Plum1
							{ 255, 215,   0 }, //220	Gold1
							{ 255, 215,  95 }, //221	LightGoldenrod2
							{ 255, 215, 135 }, //222	LightGoldenrod2
							{ 255, 215, 175 }, //223	NavajoWhite1
							{ 255, 215, 215 }, //224	MistyRose1
							{ 255, 215, 255 }, //225	Thistle1
							{ 255, 255,   0 }, //226	Yellow1
							{ 255, 255,  95 }, //227	LightGoldenrod1
							{ 255, 255, 135 }, //228	Khaki1
							{ 255, 255, 175 }, //229	Wheat1
							{ 255, 255, 215 }, //230	Cornsilk1
							{ 255, 255, 255 }, //231	Grey100
							{   8,   8,   8 }, //232	Grey3
							{  18,  18,  18 }, //233	Grey7
							{  28,  28,  28 }, //234	Grey11
							{  38,  38,  38 }, //235	Grey15
							{  48,  48,  48 }, //236	Grey19
							{  58,  58,  58 }, //237	Grey23
							{  68,  68,  68 }, //238	Grey27
							{  78,  78,  78 }, //239	Grey30
							{  88,  88,  88 }, //240	Grey35
							{  98,  98,  98 }, //241	Grey39
							{ 108, 108, 108 }, //242	Grey42
							{ 118, 118, 118 }, //243	Grey46
							{ 128, 128, 128 }, //244	Grey50
							{ 138, 138, 138 }, //245	Grey54
							{ 148, 148, 148 }, //246	Grey58
							{ 158, 158, 158 }, //247	Grey62
							{ 168, 168, 168 }, //248	Grey66
							{ 178, 178, 178 }, //249	Grey70
							{ 188, 188, 188 }, //250	Grey74
							{ 198, 198, 198 }, //251	Grey78
							{ 208, 208, 208 }, //252	Grey82
							{ 218, 218, 218 }, //253	Grey85
							{ 228, 228, 228 }, //254	Grey89
							{ 238, 238, 238 }, //255	Grey93
};

#endif /* COLORS_H_ */