#import <Foundation/Foundation.h>

#import "MGLForegroundStyleLayer.h"

NS_ASSUME_NONNULL_BEGIN

/**
 `MGLVectorStyleLayer` is an abstract superclass for style layers whose content
 is defined by an `MGLGeoJSONSource` or `MGLVectorSource` object.
 
 Do not create instances of this class directly, and do not create your own
 subclasses of this class. Instead, create instances of the following concrete
 subclasses: `MGLCircleStyleLayer`, `MGLFillStyleLayer`, `MGLLineStyleLayer`,
 and `MGLSymbolStyleLayer`.
 */
@interface MGLVectorStyleLayer : MGLForegroundStyleLayer

#pragma mark Refining a Style Layer’s Content

/**
 Identifier of the layer within the source identified by the `sourceIdentifier`
 property from which the receiver obtains the data to style.
 */
@property (nonatomic, nullable) NSString *sourceLayerIdentifier;

/**
 The style layer’s predicate.
 
 Use the style layer’s predicate to include only the features in the source
 layer that satisfy a condition that you define. If the style layer initially
 comes from the style, its predicate corresponds to the
 <a href="https://www.mapbox.com/mapbox-gl-style-spec/#layer-filter">`filter`</a>
 property in the style JSON.
 
 The following comparison operators are supported.
 
 <ul>
 <li><code>NSEqualToPredicateOperatorType</code> (<code>=</code>, <code>==</code>)</li>
 <li><code>NSGreaterThanOrEqualToPredicateOperatorType</code> (<code>>=</code>, <code>=></code>)</li>
 <li><code>NSLessThanOrEqualToPredicateOperatorType</code> (<code><=</code>, <code>=<</code>)</li>
 <li><code>NSGreaterThanPredicateOperatorType</code> (<code>></code>)</li>
 <li><code>NSLessThanPredicateOperatorType</code> (<code><</code>)</li>
 <li><code>NSNotEqualToPredicateOperatorType</code> (<code>!=</code>, <code><></code>)</li>
 <li><code>NSBetweenPredicateOperatorType</code> (<code>BETWEEN</code>)</li>
 </ul>
 
 The following compound operators are supported:
 
 <ul>
 <li><code>NSAndPredicateType</code> (<code>AND</code>, <code>&&</code>)</li>
 <li><code>NSOrPredicateType</code> (<code>OR</code>, <code>||</code>)</li>
 <li><code>NSNotPredicateType</code> (<code>NOT</code>, <code>!</code>)</li>
 </ul>
 
 The following aggregate operator is supported:
 
 <ul>
 <li><code>NSInPredicateOperatorType</code> (<code>IN</code>)</li>
 </ul>
 
 To test whether a feature has or lacks a specific attribute, compare the attribute to `NULL` or `NIL`. Predicates created using the `+[NSPredicate predicateWithValue:]` method are also supported. String operators and custom operators are not supported.
 
 For details about the predicate format string syntax, consult the “Predicate
 Format String Syntax” chapter of the “Predicate Programming Guide” in Apple
 developer documentation.
 
 The predicate's left-hand expression must be a string that identifies a feature
 attribute or, alternatively, one of the following special attributes:
 
 <table>
 <thead>
 <tr><th>Attribute</th><th>Meaning</th></tr>
 </thead>
 <tbody>
 <tr>
    <td><code>$id</code></td>
    <td>
        A value that uniquely identifies the feature in the containing source.
        For details on the types of values that may be associated with this key,
        consult the documentation for the <code>MGLFeature</code> protocol’s
        <code>identifier</code> property.
    </td>
 </tr>
 <tr>
    <td><code>$type</code></td>
    <td>
        The type of geometry represented by the feature. A feature’s type is
        guaranteed to be one of the following strings:
        <ul>
            <li>
                <code>Point</code> for point features, corresponding to the
                <code>MGLPointAnnotation</code> class
            </li>
            <li>
                <code>LineString</code> for polyline features, corresponding to
                the <code>MGLPolyline</code> class
            </li>
            <li>
                <code>Polygon</code> for polygon features, corresponding to the
                <code>MGLPolygon</code> class
            </li>
        </ul>
    </td>
 </tr>
 <tr>
    <td><code>point_count</code></td>
    <td>The number of point features in a given cluster.</td>
 </tr>
 </tbody>
 </table>
 
 The predicate’s right-hand expression must be an `NSString` (to match strings)
 or `NSNumber` (to match numbers, including Boolean values) or an array of
 `NSString`s or `NSNumber`s, depending on the operator and the type of values
 expected for the attribute being tested. For floating-point values, use
 `-[NSNumber numberWithDouble:]` instead of `-[NSNumber numberWithFloat:]`
 to avoid precision issues.
 
 Automatic type casting is not performed. Therefore, a feature only matches this
 predicate if its value for the attribute in question is of the same type as the
 value specified in the predicate.
 */
@property (nonatomic, nullable) NSPredicate *predicate;

@end

NS_ASSUME_NONNULL_END
