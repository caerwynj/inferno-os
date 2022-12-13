extern unsigned char root13code[];
extern int root13len;
extern unsigned char root14code[];
extern int root14len;
extern unsigned char root16code[];
extern int root16len;
extern unsigned char root17code[];
extern int root17len;
extern unsigned char root18code[];
extern int root18len;
extern unsigned char root19code[];
extern int root19len;
extern unsigned char root20code[];
extern int root20len;
extern unsigned char root21code[];
extern int root21len;
extern unsigned char root22code[];
extern int root22len;
extern unsigned char root23code[];
extern int root23len;
extern unsigned char root24code[];
extern int root24len;
extern unsigned char root25code[];
extern int root25len;
int rootmaxq = 26;
Dirtab roottab[26] = {
	"",	{0, 0, QTDIR},	 0,	0555,
	"chan",	{1, 0, QTDIR},	 0,	0555,
	"dev",	{2, 0, QTDIR},	 0,	0555,
	"dis",	{3, 0, QTDIR},	 0,	0555,
	"lib",	{4, 0, QTDIR},	 0,	0555,
	"env",	{5, 0, QTDIR},	 0,	0555,
	"fd",	{6, 0, QTDIR},	 0,	0555,
	"net",	{7, 0, QTDIR},	 0,	0555,
	"prog",	{8, 0, QTDIR},	 0,	0555,
	"n",	{9, 0, QTDIR},	 0,	0555,
	"tmp",	{10, 0, QTDIR},	 0,	0555,
	"osinit.dis",	{11, 0, QTFILE},	 0,	0444,
	"lib",	{12, 0, QTDIR},	 0,	0555,
	"disk",	{13, 0, QTDIR},	 0,	0555,
	"sh.dis",	{14, 0, QTFILE},	 0,	0444,
	"tiny",	{15, 0, QTDIR},	 0,	0555,
	"ls.dis",	{16, 0, QTFILE},	 0,	0444,
	"ps.dis",	{17, 0, QTFILE},	 0,	0444,
	"ns.dis",	{18, 0, QTFILE},	 0,	0444,
	"cat.dis",	{19, 0, QTFILE},	 0,	0444,
	"bind.dis",	{20, 0, QTFILE},	 0,	0444,
	"mount.dis",	{21, 0, QTFILE},	 0,	0444,
	"pwd.dis",	{22, 0, QTFILE},	 0,	0444,
	"echo.dis",	{23, 0, QTFILE},	 0,	0444,
	"cd.dis",	{24, 0, QTFILE},	 0,	0444,
	"sh.dis",	{25, 0, QTFILE},	 0,	0444,
};
Rootdata rootdata[26] = {
	0,	 &roottab[1],	 11,	nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 &roottab[12],	 13,	nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 root13code,	 0,	 &root13len,
	3,	 nil,	 0,	 nil,
	3,	 nil,	 0,	 nil,
	3,	 root14code,	 0,	 &root14len,
	3,	 &roottab[25],	 1,	nil,
	3,	 root17code,	 0,	 &root17len,
	3,	 root18code,	 0,	 &root18len,
	3,	 root19code,	 0,	 &root19len,
	3,	 root20code,	 0,	 &root20len,
	3,	 root21code,	 0,	 &root21len,
	3,	 root22code,	 0,	 &root22len,
	3,	 root23code,	 0,	 &root23len,
	3,	 root24code,	 0,	 &root24len,
	3,	 root25code,	 0,	 &root25len,
	15,	 root16code,	 0,	 &root16len,
};
