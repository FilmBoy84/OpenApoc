
#pragma once
#include "library/sp.h"

#include "framework/image.h"
#include "control.h"
#include "forms_enums.h"

namespace OpenApoc
{

class Graphic : public Control
{

  private:
	sp<Image> image;

  protected:
	virtual void OnRender() override;

  public:
	HorizontalAlignment ImageHAlign;
	VerticalAlignment ImageVAlign;
	FillMethod ImagePosition;
	bool AutoSize;

	Graphic(Control *Owner, sp<Image> Image = nullptr);
	virtual ~Graphic();

	virtual void EventOccured(Event *e) override;
	virtual void Update() override;
	virtual void UnloadResources() override;

	sp<Image> GetImage() const;
	void SetImage(sp<Image> Image);

	virtual Control *CopyTo(Control *CopyParent) override;
	virtual void ConfigureFromXML(tinyxml2::XMLElement *Element) override;
};

}; // namespace OpenApoc
