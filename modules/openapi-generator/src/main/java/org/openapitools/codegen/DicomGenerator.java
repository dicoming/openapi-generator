package org.openapitools.codegen;

import java.util.ArrayList;
import java.util.List;

/**
 *
 */
public class DicomGenerator extends DefaultGenerator {

    @Override
    public List<CodegenOperation> sortOperations(List<CodegenOperation> ops) {

        List<CodegenOperation> sortedOperations = new ArrayList<>();

        List<CodegenOperation> create = new ArrayList<>();
        List<CodegenOperation> find = new ArrayList<>();
        List<CodegenOperation> get = new ArrayList<>();
        List<CodegenOperation> update = new ArrayList<>();
        List<CodegenOperation> other = new ArrayList<>();
        List<CodegenOperation> delete = new ArrayList<>();

        ops.forEach(operation -> {
            if (operation.operationId.matches("create.*")) {
                create.add(operation);
            } else if (operation.operationId.matches("find.*")) {
                find.add(operation);
            } else if (operation.operationId.matches("get.*")) {
                get.add(operation);
            } else if (operation.operationId.matches("update.*")) {
                update.add(operation);
            } else if (operation.operationId.matches("delete.*")) {
                delete.add(operation);
            } else {
                other.add(operation);
            }
        });

        sortedOperations.addAll(create) ;
        sortedOperations.addAll(find) ;
        sortedOperations.addAll(get) ;
        sortedOperations.addAll(update) ;
        sortedOperations.addAll(other) ;
        sortedOperations.addAll(delete) ;

        return sortedOperations;
    }
}