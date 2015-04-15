#ifndef POSE_INCLUDED_HPP
#define POSE_INCLUDED_HPP

struct UUID
{

};

class Rotation
{
public:

    Rotation(double x, double y, double z, double w)
        : rotation_{x, y, z, w}
    { }

    Rotation(const Rotation &other)
        : rotation_{other.rotation_[0], other.rotation_[1], other.rotation_[2], other.rotation_[3]}
    { }

    double getX() const { return rotation_[0]; }

    double getY() const { return rotation_[1]; }

    double getZ() const { return rotation_[2]; }

    double getW() const { return rotation_[3]; }

    void setX(double x) { rotation_[0] = x; }

    void setY(double y) { rotation_[1] = y; }

    void setZ(double z) { rotation_[2] = z; }

    void setW(double w) { rotation_[3] = w; }

private:
    double rotation_[ 4 ] ;
};

class Translation
{
public:

    Translation(double x, double y, double z)
        : translation_{x, y, z}
    { }

    Translation(const Translation &other)
        : translation_{other.translation_[0], other.translation_[1], other.translation_[2]}
    { }

    double getX() const { return translation_[0]; }

    double getY() const { return translation_[1]; }

    double getZ() const { return translation_[2]; }

    void setX(double x) { translation_[0] = x; }

    void setY(double y) { translation_[1] = y; }

    void setZ(double z) { translation_[2] = z; }

private:
    double translation_[ 3 ] ;
};


class Pose
{
public:

    Pose(const Translation &translation, const Rotation &rotation)
        : translation_(translation)
        , rotation_(rotation)
    { }

    const Translation & getTranslation() const { return translation_; }

    const Rotation & getRotation() const { return rotation_; }

private:
    Translation translation_;
    Rotation rotation_ ;
};

class Device
{
public:

    // URI node
    const Pose & getHead() const { return head_; }

private:
    UUID deviceID_ ;
    Pose head_;
};

#endif
