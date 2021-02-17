/*
 * @Descripttion: 设计模式第26章 -> 享元模式
 *                享元模式实际上把一个类的成员进行了区分，分为了内部状态和外部状态两种。
 *
 *                比如下棋的类：
 *                方案一：
 * 
 *                    一个棋子类可以定义为(颜色、X位置、Y位置)三个属性
 * 
 *                方案二：
 * 
 *                    也可以定义为(颜色)一个属性，而把X位置、Y位置独立到棋子的类外去。
 *
 *
 *                对于一个棋盘，需要包含多个棋子，对于方案一，包含多个棋子有了很多重复的信息(颜色)，
 *                对于方案二，只用生成两颗棋子，X位置、Y位置独立到棋子的类外去，因此共享了重复的内部状态，节省了内存。
 *                当一个对象的          内部状态/外部状态       的大小比例大时，享元模式节约的内存更多。
 * 
 * @version: 0.1
 * @Author: CWSY
 * @Date: 2021-02-17 19:55:19
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-02-17 20:09:59
 */

#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

//棋子颜色
enum PieceColor
{ 
    BLACK = 0, 
    WHITE = 1
};

//棋子位置
struct PiecePos
{
	int x;
	int y;
	PiecePos(int a, int b) : x(a), y(b) {}
};

//棋子定义
class Piece
{
    protected:
        PieceColor m_color; //颜色
    public:
        Piece(PieceColor color) : m_color(color) {}
        ~Piece() {}
        virtual void Draw() {}
};

class BlackPiece : public Piece
{
    public:
        BlackPiece(PieceColor color) : Piece(color) {}
        ~BlackPiece() {}
        void Draw() { cout << "绘制一颗黑棋\n"; }
};
class WhitePiece : public Piece
{
    public:
        WhitePiece(PieceColor color) : Piece(color) {}
        ~WhitePiece() {}
        void Draw() { cout << "绘制一颗白棋\n"; }
};
 

class PieceBoard    
{
    private:
        vector<PiecePos> m_vecPos; //存放棋子的位置
        Piece* m_blackPiece;       //黑棋棋子 
        Piece* m_whitePiece;       //白棋棋子
        string m_blackName;
        string m_whiteName;
    public:
        PieceBoard(string black, string white) : m_blackName(black), m_whiteName(white)
        {
            m_blackPiece = NULL;
            m_whitePiece = NULL;
        }
        ~PieceBoard() { delete m_blackPiece; delete m_whitePiece; }
        void SetPiece(PieceColor color, PiecePos pos)
        {
            if (color == BLACK)
            {
                if (m_blackPiece == NULL)  //只有一颗黑棋
                    m_blackPiece = new BlackPiece(color);
                cout << m_blackName << "在位置(" << pos.x << ',' << pos.y << ")";
                m_blackPiece->Draw();
            }
            else
            {
                if (m_whitePiece == NULL)
                    m_whitePiece = new WhitePiece(color);
                cout << m_whiteName << "在位置(" << pos.x << ',' << pos.y << ")";
                m_whitePiece->Draw();
            }
            m_vecPos.push_back(pos);
        }
};


