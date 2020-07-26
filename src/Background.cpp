
#include <Background.hpp>

Background::Background(std::string texture_name, float speed)
{
    // sf::Vector2i tile_size = ResourceManager::get_texture_size(texture_name);
    Texture* tile = ResourceManager::get_texture(texture_name);
    sf::Vector2i tile_size = tile->get_size();
    
    int x = (WINDOW_WIDTH / tile_size.x) + 1;
    int y = (WINDOW_HEIGHT / tile_size.y) + 1;

    // std::cout << tile_size.x << " " << tile_size.y << std::endl;

    for(int i = 0; i <= y; ++i)
        for(int j = 0; j <= x; ++j)
        {
            std::shared_ptr<Entity> background = std::make_shared<Entity>(tile->get_ptr(), tile_size, sf::Vector2f(i * tile_size.x, j * tile_size.y), sf::Vector2f(0,1));
            
            World::list.push_back(background);
        }
}
