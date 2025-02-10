class oleddraw
{
private:
    int cursorflash();
public:
    oleddraw(int sda, int scl);
    ~oleddraw();
    int uibackground();
    int showimagefromdb(unsigned int curimg);
    int deletestuf();
    int show();
    int confirm();
    int up();
    int down();
};