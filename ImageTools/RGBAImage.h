#pragma once
#include "ImageTools_i.h"
#include "rawimage.h"
class CRGBAImage :
	public CRawImage <COM_STRUCT_CLR_RGBA>
{
public:
	CRGBAImage(void);
	~CRGBAImage(void);
};

