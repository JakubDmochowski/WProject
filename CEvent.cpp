#include "CEvent.h"

CEvent CEvent::eventHandler;

CEvent::CEvent() {
}

CEvent::~CEvent() {
    //Do nothing
}

void CEvent::HandleEvents() {
    SDL_Event Event;
    while(SDL_PollEvent(&Event)) {
        OnEvent(&Event);
    }
}

void CEvent::OnEvent(SDL_Event* Event) {
    switch(Event->type) {
        case SDL_WINDOWEVENT: {
            switch(Event->window.event) {
                case SDL_WINDOWEVENT_ENTER: {
                    for(auto& wl : WindowListener::windowListeners) {
                        wl->OnMouseFocus();
                    }
                    break;
                }
                case SDL_WINDOWEVENT_LEAVE: {
                    for(auto& wl : WindowListener::windowListeners) {
                        wl->OnMouseBlur();
                    }
                    break;
                }
                case SDL_WINDOWEVENT_FOCUS_GAINED: {
                    for(auto& wl : WindowListener::windowListeners) {
                        wl->OnInputFocus();
                    }
                    break;
                }
                case SDL_WINDOWEVENT_FOCUS_LOST: {
                    for(auto& wl : WindowListener::windowListeners) {
                        wl->OnInputBlur();
                    }
                    break;
                }
                case SDL_WINDOWEVENT_RESIZED: {
                    for(auto& wl : WindowListener::windowListeners) {
                        wl->OnResize(Event->window.data1,Event->window.data2);
                    }
                    break;
                }
            }
            break;
        }

        case SDL_KEYDOWN: {
            for(auto& kl : KeyboardListener::keyboardListeners) {
                kl->OnKeyDown(Event->key.keysym.sym);
            }
            break;
        }

        case SDL_KEYUP: {
            for(auto& kl : KeyboardListener::keyboardListeners) {
                kl->OnKeyUp(Event->key.keysym.sym);
            }
            break;
        }

        case SDL_MOUSEMOTION: {
            for(auto& ml : MouseListener::mouseListeners) {
                ml->OnMouseMove(Event->motion.x,Event->motion.y,Event->motion.xrel,Event->motion.yrel,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
            }
            break;
        }

        case SDL_MOUSEBUTTONDOWN: {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    for(auto& ml : MouseListener::mouseListeners) {
                        ml->OnLButtonDown(Event->button.x,Event->button.y);
                    }
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    for(auto& ml : MouseListener::mouseListeners) {
                        ml->OnRButtonDown(Event->button.x,Event->button.y);
                    }
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    for(auto& ml : MouseListener::mouseListeners) {
                        ml->OnMButtonDown(Event->button.x,Event->button.y);
                    }
                    break;
                }
            }
            break;
        }

        case SDL_MOUSEBUTTONUP:    {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    for(auto& ml : MouseListener::mouseListeners) {
                        ml->OnLButtonUp(Event->button.x,Event->button.y);
                    }
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    for(auto& ml : MouseListener::mouseListeners) {
                        ml->OnRButtonUp(Event->button.x,Event->button.y);
                    }
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    for(auto& ml : MouseListener::mouseListeners) {
                        ml->OnMButtonUp(Event->button.x,Event->button.y);
                    }
                    break;
                }
            }
            break;
        }

        case SDL_JOYAXISMOTION: {
            for(auto& jl : JoystickListener::joystickListeners) {
                jl->OnJoyAxis(Event->jaxis.which,Event->jaxis.axis,Event->jaxis.value);
            }
            break;
        }

        case SDL_JOYBALLMOTION: {
            for(auto& jl : JoystickListener::joystickListeners) {
                jl->OnJoyBall(Event->jball.which,Event->jball.ball,Event->jball.xrel,Event->jball.yrel);
            }
            break;
        }

        case SDL_JOYHATMOTION: {
            for(auto& jl : JoystickListener::joystickListeners) {
                jl->OnJoyHat(Event->jhat.which,Event->jhat.hat,Event->jhat.value);
            }
            break;
        }
        case SDL_JOYBUTTONDOWN: {
            for(auto& jl : JoystickListener::joystickListeners) {
                jl->OnJoyButtonDown(Event->jbutton.which,Event->jbutton.button);
            }
            break;
        }

        case SDL_JOYBUTTONUP: {
            for(auto& jl : JoystickListener::joystickListeners) {
                jl->OnJoyButtonUp(Event->jbutton.which,Event->jbutton.button);
            }
            break;
        }

        case SDL_QUIT: {
            for(auto& wl : WindowListener::windowListeners) {
                wl->OnExit();
            }
            break;
        }

        case SDL_SYSWMEVENT: {
            //Ignore
            break;
        }

        default: {
            for(auto& ul : UserDefinedListener::userDefinedListeners) {
                ul->OnUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
            }
            break;
        }
    }
}
