#ifndef POSITION_HPP_INCLUDED
#define POSITION_HPP_INCLUDED

class Position
{
	public:
	
	Position() : m_x(0), m_y(0) {}
	Position(int x, int y) : m_x(x), m_y(y) {}
	Position(float x, float y) : m_x(x), m_y(y) {}
	Position(const Position& p) : m_x(p.m_x), m_y(p.m_y) {}
	
	inline float getX() const { return m_x; }
	inline float getY() const { return m_y; }
	inline int getXint() const { return (int)m_x; }
	inline int getYint() const { return (int)m_y; }
	
	inline void setX(float x) { m_x = x; }
	inline void setX(int x) { m_x = x; }
	inline void setY(float y) { m_y = y; }
	inline void setY(int y) { m_y = y; }
	
	Position& operator=(const Position& p)
	{
		m_x = p.m_x;
		m_y = p.m_y;
		
		return *this;
	}
	
	Position operator+(const Position& p)
	{
		return Position(m_x+p.m_x, m_y+p.m_y);
	}
	
	Position& operator+=(const Position& p)
	{
		m_x += p.m_x;
		m_y += p.m_y;
		
		return *this;
	}
	
	Position operator-(const Position& p)
	{
		return Position(m_x-p.m_x, m_y-p.m_y);
	}
	
	Position operator-=(const Position& p)
	{
		m_x -= p.m_x;
		m_y -= p.m_y;
		
		return *this;
	}
	
	Position operator*(float f)
	{
		return Position(m_x*f, m_y*f);
	}
	
	Position operator*(int f)
	{
		return Position(m_x*f, m_y*f);
	}
	
	Position& operator*=(float f)
	{
		m_x *= f;
		m_y *= f;
		
		return *this;
	}
	
	Position& operator*=(int f)
	{
		m_x *= f;
		m_y *= f;
		
		return *this;
	}
	
	Position& operator++()
	{
		m_x++;
		
		return *this;
	}
	
	Position& operator--()
	{
		if(m_x >= 1)
		{
			m_x--;
		}
		else if(m_y >= 1)
		{
			m_x = 0;
			m_y--;
		}
		
		return *this;
	}
	
	Position operator%(const Position& p)
	{
		return Position((int)m_x%(int)p.m_x, ((int)m_y + ((int)m_x/(int)p.m_x))%(int)p.m_y);
	}
	
	Position& operator%=(const Position& p)
	{
		m_y += ((int)m_x/(int)p.m_x);
		
		m_x = (int)m_x % (int)p.m_x;
		m_y = (int)m_y % (int)p.m_y;
		
		return *this;
	}
	
	bool operator!=(const Position& p) const
	{
		return ((int)m_x != (int)p.m_x) || ((int)m_y != (int)p.m_y);
	}
	
	bool operator==(const Position& p) const
	{
		return ((int)m_x == (int)p.m_x) && ((int)m_y == (int)p.m_y);
	}
	
	private:
	
	float m_x;
	float m_y;
};

#endif
