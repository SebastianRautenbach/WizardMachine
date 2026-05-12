#pragma once

namespace wizmrenderer
{
    class camera;
    class renderlist;
    
    class renderable
    {
    public:
        virtual void UpdateGraphics(camera* camera,float delta_time, renderlist*_renderlist){}
        
    private:
        
    };
}
