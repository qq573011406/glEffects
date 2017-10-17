
#pragma  once

#ifndef GLEFFECTS_H
#define GLEFFECTS_H

#include <map>
#include <vector>
#include <ostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>



enum class StateValueType
{
	COMPILE,
	BOOLEAN,
	STRING,
	INTEGER,
	FLOAT,
	FLOAT2,
	FLOAT3,
	FLOAT4,
	D3DCOLOR,
	UNKNOWN,
};

class StateAssignmentValue
{
public:

	StateAssignmentValue(StateValueType vt):
		m_ValueType(StateValueType::UNKNOWN)
	{
		m_ValueType = vt;
	}
	virtual ~StateAssignmentValue()
	{
	}

	virtual std::string toString() const = 0;

	const StateValueType getValueType() const { return m_ValueType; }

private:
	StateValueType m_ValueType;
};


class StateCompileValue : public StateAssignmentValue
{
public:
	StateCompileValue( std::string target, std::string entrypoint) :StateAssignmentValue(StateValueType::COMPILE)
	{
		m_Target = target;
		m_Entrypoint = entrypoint;
	}
	~StateCompileValue()override = default;

	const std::string getTarget() const { return m_Target; }
	const std::string getEntryPoint() const { return m_Entrypoint; }

	
	virtual std::string toString() const override
	{
		return "Target:" + m_Target + " EntryPoint:" + m_Entrypoint;
	}

private:
	std::string m_Target;
	std::string m_Entrypoint;
};


class StateBooleanValue : public  StateAssignmentValue
{
public:
	StateBooleanValue(bool value) :StateAssignmentValue(StateValueType::BOOLEAN)
	{
		m_Val = value;
	}
	~StateBooleanValue()override = default;

	const bool getValue() const { return m_Val; }

	virtual std::string toString()  const override
	{
		return m_Val ? "TRUE" : "FALSE";
	}

private:
	bool m_Val;
};

class StateIntegerValue : public  StateAssignmentValue
{
public:
	StateIntegerValue(int value) :StateAssignmentValue(StateValueType::INTEGER)
	{
		m_Val = value;
	}
	~StateIntegerValue()override = default;

	const int getValue() const { return m_Val; }

	virtual std::string  toString()  const override
	{
		std::stringstream ss;
		ss << m_Val;
		return ss.str();
	}

private:
	int m_Val;
};

class StateFloatValue : public  StateAssignmentValue
{
public:
	StateFloatValue(float value) :StateAssignmentValue(StateValueType::FLOAT)
	{
		m_Val = value;
	}
	~StateFloatValue()override = default;

	const float getValue() const { return m_Val; }

	virtual  std::string toString()  const override
	{
		std::stringstream ss;
		ss << m_Val;
		return ss.str();
	}

private:
	float m_Val;
};

class StateFloat2Value : public  StateAssignmentValue
{
public:
	StateFloat2Value(float value[2]) :StateAssignmentValue(StateValueType::FLOAT2)
	{
		m_Val[0] = value[0];
		m_Val[1] = value[1];
	}
	~StateFloat2Value()override = default;

	const float* getValue() const { return m_Val; }

	virtual  std::string toString()  const override
	{
		std::stringstream ss;
		ss << "float2<" << m_Val[0] << "," << m_Val[1]<< ">";
		return ss.str();
	}

private:
	float m_Val[2];
};
class StateFloat3Value : public  StateAssignmentValue
{
public:
	StateFloat3Value(float value[3]) :StateAssignmentValue(StateValueType::FLOAT3)
	{
		m_Val[0] = value[0];
		m_Val[1] = value[1];
		m_Val[2] = value[2];
	}
	~StateFloat3Value()override = default;

	const float* getValue() const { return m_Val; }

	virtual  std::string toString()  const override
	{
		std::stringstream ss;
		ss << "float3<" << m_Val[0] << "," << m_Val[1] << "," << m_Val[2]<< ">";
		return ss.str();
	}

private:
	float m_Val[3];
};
class StateFloat4Value : public  StateAssignmentValue
{
public:
	StateFloat4Value(float value[4]) :StateAssignmentValue(StateValueType::FLOAT4)
	{
		m_Val[0] = value[0];
		m_Val[1] = value[1];
		m_Val[2] = value[2];
		m_Val[3] = value[3];
	}
	~StateFloat4Value()override = default;

	const float* getValue() const { return m_Val; }

