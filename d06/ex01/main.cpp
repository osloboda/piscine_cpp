#include <iostream>
#include "data.hpp"

void *serialize()
{
    char trf[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *tmp = new char[20];
    for (int i = 0; i < 8; i++)
        tmp[i] = trf[rand() % 62];
    for (int i = 8; i < 12; i++)
        tmp[i] = rand() % 256 - 128;
    for (int i = 12; i < 19; i++)
        tmp[i] = trf[rand() % 62];
    tmp[19] = '\0';
    return (reinterpret_cast<void*>(tmp));
}

Data * deserialize(void *s)
{
    Data *data = new Data;
    data->n = 0;
    char *in = reinterpret_cast<char*>(s);
    for(int i = 0; i < 8; i++)
        data->s1 += in[i];
    data->n = in[8];
    for(int i = 12; i < 19; i++)
        data->s2 += in[i];
    return (data);
}

int main()
{
    void	*s;
    Data	*d;
    srand(time(0));
    s = serialize();
    d = deserialize(s);
    std::cout << d->s1 << std::endl << d->n << std::endl  << d->s2 << std::endl;
    delete d;
    return (0);
}