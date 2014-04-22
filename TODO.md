TODO EtoileFoundation
=====================

- Redesign the mirror API in order to allow the existing classes to be extended per use case (e.g. documentation, runtime reflection, code generation, access control etc.). SourceCodeKit should be able to leverage it unlike now. See:
  + Mirrors: Design Principles for Meta-level Facilities of Object: bracha.org/mirrors.pdf 
  + Proxies: Design Principles for Robust Object-oriented Intercession: soft.vub.ac.be/~tvcutsem/proxies/assets/proxies.pdf
  + Mirages: Behavioral Intercession in a Mirror-based Architecture: soft.vub.ac.be/Publications/2007/vub-prog-tr-07-16.pdf 
  + Newspeak Mixin implementation: newspeaklanguage.org
- Finish the mirror implementation and write a related test suite

- Finish metamodel implementation (validation, role classes etc.) and extend the test suite

- Get rid of glibc_hack_unistd.h if possible

- Support CommonCrypto API for iOS and Mac OS X, in addition to openssl (this can be done with some preprocessor macros easily, see how CoreObject does it)

- Add NSFastEnumeration support to NSPointerArray on GNUstep (see ETEntityDescription)

- Split Collection protocols and categories into multiple files

- Add some useful HOM methods such as -flattenedCollection, -deepFlattenedCollection, -flatMappedCollection etc. and their block equivalent methods.

- Rename ETSourceDidUpdateNotification to ETCollectionDidUpdateNotification


Known Issues
------------

- Figure out why CArray doesn't compile on Mac OS X