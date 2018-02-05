#include "Core.hpp"

int main(int ac, char **av)
{
  arcade::Core Core(ac, av);

  if (!Core.setup("games/", "lib/"))
    return (1);
  return (Core.play());
}