	virtual  std::string toString()  const override
	{
		std::stringstream ss;
		ss << "float4<"<<m_Val[0]<<"," << m_Val[1] << "," << m_Val[2] << "," << m_Val[3] <<">";
		return ss.str();
	}

private:
	float m_Val[4];
};


class StateStringValue : public StateAssignmentValue
{
public:
	StateStringValue(std::string value) :StateAssignmentValue(StateValueType::STRING)
	{
		m_Val = value;
	}
	~StateStringValue()override = default;

	const std::string getValue() const { return m_Val; }

	virtual std::string toString()  const override
	{
		return m_Val;
	}

private:
	std::string m_Val;
};




class StateAssignmentNode
{
public:
	StateAssignmentNode(std::string name, StateAssignmentValue* value,int nameIndex = -1)
	{
		m_Name = name;
		m_Value = value;
		m_NameIndex = nameIndex;
	}
	~StateAssignmentNode() {
		if (m_Value != nullptr) {
			delete m_Value;
			m_Value = nullptr;
		}
	};
	const std::string getName() const { return m_Name; }
	const StateAssignmentValue* getValue() const { return m_Value; }
	const int getNameIndex() const { return m_NameIndex; }
private:
	std::string m_Name;
	int m_NameIndex;
	StateAssignmentValue* m_Value;
};




class PassNode
{
public:
	PassNode(std::string name, std::vector<StateAssignmentNode*> states)
	{
		m_Name = name;
		m_StateAssignments = states;
	}
	~PassNode()
	{
		for (auto state : m_StateAssignments) {
			delete state;
		}
		m_StateAssignments.clear();
	}
	const std::string getName() const { return m_Name; }


	const std::vector<StateAssignmentNode*> getStateAssignments()const { return m_StateAssignments; }

private:
	std::string m_Name;
	std::vector<StateAssignmentNode*> m_StateAssignments;
};



class TechniqueNode
{

public:
	TechniqueNode(std::string name,std::vector<PassNode*> passNodes)
	{
		m_Name = name;
		m_PassNodes = passNodes;
	}
	~TechniqueNode()
	{
		for (auto passNode : m_PassNodes) {
			delete passNode;
		}
		m_PassNodes.clear();
	}

	const std::string getName() const { return m_Name; }
	std::vector<PassNode*> getPasses() const { return m_PassNodes; }
private:
	std::string m_Name;
	std::vector<PassNode*> m_PassNodes;
};


class CodeBlock
{
public:
	CodeBlock(std::string name,std::string code)
	{
		m_Name = name;
		m_Code = code;
	};
	~CodeBlock() {};

public:
	const std::string getName()const { return m_Name; }
	const std::string getCode()const { return m_Code; }

private:
	std::string m_Name;
	std::string m_Code;
};

class UniformNode
{
public:
	UniformNode(std::string type, std::string name, std::string semantic)
	{
		m_Name = name;
		m_Type = type;
		m_Semantic = semantic;
	}
	~UniformNode() {};

	const std::string getName()const { return m_Name; }
	const std::string getType()const { return m_Type; }
	const std::string getSemantic()const { return m_Semantic; }

private:
	std::string m_Name;
	std::string m_Type;
	std::string m_Semantic;
};



class GLEffectsTree
{
public:
	GLEffectsTree() {}
	~GLEffectsTree()
	{
		for (auto tec:m_Techniques)
		{
			delete tec;
		}
		m_Techniques.clear();

		for (auto block : m_CodeBlocks)
		{
			delete block;
		}
		m_CodeBlocks.clear();

		for (auto uniform : m_Uniforms)
		{
			delete uniform;
		}
		m_Uniforms.clear();
	}
	const std::vector<UniformNode*> getUniforms() const { return m_Uniforms; }
	const std::vector<CodeBlock*> getCodeBlocks() const { return m_CodeBlocks; }
	const std::vector<TechniqueNode*> getTechiques() const { return m_Techniques; }
	void AddTechnique(TechniqueNode& technique) { m_Techniques.push_back(&technique); }
	void AddUniform(UniformNode& uniform) { m_Uniforms.push_back(&uniform); }
	void AddCodeBlock(CodeBlock* block)
	{
		m_CodeBlocks.push_back(block);
	}
private:
	std::vector<TechniqueNode*> m_Techniques;
	std::vector<CodeBlock*> m_CodeBlocks;
	std::vector<UniformNode*> m_Uniforms;
};


#endif // GLEFFECTS_H
