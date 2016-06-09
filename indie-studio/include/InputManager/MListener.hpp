//
//
//

#ifndef MLISTENER_HPP_
# define  MLISTENER_HPP_

# include <OISEvents.h>
# include <OISMouse.h>
# include <iostream>

namespace OgreInput
{
  class MListener : public OIS::MouseListener
  {
  protected:
    bool			(*_onMouseMoved)(const OIS::MouseEvent& me);
    bool			(*_onMousePressed)(const OIS::MouseEvent& me,
						   OIS::MouseButtonID id);
    bool			(*_onMouseReleased)(const OIS::MouseEvent& me,
						    OIS::MouseButtonID id);

  public:
    MListener();
    MListener(bool (*onMouseMoved)(const OIS::MouseEvent& me),
	      bool (*onMousePressed)(const OIS::MouseEvent& me, OIS::MouseButtonID id),
	      bool (*onMouseReleased)(const OIS::MouseEvent& me, OIS::MouseButtonID id));
    virtual ~MListener();

    virtual bool		mouseMoved(const OIS::MouseEvent& me);
    virtual bool		mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id);
    virtual bool		mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id);

  public:
    void			setOnMouseMoved(bool (*)(const OIS::MouseEvent& me));
    void			setOnMousePressed(bool (*)(const OIS::MouseEvent& me,
							   OIS::MouseButtonID id));
    void			setOnMouseReleased(bool (*)(const OIS::MouseEvent& me,
							    OIS::MouseButtonID id));
  };
};

#endif /* ! MOUSELISTENER_HPP_ */
