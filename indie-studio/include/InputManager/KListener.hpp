#ifndef KLISTENER_HPP_
# define KLISTENER_HPP_

# include <OISEvents.h>
# include <OISKeyboard.h>

namespace OgreInput
{
  class KListener : public OIS::KeyListener
  {
  protected:
    bool			(*_onKeyPressed)(const OIS::KeyEvent&);
    bool			(*_onKeyReleased)(const OIS::KeyEvent&);

  public:
    KListener();
    KListener(bool (*)(const OIS::KeyEvent&),
	      bool (*)(const OIS::KeyEvent&));
    ~KListener();

    virtual bool		keyPressed(const OIS::KeyEvent&);
    virtual bool		keyReleased(const OIS::KeyEvent&);

    void			setOnKeyPressed(bool (*)(const OIS::KeyEvent&));
    void			setOnKeyReleased(bool (*)(const OIS::KeyEvent&));
  };
};

#endif /* !KLISTENER_HPP_ */
