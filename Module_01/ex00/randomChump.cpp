# include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie *zombie_rand;
    zombie_rand = newZombie(name);
    zombie_rand->annouce();

}