#ifndef STRING_H
#define STRING_H

#ifdef __cplusplus

class String
{
private:
	unsigned int m_Length;
	char* m_Buffer;

public:
	String()
	{
		m_Length = 0;
		m_Buffer = new char[0];
	}

	String(const char* cString)
	{
		if (cString)
		{
			unsigned int n = 0;
			while (cString[n] != '\0') n++;
			m_Length = n;
			m_Buffer = new char[m_Length + 1];
			for (unsigned int i = 0; i < m_Length; i++) m_Buffer[i] = cString[i];
			m_Buffer[m_Length] = '\0';
		}
		else
		{
			m_Length = 0;
			m_Buffer = new char[0];
		}
	}

	String(const String& string)
	{
		m_Length = string.Size();
		m_Buffer = new char[m_Length + 1];
		for (unsigned int i = 0; i < m_Length; i++) m_Buffer[i] = string[i];
		m_Buffer[m_Length] = '\0';
	}

	~String()
	{
		m_Length = 0;
		delete[] m_Buffer;
	}

	int Size() const
	{
		return m_Length;
	}

	const char* c_str() const
	{
		return m_Buffer;
	}

	bool Equals(String& other) const
	{
		if (m_Length != other.Size()) return false;
		unsigned int n = 0;
		while ((n < m_Length) && (m_Buffer[n] == other[n])) n++;
		return (n == m_Length);
	}

	bool Equals(const char* other) const
	{
		String string(other);
		return this->Equals(string);
	}

	int Index(char c) const
	{
		for (unsigned int i = 0; i < m_Length; i++)
		{
			if (m_Buffer[i] == c) return (int)i;
		}
		return -1;
	}

	String& Concat(const String& string)
	{
		unsigned int len = m_Length + string.Size();
		char* tempStr = new char[len + 1];

		for (unsigned int i = 0; i < m_Length; i++)
		{
			tempStr[i] = m_Buffer[i];
		}

		for (int i = 0; i < string.Size(); i++)
		{
			tempStr[m_Length + i] = string[i];
		}

		delete[] m_Buffer;
		m_Length = len;
		m_Buffer = new char[len + 1];

		for (unsigned int i = 0; i < m_Length; i++)
		{
			m_Buffer[i] = tempStr[i];
		}

		m_Buffer[len] = '\0';

		delete[] tempStr;
		tempStr = nullptr;

		return *this;
	}

	String& Concat(const char* string)
	{
		String other(string);
		return this->Concat(other);
	}

	String& ToUpperCase()
	{
		for (unsigned int i = 0; i < m_Length; i++)
		{
			if ('a' <= m_Buffer[i] && m_Buffer[i] <= 'z') m_Buffer[i] -= ('a' - 'A');
		}
		return *this;
	}

	String& ToLowerCase()
	{
		for (unsigned int i = 0; i < m_Length; i++)
		{
			if ('A' <= m_Buffer[i] && m_Buffer[i] <= 'Z') m_Buffer[i] += ('a' - 'A');
		}
		return *this;
	}

	String& operator=(const String& string)
	{
		if (this == &string) return *this;

		delete[] m_Buffer;
		m_Length = string.Size();
		m_Buffer = new char[m_Length + 1];

		for (unsigned int i = 0; i < m_Length; i++)
		{
			m_Buffer[i] = string[i];
		}

		m_Buffer[m_Length] = '\0';

		return *this;
	}

	char operator[] (unsigned int index) const
	{
		if (index >= m_Length) throw 1;
		return m_Buffer[index];
	}

	char& operator[] (unsigned int index)
	{
		if (index >= m_Length) throw 1;
		return m_Buffer[index];
	}

	friend bool operator==(String& left, String& right)
	{
		return left.Equals(right);
	}

	friend bool operator==(String& left, const char* right)
	{
		return left.Equals(right);
	}

	friend bool operator==(const char* left, String& right)
	{
		return right.Equals(left);
	}

	friend bool operator!=(String& left, String& right)
	{
		return !left.Equals(right);
	}

	friend bool operator!=(String& left, const char* right)
	{
		return !left.Equals(right);
	}

	friend bool operator!=(const char* left, String& right)
	{
		return !right.Equals(left);
	}

	friend String operator+(const String& left, const String& right)
	{
		return String(left).Concat(right);
	}

	friend String operator+(const String& left, const char* right)
	{
		return String(left).Concat(right);
	}

	friend String operator+(const char* left, const String& right)
	{
		return String(left).Concat(right);
	}

	String& operator+=(const String& string)
	{
		return this->Concat(string);
	}

};

#endif /* ifdef __cplusplus */

#endif /* STRING_H */
