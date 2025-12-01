#pragma once
typedef float scal;
class Vec2 {
	scal x;
	scal y;

public:
	//Choisir un des deux constructeur
	Vec2();
	Vec2(scal x, scal y);
	~Vec2();

	Vec2 operator+(const Vec2& vec);
	Vec2 operator-(const Vec2& vec);
	Vec2 operator*(const Vec2& vec);
	Vec2 operator/(const Vec2& vec);

	Vec2& operator+=(const Vec2& vec);
	Vec2& operator-=(const Vec2& vec);
	Vec2& operator*=(const Vec2& vec);
	Vec2& operator/=(const Vec2& vec);

	bool operator==(const Vec2& vec);
	bool operator!=(const Vec2& vec);
	void operator<<(const Vec2& vec);


};