# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *friends = new Zombie[N];
	char number;

	number = '!';
	for (int i = 0; i < N; i++)
	{
		friends[i].set_name(name + " " + number);
		friends[i].annouce();
		number++;
	}
	return friends;
}