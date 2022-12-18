extern unsigned char root9code[];
extern int root9len;
extern unsigned char root10code[];
extern int root10len;
extern unsigned char root11code[];
extern int root11len;
extern unsigned char root12code[];
extern int root12len;
extern unsigned char root13code[];
extern int root13len;
extern unsigned char root14code[];
extern int root14len;
extern unsigned char root15code[];
extern int root15len;
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
	"env",	{4, 0, QTDIR},	 0,	0555,
	"fd",	{5, 0, QTDIR},	 0,	0555,
	"net",	{6, 0, QTDIR},	 0,	0555,
	"prog",	{7, 0, QTDIR},	 0,	0555,
	"osinit.dis",	{8, 0, QTFILE},	 0,	0444,
	"lib",	{9, 0, QTDIR},	 0,	0555,
	"sh.dis",	{10, 0, QTFILE},	 0,	0444,
	"ls.dis",	{11, 0, QTFILE},	 0,	0444,
	"ps.dis",	{12, 0, QTFILE},	 0,	0444,
	"ns.dis",	{13, 0, QTFILE},	 0,	0444,
	"cat.dis",	{14, 0, QTFILE},	 0,	0444,
	"pwd.dis",	{15, 0, QTFILE},	 0,	0444,
	"echo.dis",	{16, 0, QTFILE},	 0,	0444,
	"cd.dis",	{17, 0, QTFILE},	 0,	0444,
	"bind.dis",	{18, 0, QTFILE},	 0,	0444,
	"mount.dis",	{19, 0, QTFILE},	 0,	0444,
	"readdir.dis",	{20, 0, QTFILE},	 0,	0444,
	"workdir.dis",	{21, 0, QTFILE},	 0,	0444,
	"daytime.dis",	{22, 0, QTFILE},	 0,	0444,
	"bufio.dis",	{23, 0, QTFILE},	 0,	0444,
	"string.dis",	{24, 0, QTFILE},	 0,	0444,
	"arg.dis",	{25, 0, QTFILE},	 0,	0444,
};
Rootdata rootdata[26] = {
	0,	 &roottab[1],	 8,	nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 &roottab[9],	 11,	nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 nil,	 0,	 nil,
	0,	 root9code,	 0,	 &root9len,
	3,	 &roottab[20],	 6,	nil,
	3,	 root10code,	 0,	 &root10len,
	3,	 root11code,	 0,	 &root11len,
	3,	 root12code,	 0,	 &root12len,
	3,	 root13code,	 0,	 &root13len,
	3,	 root14code,	 0,	 &root14len,
	3,	 root15code,	 0,	 &root15len,
	3,	 root16code,	 0,	 &root16len,
	3,	 root17code,	 0,	 &root17len,
	3,	 root18code,	 0,	 &root18len,
	3,	 root19code,	 0,	 &root19len,
	9,	 root20code,	 0,	 &root20len,
	9,	 root21code,	 0,	 &root21len,
	9,	 root22code,	 0,	 &root22len,
	9,	 root23code,	 0,	 &root23len,
	9,	 root24code,	 0,	 &root24len,
	9,	 root25code,	 0,	 &root25len,
};
