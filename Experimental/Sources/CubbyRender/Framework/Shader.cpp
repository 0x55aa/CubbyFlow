/*************************************************************************
> File Name: Shader.cpp
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: Abstract base class for Shader object.
> Created Time: 2020/02/19
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#include <Framework/Shader.h>
#include <Framework/Renderer.h>
#include <Framework/ShaderPreset.h>
#include <Framework/Common.h>
#include <cassert>

#include <fstream>
#include <sstream>

namespace CubbyFlow {
namespace CubbyRender {
    
    Shader::Shader()
    {
        //! Do nothing.
    }

    Shader::~Shader()
    {   
        //! Do nothing.
    }

    int Shader::load(const std::string& shaderName)
    {
        ShaderMap shaderMap;

        if (shaderName == "simple_shader")
        {
            std::string vertexShader = kSimpleColorShaders[0];
            std::string fragmentShader = kSimpleColorShaders[1];

            shaderMap = {
                {"VertexShader", vertexShader},
                {"FragmentShader", fragmentShader}
            };

            _format = VertexFormat::Position3;
        }
        return onLoad(shaderMap);
    }

    int Shader::load(VertexFormat format, const ShaderMap& fileMap)
    {
        ShaderMap shaderMap;

        for(const auto& shaderPair : fileMap)
        {
            const std::string& shaderType = shaderPair.first;
            std::string shaderFilePath = shaderPair.second;
            
            std::ifstream file(shaderFilePath.c_str());
            if (file)
            {
		        std::ostringstream osstr;
		        osstr << file.rdbuf();
		        std::string shaderSource = osstr.str();
                shaderMap.insert(std::make_pair(shaderType, shaderSource));
		        file.close();
            }
            else
            {
                return 1;
            }
        }
        
        _format = format;
        return onLoad(shaderMap);
    }

    VertexFormat Shader::getInputVertexFormat() const
    {
        return _format;
    }

    const ShaderParameters& Shader::getParameters() const
    {
        return _parameters;
    }

    void Shader::setParameters(const ShaderParameters& parameters)
    {
        _parameters = parameters;
    }


} 
}