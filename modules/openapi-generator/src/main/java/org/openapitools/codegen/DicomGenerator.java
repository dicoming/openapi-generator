package org.openapitools.codegen;

import io.swagger.v3.oas.models.OpenAPI;
import io.swagger.v3.oas.models.Operation;
import io.swagger.v3.oas.models.media.Schema;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

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

        sortedOperations.addAll(create);
        sortedOperations.addAll(find);
        sortedOperations.addAll(get);
        sortedOperations.addAll(update);
        sortedOperations.addAll(other);
        sortedOperations.addAll(delete);

        return sortedOperations;
    }

    @Override
    protected void postProcessCodegenOperation(CodegenOperation codegenOperation, String resourcePath,
                                               String httpMethod, Operation operation, Map<String, Schema> schemas,
                                               OpenAPI openAPI) {
        if (codegenOperation.consumes != null && codegenOperation.consumes.size() > 0) {
            String contentType = codegenOperation.consumes.get(0).get("mediaType");
            for (CodegenParameter headerParam : codegenOperation.headerParams) {
                if (headerParam.paramName.equals("Content-Type")) {
                    headerParam.value = contentType;
                    headerParam.isContentType = true;
                    headerParam.hasValue = true;
                }
            }
        } else {
            LOGGER.warn(operation.getOperationId() + " has not value of consumes to set Content-Type header");
        }

        if (codegenOperation.responses != null && codegenOperation.responses.size() > 0) {
            String code = codegenOperation.responses.get(0).code;
            if (code != null) {
                codegenOperation.successResponseCode = Integer.parseInt(code);
            } else {
                LOGGER.warn(operation.getOperationId() + " has not any response codes");
            }

        }
        if (codegenOperation.operationId.startsWith("create")
                || codegenOperation.operationId.startsWith("update")) {
            codegenOperation.isOperationForChange = true;
        }
        if (codegenOperation.operationId.startsWith("create")) {
            codegenOperation.isCreateOperation = true;
        }
        if (codegenOperation.operationId.startsWith("get")
                || codegenOperation.operationId.startsWith("update")
                || codegenOperation.operationId.startsWith("delete")) {
            codegenOperation.isNeededIdFromCreateOperation = true;
        }

        if (codegenOperation.operationId.startsWith("update")) {
            codegenOperation.isUpdateOperation = true;
        }

    }
}