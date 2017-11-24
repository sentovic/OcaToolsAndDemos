/*
 *  By downloading or using this file, the user agrees to be bound by the terms of the license 
 *  agreement located at http://ocaalliance.com/EULA as an original contracting party.
 *
 *  Description         : OcaLiteClassID
 *
 */

#ifndef OCALITECLASSID_H
#define OCALITECLASSID_H

// ---- Include system wide include files ----

// ---- Include local include files ----
#include "IOcaLiteMarshal.h"
#include "OcaLiteFrameworkDataTypes.h"
#include "OcaLiteString.h"

// ---- Referenced classes and types ----

// ---- Helper types and constants ----

#ifndef OCA_CLASS_ID_SIZE
/** The maximum depth of the class ID */
#define OCA_CLASS_ID_SIZE 5
#endif //OCA_CLASS_ID_SIZE

/** Class ID field mask to identify a proprietary class. */
#define OCA_CLASS_ID_PROPRIETARY_CLASS_FIELD_MASK       static_cast< ::OcaUint16>(0x8000)

/** Class ID field mask to identify a proprietary test class. */
#define OCA_CLASS_ID_PROPRIETARY_TEST_CLASS_FIELD_MASK  static_cast< ::OcaUint16>(0xff00)

// ---- Helper functions ----

// ---- Class Definition ----

/**
 * Class identifier : structured variable of the form a.b.c...
 * @ingroup FrameworkDataTypes
 */
class OcaLiteClassID : public ::IOcaLiteMarshal
{
public:
    /** Default constructor. */
    OcaLiteClassID();

    /**
     * Constructor.
     *
     * @param[in]   fieldCount  Identifies the number of fields of the ClassID, i.e. the level of the class
     *                          tree the class is in. For example if this field count is 3, the ClassID is of
     *                          the form 'n.m.p'. The minimum field count is 1 (OcaRoot class). A field count
     *                          of zero is invalid.
     * @param[in]   fields      Array of actual fields of the ClassID. The array has 'fieldCount' entries. If
     *                          for example the field count is 3 and the Fields array has value {1, 2, 3} the
     *                          ClassID is '1.2.3'.
     */
    OcaLiteClassID(::OcaUint16 fieldCount, const ::OcaUint16* fields);

    /**
     * Copy constructor.
     *
     * @param[in]   source      The source to copy the object from.
     */
    OcaLiteClassID(const ::OcaLiteClassID& source);

    /**
     * Destructor.
     */
    virtual ~OcaLiteClassID();

    /**
     * Retrieves the class ID of the parent class.
     *
     * @param[out]  parent      The class ID of the parent class.
     * @return True if there is a parent, false otherwise.
     */
    bool GetParent(::OcaLiteClassID& parent) const;

    /**
     * Getter for FieldCount.
     *
     * @return The number of fields of the ClassID.
     */
    ::OcaUint16 GetFieldCount() const
    {
        return m_fieldCount;
    }

    /**
     * Getter for the Fields.
     *
     * @return The Fields.
     */
    const ::OcaUint16* GetFields() const
    {
        return m_fields;
    }

    /**
     * Assignment operator.
     *
     * @param[in]   source      The source to assign the object from.
     * @return A reference to this object.
     */
    ::OcaLiteClassID& operator=(const ::OcaLiteClassID& source);

    /**
     * The is-equal operator.
     *
     * @param[in]   rhs         The object to compare with.
     * @return True if the classes are equal.
     */
    bool operator==(const ::OcaLiteClassID& rhs) const;

    /**
     * The is-not-equal operator.
     *
     * @param[in]   rhs         The object to compare with.
     * @return True if the classes are not equal.
     */
    bool operator!=(const ::OcaLiteClassID& rhs) const;

    /**
     * The less-than operator.
     *
     * @param[in]   rhs         The object to compare with.
     * @return True if this object is less than rhs.
     */
    bool operator<(const ::OcaLiteClassID& rhs) const;

    /**
     * The less-than-or-equal operator.
     *
     * @param[in]   rhs         The object to compare with.
     * @return True if this object is less than or equal to rhs.
     */
    bool operator<=(const ::OcaLiteClassID& rhs) const;

    /**
     * The greater-than operator.
     *
     * @param[in]   rhs         The object to compare with.
     * @return True if this object is greater than rhs.
     */
    bool operator>(const ::OcaLiteClassID& rhs) const;

    /**
     * The greater-than-or-equal operator.
     *
     * @param[in]   rhs         The object to compare with.
     * @return True if this object is greater than or equal to rhs.
     */
    bool operator>=(const ::OcaLiteClassID& rhs) const;

    // ---- IOcaLiteMarshal methods ----

    virtual void Marshal(::OcaUint8** destination, const ::IOcaLiteWriter& writer) const;

    virtual bool Unmarshal(::OcaUint32& bytesLeft, const ::OcaUint8** source, const ::IOcaLiteReader& reader);

    virtual ::OcaUint32 GetSize(const ::IOcaLiteWriter& writer) const;

private:
    /** The number of fields of the ClassID. */
    ::OcaUint16     m_fieldCount;

    /** The fields. */
    ::OcaUint16     m_fields[OCA_CLASS_ID_SIZE];
};

#endif // OCALITECLASSID_H
