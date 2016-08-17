#ifndef MARK_COMPILER_GENERATED_H
#define MARK_COMPILER_GENERATED_H

// DQ (5/22/2005):
/*! \brief Mark an AST subtree as compiler generated (used for instatiated templates generated by ROSE as specializations).

    Template instatiation is handled by ROSE and EDG though the translation of instatiations to be template 
    specializations. When output as specializations they are generated code (not appearing in the original 
    source code).  Since EDG recordes the position of the instatiated template as the location of the original 
    template declaration (which could be in a different file) the unparser can skip over the output of such 
    parts of the AST (since we only output the code associated with the original source file as a way of 
    stripping off all the headers files that would otherwise be prepended to the source code).

    \internal Note that it sould not be sufficient to mark the generated template specializations as transformations 
    since then all template specializations wuld be output (only user transformed template specializations should 
    be output).
 */
void markAsCompilerGenerated( SgNode* node );

/*! \brief Mark an AST subtree as compiler generated (used for instatiated templates generated by ROSE as specializations).

    Template instatiation is handled by ROSE and EDG though the translation of instatiations to be template 
    specializations. When output as specializations they are generated code (not appearing in the original 
    source code).  Since EDG recordes the position of the instatiated template as the location of the original 
    template declaration (which could be in a different file) the unparser can skip over the output of such 
    parts of the AST (since we only output the code associated with the original source file as a way of 
    stripping off all the headers files that would otherwise be prepended to the source code).

    \internal Note that it sould not be sufficient to mark the generated template specializations as transformations 
    since then all template specializations wuld be output (only user transformed template specializations should 
    be output).
 */
class MarkAsCompilerGenerated : public SgSimpleProcessing
   {
     public:
      //! Required traversal function
          void visit (SgNode* node);

      //! static function used in both AST fixup and in AST consistancy tests
          static bool templateDeclarationCanBeMarkedAsCompilerGenerated(SgTemplateDeclaration* templateDeclaration);
   };

// endif for MARK_COMPILER_GENERATED_H
#endif
