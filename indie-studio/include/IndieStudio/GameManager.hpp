//
// GameManager.hpp for  in /home/agor_m/epitech/cpp_indie_studio
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Sun Jun  5 20:06:04 2016 Maxime Agor
// Last update Sun Jun  5 20:06:07 2016 Maxime Agor
//

#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

# include "OgreUtilities/InitOgre.hpp"
# include "InputManager/InputManager.hpp"
# include "Gui/Manager.hpp"
# include "Tools/Thread.hpp"
# include "IndieStudio/GameObjectManager.hpp"
# include "IndieStudio/PrefabCreator.hpp"
# include "Tools/chrono.hpp"
# include "IndieStudio/FrameListener.hpp"
# include "Network/NetManager.hpp"

namespace indie
{
  class FrameListener;

  struct GDelete
  {
    GDelete(GameObject *_go, long _ms)
      :go(_go), ms(_ms)
    {}

    GameObject *go;
    long	ms;
  };

  class GameManager
  {
  public:
    GameManager(OgreUtilities::InitOgre *ogre);
    ~GameManager();

    static void start();
    static void stop();

    static void managerUpdate();

    static OgreUtilities::InitOgre	*&getOgreInstance();
    static Ogre::RenderSystem		*&getRenderSystem();
    static Ogre::RenderWindow		*&getRenderWindow();
    static Ogre::SceneManager		*&getSceneManager();
    static Ogre::Camera			*&getCamera();
    static Ogre::Viewport		*&getViewport();
    static Gui::Manager			*&getGuiManager();
    static OgreInput::InputManager	*&getInputManager();
    static indie::GameObjectManager	&getGameObjects();
    static indie::PrefabCreator		&getPrefabCreator();
    static network::NetManager		&getNetworkManager();
    static indie::GameObject		*instantiate(std::string const &prefabFile,
						     Ogre::Vector3 const & position,
						     Ogre::Quaternion const &rotation
						     = Ogre::Quaternion::IDENTITY,
						     Ogre::Vector3 const & scale
						     = Ogre::Vector3(1, 1, 1));
    static void				setDeltaTime(float deltaTime);
    static float			getDeltaTime();
    static void				destroy(GameObject *gameObject, int ms = 0);
    static long				getActualTime();
    static indie::GameObject		*getGame();

  private:
    static bool checkDeleteList(std::string const &name);

    static void startOgre();
    static void initInputManager();
    static void initSocket();
    static void initGui();
    static void startPresentation();

  private:
    static std::vector<GDelete>		_deleteList;
    static Time::Chrono			_time;
    static OgreUtilities::InitOgre	*_ogre;
    static Gui::Manager			*_GuiManager;
    static OgreInput::InputManager	*_input;
    static indie::GameObjectManager	_gameObjects;
    static indie::PrefabCreator		_prefabCreator;
    static indie::FrameListener		*_frameListener;
    static Memory::Thread		_thread;
    static network::NetManager		_networkManager;
    static float			_deltaTime;
    static indie::GameObject		*_game;
  };
};

#endif /* GAMEMANAGER_HPP_ */
