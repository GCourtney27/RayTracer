//#pragma once
#ifndef HITABLELISTSH
#define HITABLELISTH
#include "Hitable.h"

class hitable_list : public Hitable {
public:
	//hitable_list() {}
	hitable_list(Hitable** l, int n) { list = l; list_size = n; }
	virtual bool hit(const Ray& r, float tmin, float tmax, hit_record& rec) const;
	Hitable** list;
	int list_size;
};

bool hitable_list::hit(const Ray& r, float t_min, float t_max, hit_record& rec) const {
	hit_record temp_rec;
	bool hit_anything = false;
	double closest_so_far = t_max;
	for (int i = 0; i < list_size; i++) {
		if (list[i]->hit(r, t_min, (float)closest_so_far, temp_rec)) {
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}
	return hit_anything;
}

#endif // !HITABLELISTSH
