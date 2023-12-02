#include "VertexArray.h"

#include "Renderer.h"

VertexArray::VertexArray()
{

};

VertexArray::~VertexArray()
{

};

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;

	// Loop through elements
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];

		// Enable vertex attribute array
		glEnableVertexAttribArray(i);

		// Set vertex attribute pointer
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);

		// Increment offset
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(0));
}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));
}
