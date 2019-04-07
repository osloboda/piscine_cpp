#ifndef BULLET_HPP
# define BULLET_HPP

class Bullet
{
	public:
		int row;
		int col;
		Bullet() {}
		Bullet(int r, int c)
		{
			this->row = r;
			this->col = c;
		}
};

#endif
