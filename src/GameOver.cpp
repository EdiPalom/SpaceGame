#include <GameOver.hpp>

GameOver::GameOver():Entity(ResourceManager::get_texture("game_over")->get_ptr(),sf::Vector2i(690,157),sf::Vector2f(5,0.5 * WINDOW_HEIGHT - 100)),m_timer(1500)
{

}

void GameOver::update_current(double dt)
{
    if(m_timer.get_signal(dt))
        EventManager::set_event(CHANGE_SCENE);
}

void GameOver::set_collision(bool c)
{
    
}


