#include <iostream>
#include <string>

template <typename T>
void	iter(T *ad, size_t len, void (*f)(T&))
{
	for (size_t i = 0; i < len; i++)
		(*f)(ad[i]);
}

template <typename T>
void	print(T &D)
{
	std::cout << D << std::endl;
}

int main(void)
{
	std::string	t[] = 
	{
		"Aytj", "BtjyjC", "F", "tjyjI", "tjyj"
	};
	iter<std::string>(t, 5, &print<std::string>);
	return (0);
}
