#pragma once

namespace wizmrenderer
{
    class renderable;
    
    enum eRenderStateType
    {
        eRenderStateType_Sector = 0,
        eRenderStateType_Pass = 1,
        eRenderStateType_DepthTest = 2,
        eRenderStateType_Depth = 3,
        eRenderStateType_AlphaMode = 4,
        eRenderStateType_BlendMode = 5,
        eRenderStateType_VertexProgram = 6,
        eRenderStateType_FragmentProgram = 7,
        eRenderStateType_Texture = 8,
        eRenderStateType_VertexBuffer = 9,
        eRenderStateType_Matrix = 10,
        eRenderStateType_Render = 11,
        eRenderStateType_LastEnum  = 12
    };
    
    
    class render_state
    {
    public:
    
    
    
    private:
        renderable* m_renderable;
    };

}


