//---------------------------------------------------------------------------
// KeyboardGLFW.cpp
//---------------------------------------------------------------------------

#include "GLFW/glfw3.h"
#define GLEQ_IMPLEMENTATION
#include "gleq.h"
#include "impl/LowLevelInputGLFW.h"
#include "impl/KeyboardGLFW.h"

namespace CC
{
  //-------------------------------------------------------------------------
  KeyboardGLFW::KeyboardGLFW(LowLevelInputGLFW* lowLeveInputGLFW) :
    m_lowLevelInputGLFW(lowLeveInputGLFW)
  {
    m_keyArray.resize(ccKey_LastEnum);
    ClearKeyList();
  }

  //-------------------------------------------------------------------------
  void KeyboardGLFW::Update()
  {
    m_listKeysPressed.clear();

    for(std::list<GLEQevent>::iterator it = m_lowLevelInputGLFW->
        m_listEvents.begin(); it != m_lowLevelInputGLFW->m_listEvents.end();
        ++it)
    {
      GLEQevent* event = &(*it);

      if(event->type != GLEQ_KEY_PRESSED && event->type != GLEQ_KEY_RELEASED)
      {
        continue;
      }

      // Capture the key info
      ccKey key = GLEQToKey(event->key.key);
      m_keyArray[key] = (event->type == GLEQ_KEY_PRESSED);

      if (event->type == GLEQ_KEY_PRESSED)
      {
        m_listKeysPressed.push_back(KeyPress(key));
      }
    }
  }

  //-------------------------------------------------------------------------
  ccKey KeyboardGLFW::GLEQToKey(int key)
  {
    switch(key)
    {
      case GLFW_KEY_ESCAPE: return ccKey_ESCAPE;
    }
    return ccKey_NONE;
  }

  //-------------------------------------------------------------------------
  bool KeyboardGLFW::KeyIsPressed()
  {
    return m_listKeysPressed.empty() == false;
  }

  //-------------------------------------------------------------------------
  bool KeyboardGLFW::KeyIsDown(ccKey key)
  {
    return m_keyArray[key];
  }

  //-------------------------------------------------------------------------
  void KeyboardGLFW::ClearKeyList()
  {
    m_keyArray.assign(m_keyArray.size(), false);
  }
}
